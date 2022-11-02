#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pb emplace_back
#define mp make_pair

const int MAXN = (1 << 18);
int ma[2 * MAXN];
int mi[2 * MAXN];
int lt[2 * MAXN];
int rt[2 * MAXN];
int ans[2 * MAXN];
int add[2 * MAXN];
int n, q;
int inf = 1000 * 1000 * 1000;

void push(int i)
{
    add[i * 2] += add[i];
    add[i * 2 + 1] += add[i];
    ma[i] += add[i];
    mi[i] += add[i];
    lt[i] -= add[i];
    rt[i] -= add[i];
    add[i] = 0;
}

void update(int i, int l, int r, int left, int right, int x)
{
    if (l == left && r == right)
    {
        add[i] += x;
        return;
    }
    push(i);
    int m = (l + r) / 2;
    if (right <= m)
        update(i * 2, l, m, left, right, x);
    else if (left >= m)
        update(i * 2 + 1, m, r, left, right, x);
    else
    {
        update(i * 2, l, m, left, m, x);
        update(i * 2 + 1, m, r, m, right, x);
    }
    ma[i] = max(ma[i * 2] + add[i * 2], ma[i * 2 + 1] + add[i * 2 + 1]);
    mi[i] = min(mi[i * 2] + add[i * 2], mi[i * 2 + 1] + add[i * 2 + 1]);
    lt[i] = max(max(lt[i * 2] - add[i * 2], lt[i * 2 + 1] - add[i * 2 + 1]), ma[i * 2 + 1] + add[i * 2 + 1] - 2 * (mi[i * 2] + add[i * 2]));
    rt[i] = max(max(rt[i * 2] - add[i * 2], rt[i * 2 + 1] - add[i * 2 + 1]), ma[i * 2] + add[i * 2] - 2 * (mi[i * 2 + 1] + add[i * 2 + 1]));
    ans[i] = max(rt[i * 2] - add[i * 2] + ma[i * 2 + 1] + add[i * 2 + 1], ma[i * 2] + add[i * 2] + lt[i * 2 + 1] - add[i * 2 + 1]);
    ans[i] = max(ans[i], max(ans[i * 2], ans[i * 2 + 1]));
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> n >> q >> s;
    n = s.size() + 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == '(')
            ma[i + MAXN] = ma[i - 1 + MAXN] + 1;
        else
            ma[i + MAXN] = ma[i - 1 + MAXN] - 1;
    }
    for (int i = MAXN + n; i < 2 * MAXN; i++)
    {
        ma[i] = -inf;
        mi[i] = inf;
        lt[i] = -inf;
        rt[i] = -inf;
        ans[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        mi[i + MAXN] = ma[i + MAXN];
        lt[i + MAXN] = -ma[i + MAXN];
        rt[i + MAXN] = -ma[i + MAXN];
        ans[i] = 0;
    }
    for (int i = MAXN - 1; i >= 1; i--)
    {
        ma[i] = max(ma[i * 2], ma[i * 2 + 1]);
        mi[i] = min(mi[i * 2], mi[i * 2 + 1]);
        lt[i] = max(max(lt[i * 2], lt[i * 2 + 1]), ma[i * 2 + 1] - 2 * mi[i * 2]);
        rt[i] = max(max(rt[i * 2], rt[i * 2 + 1]), ma[i * 2] - 2 * mi[i * 2 + 1]);
        ans[i] = max(rt[i * 2] + ma[i * 2 + 1], ma[i * 2] + lt[i * 2 + 1]);
        ans[i] = max(ans[i], max(ans[i * 2], ans[i * 2 + 1]));
    }
    cout << ans[1] << "\n";

    for (int j = 0; j < q; j++)
    {
        int l, r;
        cin >> l >> r;
        l--; r--;
        if (l > r)
        {
            int c = r;
            r = l;
            l = c;
        }
        if (s[l] == '(' && s[r] == ')')
        {
            update(1, 0, MAXN, l + 1, r + 1, -2);
            s[l] = ')';
            s[r] = '(';
        }
        else if (s[l] == ')' && s[r] == '(')
        {
            update(1, 0, MAXN, l + 1, r + 1, 2);
            s[l] = '(';
            s[r] = ')';
        }
        cout << ans[1] << "\n";
    }
}