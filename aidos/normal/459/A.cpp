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

int main () {
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    set < pii > S;
    if( x1 != x2 && y1 != y2){
    S.insert( mp( x1, y1) );
    S.insert( mp( x2, y2));
    S.insert( mp( x2, y1));
    S.insert( mp ( x1, y2));
    }
    else if( x1 == x2){
        S.insert( mp( x1, y1) );
        S.insert( mp( x2, y2));
        S.insert( mp( x1 + abs(y2 - y1), y1));
        S.insert( mp ( x1+abs(y2-y1), y2));    
    }
    else if( y1 == y2){
        S.insert( mp( x1, y1) );
        S.insert( mp( x2, y2));
        S.insert( mp( x2, y1+ abs(x2 - x1)));
        S.insert( mp ( x1, y2+ abs(x2 - x1)));    
    }
    else {
        cout << -1;
        return 0;
    }
    
    set < pii > :: iterator ix = S.begin(), it1 = ix, it2 = ix;

    it1++;
    it2++;
    it2++;
    if( it1->s-ix ->s != it2->f - ix ->f){
        cout << -1;
        return 0;
    }

    forit(S){
        if( *it == mp(x1, y1) || *it == mp(x2, y2)) continue;
        cout << it-> f << " " << it->s <<  " ";
    }
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}