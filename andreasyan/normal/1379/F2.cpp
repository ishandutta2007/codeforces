#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 400005;

int n, m, qq;

set<int> s[N];

int l[N * 4], r[N * 4];
bool ans[N * 4];

void bil(int tl, int tr, int pos)
{
    l[pos] = 0;
    r[pos] = m + 1;
    ans[pos] = true;
    if (tl == tr)
        return;
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
}

void ubd(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        if (s[x * 2].empty())
            l[pos] = 0;
        else
            l[pos] = *(--s[x * 2].end());
        if (s[x * 2 - 1].empty())
            r[pos] = m + 1;
        else
            r[pos] = *(s[x * 2 - 1].begin());
        if (l[pos] < r[pos])
            ans[pos] = true;
        else
            ans[pos] = false;
        return;
    }

    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, pos * 2);
    else
        ubd(m + 1, tr, x, pos * 2 + 1);

    if (l[pos * 2 + 1] < r[pos * 2])
        ans[pos] = true;
    else
        ans[pos] = false;
    if (!ans[pos * 2] || !ans[pos * 2 + 1])
        ans[pos] = false;
    l[pos] = max(l[pos * 2], l[pos * 2 + 1]);
    r[pos] = min(r[pos * 2], r[pos * 2 + 1]);
}

void solv()
{
    scanf("%d%d%d", &n, &m, &qq);
    bil(1, n, 1);
    while (qq--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (s[x].find((y + 1) / 2) == s[x].end())
            s[x].insert((y + 1) / 2);
        else
            s[x].erase((y + 1) / 2);
        ubd(1, n, (x + 1) / 2, 1);
        if (ans[1])
            printf("YES\n");
        else
            printf("NO\n");
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}