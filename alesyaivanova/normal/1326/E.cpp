#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = (1 << 19);
int mi[2 * maxn];
int d[2 * maxn];
int cnt[2 * maxn];
int p[maxn];
int pos[maxn];
int q[maxn];
int n;
int inf = 1e9;

void push(int i)
{
    d[i * 2] += d[i];
    mi[i * 2] += d[i];
    d[i * 2 + 1] += d[i];
    mi[i * 2 + 1] += d[i];
    d[i] = 0;
}

void update(int i)
{
    mi[i] = inf;
    if (cnt[i * 2])
        mi[i] = mi[i * 2];
    if (cnt[i * 2 + 1])
        mi[i] = min(mi[i], mi[i * 2 + 1]);
}

void add(int i, int l, int r, int left, int right, int x)
{
    if (right <= l || left >= r)
        return;
    if (left <= l && r <= right)
    {
        mi[i] += x;
        d[i] += x;
        return;
    }
    push(i);
    add(i * 2, l, (l + r) / 2, left, right, x);
    add(i * 2 + 1, (l + r) / 2, r, left, right, x);
    update(i);
}

void turn_on(int i, int l, int r, int x)
{
    if (l == r - 1)
    {
        cnt[i] = 1;
        return;
    }
    push(i);
    if (x < (l + r) / 2)
        turn_on(i * 2, l, (l + r) / 2, x);
    else
        turn_on(i * 2 + 1, (l + r) / 2, r, x);
    cnt[i] = cnt[i * 2] + cnt[i * 2 + 1];
    update(i);
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
        pos[p[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
        q[i]--;
    }
    int pt = n - 1;
    for (int i = 0; i < n; i++)
    {
        while (pt >= 0 && mi[1] >= 0)
        {
            add(1, 0, maxn, 0, pos[pt] + 1, -1);
            turn_on(1, 0, maxn, pos[pt]);
            pt--;
        }
        cout << pt + 2 << " ";
        add(1, 0, maxn, 0, q[i] + 1, 1);
    }
}