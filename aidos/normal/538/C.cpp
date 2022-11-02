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


int n, m;
int ans;
int a[100100];
int b[100100];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
    	scanf("%d %d", &a[i], &b[i]);
    }
    ans = max(b[0] + a[0] - 1, n - a[m-1] + b[m-1]);
    for(int i =1; i < m; i++){
    	if(a[i] - a[i-1] < abs(b[i] - b[i-1])){
    		cout << "IMPOSSIBLE\n";
    		return 0;
    	}
    	int x = a[i] - a[i-1];
    	int len = abs(b[i] - b[i-1]);
    	x -= len;
    	ans = max(ans, max(b[i], b[i-1]) + x/2);
    }
    cout << ans << endl;

    





    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}