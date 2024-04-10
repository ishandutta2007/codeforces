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

int c[22];
int n;
int l, r;
int x;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> l >> r >> x;
    int ans = 0;
    for(int i = 0; i < n; i++)
        cin >> c[i];
    for(int i = 1; i < ( 1 << n); i++){
        int sum = 0;
        int mn = inf;
        int mx = 0;
        for(int j = 0; j < n; j++){
            if(i & ( 1<< j) ){
                sum += c[j];
                mx = max(mx, c[j]);
                mn = min(mn, c[j]);
            }
        }
        if(mx - mn < x) continue;
        if(sum < l || sum > r) continue;
        ans++;
    }
    cout << ans << endl;



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}