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

int n, x, y;

int a[111];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> x >> y;

    if( y == 0 && x == n - 1 && x != 0){
        cout << -1;
        return 0;
    }
    if(y == 0){
        a[1] = 1;
        a[0] = 1;
        y++;
    }
    else {
    int sum = 1;
    a[0] = 1;
    for(int i = 1; i <= y; i++){
        a[i] = sum + 1;
        sum += a[i];
    }
    }
    for(int i=y + 1; i <= y + x; i++){
        a[i] = a[i-1] + 1;
    }
    
    for(int i = y + x + 1; i < n; i++) a[i] = a[i-1];

    for(int i = 0; i < n; i++) cout << a[i] << " ";

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}