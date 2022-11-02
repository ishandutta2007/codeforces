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


int n, m;
string a, b;
vector < int > del;
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> a >> b;
    n = a.size();
    m = b.size();
    for(int i = 1; i <= 1e5; i++){
        if( n % i == 0 && m % i == 0){
            del.pb( i );
        }
    }
    int ans = 0;
    for(int i = 0; i < del.size(); i++){
        int x = del[i];
        int ok = 1;
        for(int j = 0; j < x; j++){
            if( a[j] != b[j] ) ok = 0;
        }
        for(int j = x; j < n; j++){
            if(a[j] != a[j-x]) ok = 0;
        }
        for(int j = x; j < m; j++){
            if(b[j] != b[j-x]) ok = 0;
        }
        ans += ok;
    }
    cout << ans << endl;
    

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}