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
const int  LEVEL =  log2(N) + 1;

int n, x, y, x0, y00;
map <pair <int, int>, int> d;
vector <int> dx4 = {1, -1, 0, 0}, dy4 = {0, 0, 1, -1};

void solve() {
	cin >> x0 >> y00 >> x >> y;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int r, a, b; cin >> r >> a >> b;
		for (int c = a; c <= b; c++) d[{r, c}] = INFi;
	}
	queue <pair <int, int>> q;
	q.push({x0, y00});
	d[{x0, y00}] = 0;
	while (q.size()) {
		auto &[x, y] = q.front();
		q.pop();
		for (auto dx : dx4) {
			for (auto dy : dy4) {
				if (d.find({x + dx, y + dy}) != d.end() && d[{x + dx, y + dy}] > d[{x, y}] + 1) {
					d[{x + dx, y + dy}] = d[{x, y}] + 1;
					q.push({x + dx, y + dy});
				}
			}
		}
	}
	if (d[{x, y}] == INFi) d[{x, y}] = -1;
	deb1((d[{x, y}]))
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}