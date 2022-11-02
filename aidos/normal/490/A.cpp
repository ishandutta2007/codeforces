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
const int mod = (int) 1e9 + 7;

using namespace std;

vector < int > v[40];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    int n;
    cin >> n;
    for(int i = 1, x; i <= n; i++){
        cin >> x;
        v[x].pb(i);
    }

    int m = min((int) v[1].size(), min ((int) v[2].size(), (int) v[3].size()));
    cout << m << endl;
    for(int i = 0; i < m; i++){
        for(int j = 1; j <= 3; j++){
            cout << v[j][i] <<" ";
        }
        cout << endl;
    }



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}