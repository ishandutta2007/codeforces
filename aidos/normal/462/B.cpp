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

#define MAXN (int) (1e7)
using namespace std;


int n, k;
int c[27];
string t;
vector < pii > g;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> k >> t;
    for(int i = 0; i < n; i++){
        c[t[i] - 'A']++;
    }
    for(int i = 0; i < n; i++){
        g.pb( mp(c[t[i]-'A'], t[i]-'A'));
    }
    sort(g.begin(), g.end());
    reverse(g.begin(), g.end());
    ll ans = 0;
    for(int i = 0; i < k; ){
        int j = i;
        while( i < k && g[i] == g[j] ) i++;
        ans += (i - j) * 1ll * (i - j);
    }
    cout << ans << endl;
    

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}