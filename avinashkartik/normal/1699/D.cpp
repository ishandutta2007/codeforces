#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;

const ll   N     =  3e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, a[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector <vector <int>> d(n + 1, vector <int>(n + 1, 0));
	vector <int> ct(n + 1, 0);
	for (int l = 1; l <= n; l++) {
		ct[a[l]]++;
		int mx = 1;
		for (int r = l + 1; r <= n; r++) {
			ct[a[r]]++;
			mx = max(mx, ct[a[r]]);
			if ((r - l + 1)&1) continue;
			if (mx * 2 <= r - l + 1) d[l][r] = 1;
		}
		for (int r = l + 1; r <= n; r++) {
			ct[a[r]]--;
		}
		ct[a[l]]--;
	}
	
	vector <int> dp(n + 1, -1);
	function <int(int)> mem = [&](int i) {
		if (i >= n) return n + 1 - i;
		if (dp[i] != -1) return dp[i];
		dp[i] = -INFi;
		for (int j = i + 1; j <= n + 1; j += 2) {
			if (j != n + 1 && a[i] != a[j]) continue;
			if (j == i + 1) dp[i] = max(dp[i], mem(j) + 1);
			else if (d[i + 1][j - 1] == 1) dp[i] = max(dp[i], mem(j) + 1);
		}
		return dp[i];	
	};
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i != 1 && d[1][i - 1] == 0) continue;
		ans = max(ans, mem(i));
	}
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}