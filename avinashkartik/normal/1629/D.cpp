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

const ll   N     =  5e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int n;
string s[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s[i];

	map <string, bool> m, s2, s3;
	for (int i = 1; i <= n; i++) {
		m[s[i]] = 1;
		string t = s[i];
		reverse(all(t));
		if (m.find(t) != m.end()) {
			deb1("YES")
			return;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (s[i].size() == 2) {
			string t = s[i];
			reverse(all(t));
			if (s3.find(t) != s3.end()) {
				deb1("YES")
				return;
			}
			s2[s[i]] = 1;
		} else {
			string t1 = s[i].substr(0, 2);
			string t2 = s[i].substr(1, 2);
			reverse(all(t2));
			if (s2.find(t2) != s2.end()) {
				deb1("YES")
				return;
			}
			s3[t1] = 1;
		}
	}
	deb1("NO")
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}