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

int get(int x, int y, int t){
    if( t ){
        if( y >=22) return !get(x, y-22, 0);
        if(y >= 12 && x > 0) return !get(x-1, y-12, 0);
        if( y >=2 && x>1) return !get(x-2,y-2,0);
        return 0;
    }
    if( x >= 2 && y >= 2 ) return !get(x-2, y-2, 1);
    if( x > 0 && y > 11) return !get(x-1, y-12, 1);
    if( y > 21) return !get(x, y-22, 1);
    return 0;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int x, y;
    cin >> x >> y;
    if( get(x, y, 0) ) cout << "Ciel\n";
    else cout <<"Hanako\n";

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}