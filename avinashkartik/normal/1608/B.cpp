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

const ll   N     =  1e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int n, a, b;

void solve() {
	cin >> n >> a >> b;
	if (abs(a - b) > 1 || a + b + 2 > n) {
		deb1(-1)
	} else {
		vector <int> ans, vis(n + 1, 0), left;
		for (int i = 1; i <= max(a, b); i++) {
			ans.pb(i);
			ans.pb(n - i + 1);
			vis[i] = 1;
			vis[n - i + 1] = 1;
		}
		if (a == b) ans.pb(max(a, b) + 1), vis[max(a, b) + 1] = 1;
		for (auto it : ans) vis[it] = 1;
		for (int i = 1; i <= n; i++) if (!vis[i]) left.pb(i);
		sort(all(left));
		if (a != b) reverse(all(left));
		for (auto it : left) ans.pb(it);
		if (b > a) {
			for (auto &it : ans) it = n - it + 1;
		}
		debv(ans)
	}
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}