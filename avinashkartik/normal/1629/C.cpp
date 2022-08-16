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

int n, a[N];

void solve() {
	cin >> n;
	vector <int> suf(n + 1, 0), ans;
	for (int i = 1; i <= n; i++) cin >> a[i];
	set <int> s;
	for (int i = n, mex = 0; i >= 1; i--) {
		s.insert(a[i]);
		while (s.find(mex) != s.end()) mex++;
		suf[i] = mex;
	}

	for (int i = 1; i <= n;) {
		int m = suf[i], j = i, mex = 0;
		ans.pb(m);
		s.clear();
		do {
			s.insert(a[j]);
			while (s.find(mex) != s.end()) mex++;
			j++;
		} while (j <= n && mex != m);
		i = j;
	}
	deb1(ans.size())
	debv(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}