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

#define maxn (int) (1e5) + 10
using namespace std;

int n, x;
ll a[maxn];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> x;
    for(int i = 0;  i< n; i++) cin >> a[i];
    x--;
    int pos = -1;

    for(int i = x+1; i < n; i++){
        if( pos == -1 || a[i] <= a[pos]) pos = i;
    }
    for(int i = 0; i <=x; i++){
        if( pos == -1 || a[i] <= a[pos]) pos = i;
    }
    //cout << pos <<  " " << a[pos] << endl;
    
    //cout << pos << endl;
    int y = x;
    int cnt = 0;
    while( 1 ){
      //  cout << y << endl;
        if( y == pos ) break;
        a[y]--;
        cnt++;
        y--;
        y += n;
        y %= n;
    }

    ll z = a[pos];
    for(int i = 0; i < n; i++){
        a[i] -= z;
    }
    a[pos] += z * 1ll * n + cnt;

    for(int i = 0; i < n; i++) cout << a[i] << " ";

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}