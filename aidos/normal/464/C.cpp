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
const int mod = (int) 1e9 + 7;

#define MAXN (int) (1e5) + 10
using namespace std;

string t[MAXN];
int n;
ll val[] = {0, 1, 2, 3, 4, 5, 6, 7,8,9};
ll len[]={10, 10, 10, 10, 10, 10, 10, 10, 10, 10};  

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
             
    cin >> t[0];
    t[0] = "0->" + t[0];
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> t[i];
    }


    for(int i = n; i >= 0; i--){
        int v = t[i][0] - '0';
        ll valv = 0;
        ll dl = 1;
        for(int j = t[i].size()-1; j>=3; j--){
            int x = t[i][j] - '0';
            valv = (val[x] * 1ll * dl % mod + valv) % mod;
            dl = (len[x] * 1ll * dl) % mod;
        }
        val[v] = valv;
        len[v] = dl;
    }
    cout << val[0] << endl;

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}