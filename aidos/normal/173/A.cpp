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

string a, b;
int k;
int n, m;
int dp1[1000100];

int dp2[1000100];
int get(char x,char y){
    if(x == y) return 0;
    if(x == 'R'){
        if( y == 'S') return 1;
        return 0;
    }
    if( x=='S') {
        if( y == 'R' ) return 0;
        return 1;
    }
    if( y == 'S') return 0;
    return 1;
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> k >> a >> b;
    int cnt = 1;
    n = a.size();
    m = b.size();
    int x = 0;
    int y = 0;

    for(int i = 1; ; i++){
        dp1[i] = get(a[x], b[y]) + dp1[i-1];
        dp2[i] = get(b[y], a[x]) + dp2[i-1];


        x = (x + 1) % n;
        y = ( y + 1) % m;
        if( x == 0 && y == 0) break;
        cnt++;
    }
    x = k/cnt;
    ll d1 = dp1[cnt] * 1ll * x + dp1[k % cnt];

    ll d2 = dp2[cnt] * 1ll * x + dp2[k % cnt];
    cout << d2 << " " << d1 << endl; 


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}