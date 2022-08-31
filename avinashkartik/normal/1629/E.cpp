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

const ll   N     =  1e3 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

ll n, a[N][N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	vector <vector <bool>> vis(n + 1, vector <bool> (n + 1, 0));
	int ans = 0;

	auto mark = [&](int i, int j) {
		ans ^= a[i][j];
		if (i != n) vis[i + 1][j] = 1;
		if (i != 1) vis[i - 1][j] = 1;
		if (j != n) vis[i][j + 1] = 1;
		if (j != 1) vis[i][j - 1] = 1;
	};

	auto can_i_mark = [&](int i, int j) -> bool {
		int f = 0;
		if (i != n) f |= vis[i + 1][j];
		if (i != 1) f |= vis[i - 1][j];
		if (j != n) f |= vis[i][j + 1];
		if (j != 1) f |= vis[i][j - 1];
		return !f;
	};

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (can_i_mark(i, j)) mark(i, j);
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