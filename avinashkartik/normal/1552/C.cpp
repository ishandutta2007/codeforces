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

const ll   N     =  5e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int n, k, x[N], y[N];

void solve() {
	cin >> n >> k;
	vector <int> vis(2 * n + 1, 0); 
	for (int i = 1; i <= k; i++) {
		cin >> x[i] >> y[i];
		if (x[i] > y[i]) swap(x[i], y[i]);
		vis[x[i]] = 1, vis[y[i]] = 1;
	}
	vector <int> left;
	for (int i = 1; i <= 2 * n; i++) {
		if (!vis[i]) left.pb(i);
	}
	for (int i = k + 1; i <= n; i++) {
		x[i] = left[i - (k + 1)];
		y[i] = left[i - (k + 1) + left.size() / 2];
	}

	auto intersect = [&](int i, int j) -> bool {
		return (x[i] < x[j] && x[j] < y[i] && y[i] < y[j]);
	};

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += intersect(i, j);
		}
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