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
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int n, k, l[N], r[N], d[N], p[N];
char nxt[N];
vector <int> order;
string s;

void dfs(int x) {
	if (l[x]) dfs(l[x]);
	order.pb(x);
	if (r[x]) dfs(r[x]);
}

void mark(int x) {
	while (x > 0 && d[x] != 1) {
		d[x] = 1;
		x = p[x];
	}
}

void check(int x, int no) {
	if (nxt[x] > s[x] && no <= k && nxt[x] != '#') {
		k -= no;
		mark(x);
	}
	if (l[x]) check(l[x], d[x] == 1? 1 : no + 1);
	if (r[x] && d[x] == 1) check(r[x], 1);
}

void solve() {
	cin >> n >> k >> s;
	s = '#' + s + '#';
	for (int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i];
		p[l[i]] = i;
		p[r[i]] = i;
	}
	dfs(1);
	vector <char> st;
	for (int i = 1; i <= n; i++) nxt[i] = '#';
	for (int i = n - 1; i >= 0; i--) {
		if (st.size() == 0 || s[order[i]] != st.back()) st.pb(s[order[i]]);
		if (st.size() > 1) nxt[order[i]] = st[st.size() - 2];
	}
	check(1, 1);
	string ans;
	for (int i = 0; i < n; i++) {
		ans += s[order[i]];
		if (d[order[i]] == 1) ans += s[order[i]];
	}
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}