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
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define Vint vector < int >
#define Vll vector < ll >
#define Vb vector < bool >
#define Vpii vector < pii >
#define Vpll vector < pll >

const int inf = (1ll << 31) - 1;

#define MAXN (int) (6e5)
using namespace std;
vector < int > v[MAXN];
string c;
int hash(int k, int l){
    int ans = 0;
    while( l > 0 ){
        ans = (c[k] - 'a' + 1) + ans * 27;
        k++;
        l--;
    }
    return ans;
}
map < pii, int > m;
int main () {
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    cin >> c;
    for(int i = 1; i < 5; i++){
        for(int j = 0; j+i <= c.size(); j++){
            v[hash(j, i)].pb(j);
        }
    }
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> c;
        int a=hash(0, c.size());
        int sz1 = c.size();
        cin >> c;
        int b = hash(0, c.size());
        int sz2 = c.size();
        if( v[a].size() == 0 || v[b].size() == 0) {
            cout << -1 << endl;
            continue;
        }
        if( v[a].size() > v[b].size()) {
            swap(a, b);
            swap(sz1, sz2);
        }
        if( m[mp(a, b)] ){
            cout << m[mp(a, b)] << endl;
            continue;
        }
        int ans = inf;
        for(int i = 0; i < v[a].size(); i++){
            int val = v[a][i];
            int l = 0, r = v[b].size()-1;
            while( l <= r ){
                int mid = (l + r ) >> 1;
                if( v[b][mid] < val ){
                     l=mid+1;
                     ans = min(ans, val + sz1 - v[b][mid]);
                }
                else {
                    r = mid-1;
                }
            }
            l = 0, r = v[b].size()-1;
            while( l <= r ){
                int mid = (l + r ) >> 1;
                if( v[b][mid] >= val ){
                     r=mid-1;
                     ans = min(ans, sz2 + v[b][mid] - val);
                }
                else {
                    l = mid+1;
                }
            }
        }
        ans = max(ans, max(sz1, sz2));
        m[mp(a, b)] = ans;
        cout << ans << endl;
    }
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}