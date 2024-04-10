

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e3 + 7;
int lt[N][8][N];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int n;
    scanf("%d", &n);
    vector <int> c(n);
    set <int> s;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &c[i]);
        c[i]--;
        s.insert(c[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int t = 0; t < 8; t++)
        {
            int cnt = 0;
            for (int j = i; j < n; j++)
            {
                if (c[j] == t)
                {
                    cnt++;
                    lt[i][t][cnt] = j + 1;
                }
            }
            for (int te = cnt + 1; te < N; te++)
            {
                lt[i][t][te] = -1;
            }
        }
    }
    int lim = (1 << 8);
    ans = max(ans, (int) s.size());
    vector <int> t;
    for (int i = 0; i < 8; i++)
    {
        t.push_back(i);
    }
    do
    {
        int l = 1, r = n;
        while (l < r - 1)
        {
            int m = (l + r) / 2;
            int cur = 0;
            bool good = 1;
            for (auto c: t)
            {
                if (lt[cur][c][m] == -1 || cur == n)
                {
                    good = 0;
                    break;
                }
                else
                {
                    cur = lt[cur][c][m];
                }
            }
            if (good)
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        int res = l;
        for (int mask = 0; mask < lim; mask++)
        {
            int go = 0;
            bool gg = 1;
            int cnt = 0;
            for (int i = 0; i < (int) t.size(); i++)
            {
                int c = t[i];
                int b = (mask >> i) & 1;
                cnt += (b == 1) + res;
                if (lt[go][c][res + b] == -1 || go == n)
                {
                    gg = 0;
                    break;
                }
                else
                {
                    go = lt[go][c][res + b];
                }
            }
            if (gg)
            {
                ans = max(ans, cnt);
            }
        }
    } 
    while (next_permutation(t.begin(), t.end()));
    printf("%d\n", ans);
}