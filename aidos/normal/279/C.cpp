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

#define MAXN (int) (1e5) + 10
using namespace std;

int a[MAXN];
int b[MAXN];
vector < pii > v;

int get(int l, int r){
    if( l > r) return 0;
    int lwb = lower_bound(v.begin(), v.end(), mp(l, 0)) - v.begin();
    if( lwb == v.size()) return 0;
    if( v[lwb].f >= l && v[lwb].s <= r){
        return 1;
    }
    return 0;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 2; i < n; ){
        int j = i;
        while( j<n && a[j] == a[i]) j++;
        if( a[i-1] > a[i] && a[j]> a[i]){
            v.pb( mp(i, j));
        }
        i = j;
        
    }
    for(int i = 0, l, r; i < m; i++){
        cin >> l >> r;
        if( get(l+1, r) ) cout << "No\n";
        else cout << "Yes\n";
    }


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}