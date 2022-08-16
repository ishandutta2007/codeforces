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

const ll   N     =  2e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, a[N];

int f(int u, int v) {
	if (u > v) swap(u, v);
	int d = v - u;
	if (d >= u) return (v + 1) / 2;
	int ans = d;
	u -= d;
	ans += (u / 3) * 2 + u % 3;
	return ans;
}

void solve() {
	cin >> n;
	multiset <int> s;
	for (int i = 1; i <= n; i++) cin >> a[i], s.insert(a[i]);
	
	auto mx1 = *s.begin();
	s.erase(s.begin());
	auto mx2 = *s.begin();
	s.clear();
	
	int ans = (mx1 + 1) / 2 + (mx2 + 1) / 2;
	for (int i = 2; i < n; i++) {
		int u = a[i - 1], v = a[i + 1];
		if (u > v) swap(u, v);
		ans = min(ans, u + (v - u + 1) / 2);
	}
	for (int i = 1; i < n; i++) {
		ans = min(ans, f(a[i], a[i + 1]));
	}
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}