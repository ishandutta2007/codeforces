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
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    int n = 2;
    int m = 1000;

    vector < pair < pii, pii > > ans;

    for (int i=1;i<=m;i++){
        ans.pb(mp(mp(i, 1), mp(i, 2)));
    }
    for (int i=m;i>=1;i--){
        ans.pb(mp(mp(i, 1), mp(i, 2)));
    }
    

    cout <<ans.size()<<endl;
    for (int i=0;i<ans.size();i++){
        cout <<ans[i].f.f<<" "<<ans[i].f.s<<" "<<ans[i].s.f<<" "<<ans[i].s.s<<endl;
    }
    
    
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}