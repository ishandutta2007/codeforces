#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define err(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;

const int N = 3.1e5;

pair<int, int> c[N];

void out(int x1, int c1, int x2, int c2)
{
    err("%d %d %d %d\n", x1, c1, x2, c2);
    printf("Yes\n");
    printf("%d %d\n", c1, c2);
    forn(i, c1) printf("%d%c", c[x1 + i].second, " \n"[i + 1 == c1]);
    forn(i, c2) printf("%d%c", c[x2 + i].second, " \n"[i + 1 == c2]);
    exit(0);
}

int main() {
#ifdef amit_swami
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int n, x1, x2;
    scanf("%d%d%d", &n, &x1, &x2);
    forn(i, n) scanf("%d", &c[i].first);
    forn(i, n) c[i].second = i + 1;
    sort(c, c + n);
    
    {

        int mn = 1e9;
        for (int i = 1; i <= n; ++i)
        {
            int val = (x1 + i - 1) / i;
            if (c[n - i].first >= val)
            {
                mn = i;
                break;
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            int val = (x2 + i - 1) / i;
            int pos = lower_bound(c, c + n, pair<int, int>{val, -1}) - c;
            if (pos + i + mn <= n)
            {
                out(n - mn, mn, pos, i);
            }
        }
    }

    {

        int mn = 1e9;
        for (int i = 1; i <= n; ++i)
        {
            int val = (x2 + i - 1) / i;
            if (c[n - i].first >= val)
            {
                mn = i;
                break;
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            int val = (x1 + i - 1) / i;
            int pos = lower_bound(c, c + n, pair<int, int>{val, -1}) - c;
            if (pos + i + mn <= n)
            {
                out(pos, i, n - mn, mn);
            }
        }
    }    

    printf("No\n");
            

    


    return 0;
}