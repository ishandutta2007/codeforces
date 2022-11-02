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
bool used[100100];
vector < pii > ans;
int n;
int main () {
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    cin >> n;
    for(int i = 3; i*2 <= n; i++){
        if(used[i]) continue;
        if( i%2 == 0) continue;
        vector < int > cur;
        for(int j = i; j <= n; j+=i){
            if( j % 2 == 0 || used[j]) continue;
            cur.pb(j);
        }
        if(cur.size() & 1){
            cur.pb( i + i );
        }
        for(int j = 0; j < cur.size(); j+=2){
            ans.pb(mp(cur[j], cur[j+1]));
            used[cur[j]] = 1;
            used[cur[j+1]] = 1;
        }
    }
    int l = -1;
    for(int i = 2; i <=n; i+=2){
        if(used[i]) continue;
        if( l != -1) {
            ans.pb(mp(i,l));
            l = -1;
        }
        else l = i;
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i].f << " " << ans[i].s << endl;
    }
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}