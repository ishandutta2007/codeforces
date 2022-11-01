#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf=2000000000;
const ld eps=1e-07;

int n, m;
int64 a[100], b[100], c[100], k;

int64 dp[100][100][102];
pair <int, int> p[100][100][102];

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    scanf("%d %d", &n, &m);
    cin >> k;
    for (int i = 0; i < m; ++i) 
        cin >> a[i] >> b[i] >> c[i];
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            for (int x = 0; x <= 100; ++x)
                dp[i][j][x] = -1;
    for (int j = 0; j < m; ++j)
        for (int x = 0; x <= 100; ++x)
            dp[0][j][x] = x + a[j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            for (int x = 0; x <= (b[j] - a[j]); ++x)
                if (dp[i][j][x] > 0)
                    for (int z = 0; z < 50; ++z) {
                        if (c[z] <= c[j])
                            continue;
                        int64 t = a[j] + int64(x) + k;
                        if ((t >= a[z]) && (t <= b[z])) {
                            if ((dp[i][j][x] + t) > dp[i + 1][z][t - a[z]]) {
                                dp[i + 1][z][t - a[z]] = dp[i][j][x] + t;
                                p[i + 1][z][t - a[z]] = mp(j, x);
                            }
                        }
                        t = (a[j] + int64(x)) * k;
                        if ((t >= a[z]) && (t <= b[z])) {
                            if ((dp[i][j][x] + t) > dp[i + 1][z][t - a[z]]) {
                                dp[i + 1][z][t - a[z]] = dp[i][j][x] + t;
                                p[i + 1][z][t - a[z]] = mp(j, x);
                            }
                        }
                    }
    int64 ans = -1;
    for (int j = 0; j < m; ++j)
        for (int x = 0; x <= (b[j] - a[j]); ++x)
            ans = max(ans, dp[n - 1][j][x]);
    if (ans == -1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int j = 0; j < m; ++j)
        for (int x = 0; x <= (b[j] - a[j]); ++x)
            if (dp[n - 1][j][x] == ans) {
                pair <int, int> t, t2;
                t.first = j;
                t.second = x;
                int l = n - 1;
                vector <pair<int, int>> ans;
                while (l) {
                    ans.pb(t);
                    t2.first = p[l][t.first][t.second].first;
                    t2.second = p[l][t.first][t.second].second;
                    --l;
                    t = t2;
                }
                ans.pb(t);
                reverse(ans.begin(), ans.end());
                for (int i = 0; i < n; ++i)
                    cout << ans[i].first + 1 << " " << a[ans[i].first] + ans[i].second << endl;
                return 0;
            }
    return 0;
}