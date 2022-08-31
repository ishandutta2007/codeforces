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
typedef  pair<ll, ll>          pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  3e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, a[N], b[N], p[N];

void make(ll n){
	for(int i = 0; i <= n; i++){
		p[i] = i;
	}
}

int find(ll x){
	return (p[x] == x)? x: p[x] = find(p[x]);
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];

	vector <int> d(n + 1, INFi), w(n + 1, INFi);
	d[n] = 0;
	queue <int> q;
	q.push(n);
	make(n);
	while (q.size()) {
		int x = q.front();
		q.pop();
		int i = x + b[x];
		for (int j = i; j >= i - a[i]; j = find(j - 1)) {
			if (d[j] > d[i] + 1) {
				d[j] = d[i] + 1;
				w[j] = x;
				if (j == 0) break;
				p[j] = find(j - 1);
				q.push(j);
			}
			if (j == 0) break;
		}
	}
	if (d[0] == INFi) {
		deb1(-1)
	} else {
		int st = 0;
		vector <int> ans;
		while (st != n) {
			ans.pb(st);
			st = w[st];
		}
		reverse(all(ans));
		deb1(ans.size())
		debv(ans)
	}
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}