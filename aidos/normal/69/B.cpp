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

struct node{
    int a, b, c;
};
node x[111];
int n, m;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> m;
    for(int i = 1;  i <= n; i++){
        x[i].a = inf;
        x[i].c = 0;
    }
    for(int i = 0;  i< m; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        while(a <= b){
            if(x[a].a > c){
                x[a].a = c;
                x[a].c = d;
            }
            a++;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += x[i].c;
    }
    cout << ans << endl;





    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}