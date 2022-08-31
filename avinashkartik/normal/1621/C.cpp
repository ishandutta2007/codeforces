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
const ll   INF   =  1e16;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

ll n;

void solve() {
	cin >> n;
	vector <int> ans(n + 1, 0), vis(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		vector <int> v;
		int x;
		if (!vis[i]) {
			while (1) {
				cout << "? " << i << endl;
				cin >> x;
				vis[x]++;
				v.pb(x);
				if (vis[x] == 2) break;
			}
		}
		for (int i = 0; i < (int) v.size() - 1; i++) {
			ans[v[i]] = v[i + 1];
		}
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