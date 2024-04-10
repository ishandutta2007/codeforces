#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

int dp[(1<<20) + 30];
int d[(1<<20) + 30];
int n, m;
string a[22];
int b[22][22];
vector < pii > masks[22];


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> b[i][j];
    }
    for(int i  =0; i < ( 1 << n); i++)
        dp[i] = 1000000000;
    dp[(1<<n) - 1] = 0;
    for(int i= 0; i < m; i++){
        vector < int > v;
        for(char t = 'a'; t <= 'z'; t++){
            int sum = 0;
            int mask = 0;
            v.clear();
            for(int j = 0; j < n; j++){
                if(a[j][i] == t) {
                    mask |= (1<<j);
                    v.pb(-b[j][i]);
                    sum += b[j][i];
                }
            }
            if( mask == 0 ) continue;
            sort(v.begin(), v.end());
            sum += v[0];
            masks[i].pb(mp(mask, sum));
        }
    }

    for(int i = 0; i < m; i++){
        
        for(int j =(1<<n)-1; j>=0; j--){
            for(int k  =0; k < masks[i].size(); k++){       
                int mask = ((j | masks[i][k].f) ^ masks[i][k].f);
                dp[mask] = min(dp[mask], dp[j] + masks[i][k].s);
            }
        }
        for(int j = ( 1<<n) - 1; j >= 0; j--){
            for(int k = 0; k < n; k++){
                int mask = ((j | (1<<k)) ^ (1<<k));
                dp[mask] = min(dp[mask], dp[j] + b[k][i]);
            }
        }
        
    }

    cout << dp[0] << endl;




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}