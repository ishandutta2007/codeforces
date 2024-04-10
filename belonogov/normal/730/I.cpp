/**
 *    author:  SPb ITMO University 1
 *    created: 27.10.2016 12:12:47       
**/
#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

using namespace std;

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = 1.01e9;
const dbl eps = 1e-9;

/* --- main part --- */

const int INF = (int)(1e9);


int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif

    int n, p, s;
    while (cin >> n >> p >> s) {
        vector<pair<pair<int, int>, int> > a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first.first;
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i].first.second;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());

        int sum = 0;
        for (int i = 0; i < p; i++) sum += a[i].first.first;

        vector<vector<int> > dp(n + 1, vector<int>(s + 1, -INF));
        vector<vector<int> > pr(n + 1, vector<int>(s + 1, -1));
        dp[0][0] = sum;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= s; j++) {
                if (dp[i][j] == -INF) continue;
                if (dp[i + 1][j] < dp[i][j]) {
                    dp[i + 1][j] = dp[i][j];
                    pr[i + 1][j] = j;
                }
                if (j == s) continue;
                int ndp = dp[i][j];
                if (i >= p + j) ndp += a[i].first.second;
                else ndp += a[i].first.second - a[i].first.first + a[p + j].first.first;

                if (dp[i + 1][j + 1] < ndp) {
                    dp[i + 1][j + 1] = ndp;
                    pr[i + 1][j + 1] = j;
                }
            }
        }

        vector<int> t2;
        int ci = n, cj = s;
        while (ci) {
            if (pr[ci][cj] != cj) t2.push_back(a[ci - 1].second);
            cj = pr[ci][cj];
            ci--;
        }

        vector<char> used(n);
        reverse(t2.begin(), t2.end());
        for (int i = 0; i < (int)t2.size(); i++) used[t2[i]] = 1;

        vector<int> t1;
        for (int i = 0; i < n; i++) {
            if ((int)t1.size() < p && !used[a[i].second]) {
                t1.push_back(a[i].second);
                used[a[i].second] = 1;
            }
        }

        assert((int)t1.size() == p);
        assert((int)t2.size() == s);

        printf("%d\n", dp[n][s]);
        for (int i = 0; i < p; i++) printf("%d%c", t1[i] + 1, " \n"[i + 1 == p]);
        for (int i = 0; i < s; i++) printf("%d%c", t2[i] + 1, " \n"[i + 1 == s]);
    }
    
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}