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
vector < ll > divi;
int maxi = (int)(1e5);

vector < int > has[100000];
void calc(ll k, int ind){
    if( k == 0 || ind == 0){
        if( maxi == 0) exit(0);
        maxi--;
        cout << divi[ind] << " ";
    }
    else {
        for(int x = 0; x < has[ind].size(); x++){
            calc(k-1, has[ind][x]);
        }
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    ll x, k;
    cin >> x >> k;
    for(int i = 1; i*1ll * i <=x; i++){
        if( x % i == 0){
            divi.pb(i);
            if( x != i * 1ll * i) divi.pb(x/i);
        }
    }
    sort(divi.begin(), divi.end());
    for(int i = 0; i<divi.size(); i++){
        for(int j = 0; j<=i; j++){
            if( divi[i] % divi[j] == 0){
                has[i].pb(j);
            }
        }
    }
    calc(k, divi.size()-1);
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}