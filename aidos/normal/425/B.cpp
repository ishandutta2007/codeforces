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
#include <bitset>
#include <unordered_map>

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

const int inf = 100100;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n, m, k;
int a[111][111];
int ans = -1;
void calc(vector<int> d){
	int s = 0;
	for(int j = 0; j < m; j++) {
		int cur = 0;	
		for(int i = 0; i < d.size(); i++){
			cur += a[i][j] ^ d[i];
		}
		cur = min(cur, n - cur);
		s += cur;
	}
	if(s <= k) {
		if(ans==-1) ans = s;
		else ans = min(ans, s);
	}
}
void solve(){
	cin >> n >> m >> k;
	for(int i = 0 ;i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	if(n <= k) {
		for(int i = 0; i < (1<<n); i++) {
			vector<int> d;
			for(int j = 0; j < n; j++) {
				if(i&(1<<j)) d.pb(1);
				else d.pb(0);
			}
			calc(d);
		}
	}else {
		for(int j = 0; j < m; j++) {
			vector<int> d;
			for(int i = 0; i < n; i++) d.pb(a[i][j]);
			calc(d);
		}
	}
	cout << ans << "\n";
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