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

const int inf = (int) 1e9;

#define MAXN (int) (1e7)
using namespace std;

int a, b, c;
int sum(ll x){
    int r = 0;
    while( x > 0){
        r += x % 10;
        x/=10;
    }
    return r;
}
int check(ll x, int sumt){
    if( x <= 0) return 0;
    if( x >= inf) return 0;
    return sum(x) == sumt;
}
ll Pow(int x, int a){
    ll d = 1;
    for(int i = 0; i < a; i++){
        d  = d * 1ll * x;
    }
    return d;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> a >> b >> c;
    vector < ll > v ;
    for(int i = 1; i <= 100; i++){
        ll x = b * 1ll * Pow(i, a) + c;
        if( check(x, i)){
            v.pb(x);
        }
    }
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}