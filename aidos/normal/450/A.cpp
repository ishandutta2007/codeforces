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
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int n;
    vector < int > v;
    int a[111], k;
    cin >> n >> k;
    int last = -1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        v.pb(i);
    }
    while(v.size() > 0){
        vector < int > u;
        for(int i = 0; i < v.size(); i++){
            a[v[i]] -= k;
            if( a[v[i]] > 0) u.pb(v[i]);
            else last = v[i];
        }
        v = u;
    }
    cout <<last+1 << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}