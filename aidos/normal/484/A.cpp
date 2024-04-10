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

void solve(){
    ll a, b;
    cin >> a >> b;
    if( a==b){
        cout << a << endl;
        return;
    }
    vector < int > v;
    for(int i = 0; i < 61; i++){
        if( (a & (1ll << i)) == 0){
            v.pb(i);
        }
    }

    ll t = a;
    for(int i = 0; i < v.size(); i++){
        t += (1ll << v[i]);
        if( t <= b){
            a = t;
        }
    }
    cout << a << endl;
}



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int n;
    cin >> n;
    for(int i = 0;i <n; i++){
        solve();
    }


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}