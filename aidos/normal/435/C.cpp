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
#include <cassert>

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

const int inf = (1ll << 25) - 1;
const int maxn = (int)1e4+100;
const int mod = (int) 1e9 + 7;
using namespace std;
int a[maxn];
vector<int> g[maxn];
int n;
int b[maxn];
void solve(){
	cin >> n;
	int s = 0;
	int y = 0;
	int my = 0;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		int dir = 1;
		if(i&1) dir = -1;
		for(int j = 0; j < x; j++) {
			a[s] = dir;
			s += 1;
		}
	}
	int mid = 5050;
	int cur = mid;
	int ans1 = mid;
	int ans2 = maxn;
	for(int i = 0; i < s; i++) {
		if(a[i] < 0) {
			ans1 = max(ans1, cur);
			ans2 = min(ans2, cur);
			g[cur].pb(i);
		}
		cur += a[i];
		if(a[i] > 0) {
			ans1 = max(ans1, cur);
			ans2 = min(ans2, cur);
			g[cur].pb(i);
		}

	}
	for(int i = ans1; i >= ans2; i--) {
		int ss = 0;
		for(int j = 0; j < s; j++){
			b[j] = 0;
		}
		for(int j = 0; j < g[i].size();j++) {
			b[g[i][j]] = a[g[i][j]];
		}
		for(int j = 0; j < s; j++) {
			if(b[j] > 0) cout << '/';
			else if(b[j] < 0) cout  << '\\';
			else cout << ' ';
		}
		cout << "\n";
	}


}
int main () {
    int t=1;
   	//scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }
    
    return 0;
}