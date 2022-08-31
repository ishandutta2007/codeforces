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

const ll   N     =  4e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int n, a[N], b[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	vector <int> ia(n), ib(n), vis(n + 1, 0);
	iota(all(ia), 1);
	sort (all(ia), [&](int i, int j) {
		return a[i] > a[j];
	});
	iota(all(ib), 1);
	sort (all(ib), [&](int i, int j) {
		return b[i] > b[j];
	});

	queue <int> q;
	q.push(ia[0]);
	q.push(ib[0]);
	int i = 1, j = 1;
	while (q.size()) {
		int x = q.front();
		q.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		while (i < n && a[ia[i]] >= a[x]) {
			q.push(ia[i]);
			i++;
		}
		while (j < n && b[ib[j]] >= b[x]) {
			q.push(ib[j]);
			j++;
		}
	}
	for (int i = 1; i <= n; i++) cout << vis[i];
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