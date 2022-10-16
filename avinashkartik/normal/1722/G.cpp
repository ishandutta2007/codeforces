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

int n;

void solve() {
	cin >> n;
	int x = (1 << 29), y = (1 << 28), z = (1 << 27);
	vector <int> a(n);
	if (n % 2 == 0) {
		for (int i = 0, j = 1; i < n; i += 2, j++) {
			a[i + 1] = j;
			a[i] = j + x;
		}
		a[0] += y;
		if (n % 4 == 2) a[0] -= x;
		a[2] += y;
	} else {
		for (int i = 0, j = 1; i < n - 1; i += 2, j++) {
			a[i + 1] = j;
			a[i] = j + x;
		}
		a[0] += y;
		if (n % 4 == 3) a[0] -= x;
		a[2] += y;
		a[n - 1] += z;
		a[1] += z;
	}
	debv(a)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}