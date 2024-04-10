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
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    int a[10], x, n, c=  0;
    a[0] = a[1] =0;

    for(int i  = 0; i < 3; i++){
        cin >> x;
        a[0] += x;
    }
    while( a[0] > 0){
        a[0] -= 5;
        c++;
    }
    for(int i  = 0; i < 3; i++){
        cin >> x;
        a[1] += x;
    }
    while( a[1] > 0){
        a[1] -= 10;
        c++;
    }
    cin >> n;
    if( c <= n) cout << "YES\n";
    else cout << "NO\n";
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}