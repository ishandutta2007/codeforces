#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <map>

using namespace std;

const int MAXN = 100;

long long a[MAXN];
int s[MAXN];
long long f[MAXN][3];
int upd[MAXN][3], cnt;
int n;
long long m;


long long rec(int n, int m)
{
    if (n == 0) return m == 0;

    if (upd[n][m] == cnt) return f[n][m];
    upd[n][m] = cnt;

    long long &res = f[n][m];
    res = 0;

    if (m + s[n] > 2) return res;

    if (m + s[n] == 0)
    {
        res = rec(n - 1, 0);
    }
    else
    {
        res += rec(n - 1, m + s[n] - (int)(m == 0 || s[n] == 0));
        if (m + s[n] < 2) res += rec(n - 1, 2);
    }
    return res;
}


map <int, int> M;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    a[1] = 1;
    a[2] = 2;
    for (n = 2; a[n] <= (long long)1e+18; )
    {
        n++;
        a[n] = a[n - 1] + a[n - 2];
    }
    n--;

/*
    for (int i = 0; i < (1 << 22); i++)
    {
        int s = 0;
        for (int j = 0; j < 22; j++)
            if (i & (1 << j))
                s += a[j + 1];
        M[s]++;
    }

    for (map <int, int> :: iterator iter = M.begin(); iter != M.end(); ++iter )
        printf("%d %d\n", iter->first, iter->second);
//*/        

    int t = 0;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%I64d", &m);
//        printf("%I64d: ", m);

        for (int i = n; i >= 1; i--)
        {
            if (m >= a[i])
            {
                s[i] = 1;
                m -= a[i];
            }
            else
            {
                s[i] = 0;
            }
        }

        cnt++;
        long long answer = rec(n, 0);
        printf("%I64d\n", answer);
    }

    fprintf(stderr, "Time of execution: %.3lf sec.\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}