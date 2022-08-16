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

const ll   N     =  105;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n;
string s;
vector <int> v = {22, 25, 27, 32, 33, 35, 52, 55, 57, 72, 75, 77};

void solve() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' || s[i] == '9') {
			deb1(1)
			deb1(s[i])
			return;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 3; j++) {
			int no = (s[i] - '0') * 10 + s[j] - '0';
			if (find(all(v), no) != v.end()) {
				deb1(2)
				deb1(no)
				return;
			}
		}
	}
}

int main() {
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}