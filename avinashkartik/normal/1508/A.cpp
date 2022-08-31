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

const ll   N     =  3e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n;
string s[3];

void solve() {
	cin >> n >> s[0] >> s[1] >> s[2];
	string ans;
	for (int i = 0, j = 0, k = 0, no = 0; no < 3 * n; no++) {
		vector <int> ct(2, 0);
		if (i == 2 * n) {
			if (j == 2 * n || k == 2 * n) break;
			if (j > k) {
				ans += s[1][j];
				j++;
			} else {
				ans += s[2][k];
				k++;
			}
			continue;
		}
		if (j == 2 * n) {
			if (i == 2 * n || k == 2 * n) break;
			if (i > k) {
				ans += s[0][i];
				i++;
			} else {
				ans += s[2][k];
				k++;
			}
			continue;
		}
		if (k == 2 * n) {
			if (j == 2 * n || i == 2 * n) break;
			if (j > i) {
				ans += s[1][j];
				j++;
			} else {
				ans += s[0][i];
				i++;
			}
			continue;
		}
		ct[s[0][i] - '0']++;
		ct[s[1][j] - '0']++;
		ct[s[2][k] - '0']++;
		if (ct[1] > ct[0]) {
			ans += '1';
			if (s[0][i] == '1') i++;
			if (s[1][j] == '1') j++;
			if (s[2][k] == '1') k++;
		} else {
			ans += '0';
			if (s[0][i] == '0') i++;
			if (s[1][j] == '0') j++;
			if (s[2][k] == '0') k++;
		}
	}
	while (ans.size() < 3 * n) ans += '1';
	assert (ans.size() == 3 * n);
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}