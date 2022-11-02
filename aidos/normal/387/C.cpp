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



vector < int > vv;
string x;
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    cin >> x;
    for(int i = 0; i < x.size(); i++) vv.pb( x[i] - '0');
    int ans=0;
    while(vv.size() > 0){
        int cnt = 0;
        ans++;
        while( vv.size() > 0 && vv.back() == 0){
            cnt++;
            vv.pop_back();
        }
        if( vv.size() < cnt + 2 ) {
            break;
        }
        int cur = vv.back();
        vv.pop_back();
        if( vv[vv.size() - 1 - cnt]< cur &&vv.size() == cnt + 1) break;
    }
    cout << ans << endl;



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}