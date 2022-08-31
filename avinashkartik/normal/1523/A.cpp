
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
typedef  pair<ll, ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  2e3 + 5;
const ll   mod   =  998244353;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, m;
string s;

void solve() {
	cin >> n >> m >> s;
	vector <ll> w(n, INFi);
	queue <int> q;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			w[i] = 0;
			q.push(i);
		}
	}
	while (q.size()) {
		int x = q.front();
		q.pop();
		if (x && w[x - 1] >= w[x] + 1) {
			if (w[x - 1] == w[x] + 1) w[x - 1] = INFi;
			else {
				q.push(x - 1);
				w[x - 1] = w[x] + 1;
			}
		}
		if (x != n - 1 && w[x + 1] >= w[x] + 1) {
			if (w[x + 1] == w[x] + 1) w[x + 1] = INFi;
			else {
				q.push(x + 1);
				w[x + 1] = w[x] + 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (w[i] <= m) cout << "1";
		else cout << "0";
	}
	newl;
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}