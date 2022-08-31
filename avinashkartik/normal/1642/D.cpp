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

const ll   N     =  505;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, a[N];

void recurse(vector <int> &v, vector <pair <int, int>> &ans, vector <int> &split, int ct) {
	if (v.size() == 0) return;
	int j = 1;
	for (; j < v.size(); j++) {
		if (v[j] == v[0]) break;
	}
	vector <int> u;
	for (int i = 1; i < j; i++) {
		u.pb(v[i]);
		ans.pb({ct + j + i, v[i]});
	}
	reverse(all(u));
	for (int i = j + 1; i < v.size(); i++) u.pb(v[i]);
	split.pb(2 * j);
	recurse(u, ans, split, ct + j * 2);
}

void solve() {
	cin >> n;
	set <int> s;
	vector <int> v;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (s.find(a[i]) != s.end()) s.erase(a[i]);
		else s.insert(a[i]);
		v.pb(a[i]);
	}
	
	if (s.size()) {
		deb1(-1)
		return;
	}
	
	vector <pair <int, int>> ans;
	vector <int> split;
	recurse(v, ans, split, 0);
	deb1(ans.size());
	for (auto it : ans) deb2(it.f, it.s)
	deb1(split.size())
	debv(split)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}