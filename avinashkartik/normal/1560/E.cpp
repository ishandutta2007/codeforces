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

const ll   N     =  1e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n;
string s;

void solve() {
	cin >> s;
	n = s.size();

	vector <int> ct(26, 0);
	set <char> se;
	string t, ans;

	for (int i = n - 1; i >= 0; i--) {
		ct[s[i] - 'a']++;
		if (se.find(s[i]) == se.end()) {
			t += s[i];
			se.insert(s[i]);
		}
	}

	int m = t.size();
	string res = t;

	for (int i = 0; i < m; i++) {
		if (ct[t[i] - 'a'] % (m - i)) {
			deb1(-1)
			return;
		}
		ct[t[i] - 'a'] /= (m - i);
	}

	for (int i = 0; i < n; i++) {
		ct[s[i] - 'a']--;
		int f = 1;
		for (auto it : t) {
			if (ct[it - 'a'] < 0) {
				deb1(-1)
				return;
			}
			f &= (ct[it - 'a'] == 0);
		}
		if (f == 1) {
			ans = s.substr(0, i + 1);
			break;
		}
	}

	string st = ans, ch = ans;
	for (int j = 0; j < m; j++) {
		string s1 = st, res = "";
		for (auto it : s1) {
			if (it != t.back()) {
				res += it;
			}
		}
		st = res;
		ch += res;
		t.pop_back();
	}

	if (ch == s) {
		reverse(all(res));
		deb2(ans, res)
	} else deb1(-1)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}