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

bool ok(int x1, int y1, int x2, int y2){
    if(x1 <= x2 && y1 <= y2) return 1;
                                                              
    if(x2 <= x1 && y2 <= y1) return 0;

    for(int i = x1; i >= 0; i--){
        int move = x1 - i;
        int z = x2 - move;
        int z2 = y2 - move;
        if(z < 0) z = 0;
        if( i <= z && y1 <= z2) return 1;
    }

    return 0;
}



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int x1, x2, y1, y2;

    cin >> x1 >> y1 >> x2 >> y2;
    if(ok(x1, y1, x2, y2) || ok(y1, x1, y2, x2)){
        cout << "Polycarp\n";
    }
    else cout << "Vasiliy\n";





    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}