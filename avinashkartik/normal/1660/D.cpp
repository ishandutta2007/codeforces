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
	int p = 0, f = n, l = 0, ans = 0;
	int p0 = 0, p1 = 0;
	vector <int> t(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		if (!a[i]) {
			p0 = i;
			p1 = p = 0;
			continue;
		}
		t[i] = t[i - 1];
		if (a[i] == 2) t[i]++;
		if (a[i] == -2) t[i]++, p ^= 1;
		if (a[i] == -1) p ^= 1;
		if (p1 == 0 && p == 1) p1 = i;
		if (p == 0) {
			if (t[i] - t[p0] > ans) {
				ans = t[i] - t[p0];
				f = p0;
				l = n - i;
			}
		} else if (p1 != i) {
			if (t[i] - t[p1] > ans) {
				ans = t[i] - t[p1];
				f = p1;
				l = n - i;
			}
		}
	}
	deb2(f, l)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}