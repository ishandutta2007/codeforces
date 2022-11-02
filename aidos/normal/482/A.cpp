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

vector < int > v;

int main () {
    
    #ifdef LOCAL
        freopen ("a.in", "r", stdin);
        freopen ("a.out", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    int l = 1;
    int r = k+1;
    while(l < r){
        v.pb(l);
        v.pb( r);
        l++;
        r--;
    }
    if( l == r) v.pb( r );
    int z = n - k - 1;
    for(int i = 1; i <= z; i++) cout << i << " ";
    for(int i = 0; i < v.size(); i++) cout << z + v[i] << " ";




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}