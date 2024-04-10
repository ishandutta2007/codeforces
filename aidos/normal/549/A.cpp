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



    string a[55];
    int n;
    int m;
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin>> a[i];
    }
    int ans = 0;
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            string cur = "";
            cur += a[i][j];
            cur += a[i-1][j]; 
            cur+=a[i][j-1];
            cur += a[i-1][j-1];
            for(int k = 0; k < cur.size(); k++){
                for(int t = k+1; t < cur.size(); t++){
                    if(cur[t] < cur[k]) swap(cur[t], cur[k]);
                }
            }
            if(cur == "acef") ans++;
        }
    }
    cout << ans << endl;



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}