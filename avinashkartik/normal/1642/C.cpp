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
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, x, a[N];

void solve() {
	cin >> n >> x;
	map <ll, int> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		m[a[i]]++;
	}
	sort(a + 1, a + n + 1);
	
	int ct = 0;
	for (int i = 1; i <= n; i++) {
		if (m[a[i]] == 0) continue;
		if (a[i] % x == 0 && m[a[i] / x]) {
			m[a[i]]--;
			m[a[i] / x]--;
		} else if (m[a[i] * x]) {
			m[a[i]]--;
			m[a[i] * x]--;
		} else {
			m[a[i]]--;
			ct++;
		}
	}
	deb1(ct)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}