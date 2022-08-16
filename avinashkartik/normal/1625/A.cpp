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

const ll   N     =  3e5 + 2;
const ll   mod   =  998244353;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int n, l, a[N];

void solve() {
	cin >> n >> l;
	vector <int> ct(l, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 0; j < l; j++) {
			if ((a[i] >> j)&1) ct[j]++;
		}
	}
	int ans = 0;
	for (int j = 0; j < l; j++) {
		if (ct[j] > n - ct[j]) ans += (1 << j);
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