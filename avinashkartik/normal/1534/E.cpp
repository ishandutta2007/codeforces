#include<bits/stdc++.h>

using namespace std;

#define  f              first                 
#define  s              second
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll, ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  1e6 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, k;

void solve() {
	cin >> n >> k;
	vector <int> d(n + 1, INFi), p(n + 1, -1);
	d[0] = 0;
	queue <int> q;
	q.push(0);
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (int i = 1; i <= k; i++) {
			int add = i, rem = (k - i);
			if (add <= (n - x) && x >= rem) {
				if (d[x - rem + add] > d[x] + 1) {
					d[x - rem + add] = d[x] + 1;
					q.push(x - rem + add);
					p[x - rem + add] = x;
				}
			}
		}
	}
	if (p[n] == -1) {
		deb1("-1")
		return;
	} else {
		vector <int> path, vis(n + 1, 0);
		int x = n, ans = 0;
		while (x) {
			path.pb(x);
			x = p[x];
		}
		reverse(all(path));
		for (auto y : path) {
			int add = (k + y - x) / 2, rem = (k + x - y) / 2;
			vector <int> q;
			for (int i = 1; i <= n; i++) {
				if (add && vis[i] == 0) {
					q.pb(i);
					vis[i] ^= 1;
					add--;
				} else if (rem && vis[i] == 1) {
					q.pb(i);
					vis[i] ^= 1;
					rem--;
				}
			}
			cout << "? ";
			debv(q);
			int Q; cin >> Q;
			ans ^= Q;
			x = y;
		}
		deb2("!", ans)
	}
}

int main() {
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}