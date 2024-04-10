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
#define sz(a) (int)a.size()
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
#define sz(a) (int)a.size()

const int inf = (1 << 29) - 1;
const int maxn = (int)1e6 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;
int n, m;
int a[maxn];
int ans[maxn];
vector< pii > qu[maxn];
int f[maxn];
int b[maxn];
int pa[maxn];
void updmax(int &v, int x) {
	if(v < x) v = x;
}
void solve(){
	cin >> n >> m;
	for(int i = 1; i < maxn; i++) f[i] = f[i-1] ^ i;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		qu[r].pb(mp(i, l));
	}
	for(int i = 1; i <= n; i++) {
		int cur = 0;
		for(int j = i; j >= 1; j--) {
			if(a[i] >= a[j])updmax(cur, f[a[i]]^f[a[j]-1]);
			else updmax(cur, f[a[i]-1]^f[a[j]]);
			updmax(pa[j], cur);
		}
		for(auto x: qu[i]) {
			ans[x.f] = pa[x.s];
		}
	}
	for(int i = 0; i < m; i++) cout << ans[i] << "\n";

}
int main () {

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d: ", i);
      solve();
    }
    
    return 0;
}