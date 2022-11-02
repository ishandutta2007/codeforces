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
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

int n;
int x;
map < int, int > m;
set < int > S;
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    x = n * n;
    for(int i = 0; i < x; i++){
        int y;
        cin >> y;
        m[y]++;
        S.insert(-y);
    }

    vector < int > ans;
    forit(it, S){
        int y = -(*it);
        while(m[y] > 0) {
        
        for(int j = 0; j < ans.size(); j++){
            m[__gcd(ans[j], y)] -= 2;
        }
        m[y]--;
        ans.pb( y );
        }
    }
    forit(it, ans){
        cout << *it << " ";
    }




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}