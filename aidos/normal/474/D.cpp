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

int t[MAXN];

const int e = (int)1e5 + 1;
int sum[MAXN];



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    for(int i =0;  i < k; i++) t[i] = 1;
    for(int i = k; i <= e; i++){
        t[i] = (t[i-1] + t[i-k]) % mod;
    }
    for(int i = 1; i <=e; i++){
        sum[i] = (sum[i-1] + t[i]) % mod;
    }
    for(int i = 0, l, r; i < n; i++){
        cin >> l >> r;
        int d = sum[r] - sum[l-1];
        if( d < 0 ) d += mod;
        cout << d << endl;
    }

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}