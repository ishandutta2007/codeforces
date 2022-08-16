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
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll, ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  3e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, x, ans[N];

void solve() {
	cin >> n;
	int ind = n;
	for (int i = 1; i < n; i += 2) {
		cout << "? ";
		deb4(1, i, i + 1, n - 1)
		cin >> x;
		if (x == n) {
			ind = i + 1;
			break;
		} else if (x == n - 1) {
			cout << "? ";
			deb4(1, i + 1, i, n - 1)
			cin >> x;
			if (x == n) {
				ind = i;
				break;
			}
		}
	}
	ans[ind] = n;
	for (int i = 1; i <= n; i++) {
		if (i == ind) continue;
		cout << "? ";
		deb4(2, i, ind, 1)
		cin >> ans[i];
	}
	cout << "! ";
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << endl;
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}