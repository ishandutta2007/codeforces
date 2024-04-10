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



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    int n, x;
    cin >> n ;
    x = n/2;
    for(int i =0; i + i < n; i++){
        for(int j = 0; j < x; j++ ) cout <<'*';
        for(int j = 0; j + x + x < n; j++) cout << 'D';
        for(int j = 0; j < x; j++ ) cout <<'*';
        cout << endl;
        x--;
    }
    x = 1;
    for(int i = 1; i + i < n; i++){
        for(int j = 0; j < x; j++ ) cout <<'*';
        for(int j = 0; j + x + x < n; j++) cout << 'D';
        for(int j = 0; j < x; j++ ) cout <<'*';
        cout << endl;
        x++;
    }



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}