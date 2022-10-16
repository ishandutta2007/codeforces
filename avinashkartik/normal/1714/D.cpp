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
string t;
pair <int, int> ans[N];

void solve() {
	cin >> t >> n;
	vector <string> s(n);
	for (int i = 0; i < n; i++) cin >> s[i];
	vector <int> mv(t.size(), INFi);
	for (int i = 0; i < t.size(); i++) {
		int cur = i == 0 ? 0 : mv[i - 1];
		for (int it = 0; it < n; it++) {
			if (s[it].size() + i > t.size()) continue;
			if (s[it] == t.substr(i, s[it].size())) {
				for (int j = i; j < i + s[it].size(); j++) {
					if (cur + 1 < mv[j]) {
						mv[j] = cur + 1;
						ans[j] = {i, it};
					} else if (cur + 1 == mv[j] && i + s[it].size() > ans[j].f + s[ans[j].s].size()) {
						ans[j] = {i, it};
					}
				}
			}
		}
	}
	if (mv.back() > t.size()) deb1(-1)
	else {
		set <pair <int, int>> s;
		for (int i = 0; i < t.size(); i++) {
			s.insert(ans[i]);
		}
		assert(s.size() == mv.back());
		deb1(mv.back())
		for (auto it : s) deb2(it.s + 1, it.f + 1)
	}
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}