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

const ll   N     =  2e3 + 5;
const ll   M     =  1e7 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, d;
string s[N];

void solve() {
	cin >> d >> n;
	for(int i = 1; i <= n; i++) cin >> s[i];
	sort(s + 1, s + n + 1, [&](string x, string y) { 
		return count(all(x), '1') < count(all(y), '1'); 
	});
	vector <int> vis(n + 1, 0);
	ll res = 0;
	vector <char> ans;
	for(int i = 1; i <= n; i++) {
		if(vis[i] == 1) continue;
		int ind = i;
		if(ans.size()) ans.pb('R');
		for(int k = 0; k < d; k++) {
			if(s[ind][k] == '1') ans.pb(k + '0');
		}
		for(int j = i + 1; j <= n; j++) {
			if(vis[j] == 1) continue;
			int f = 1;
			for(int k = 0; k < d; k++) {
				if(s[ind][k] == '1') f &= (s[j][k] == '1');
			}
			if(f == 1) {
				for(int k = 0; k < d; k++) {
					if(s[j][k] == '1' && s[ind][k] == '0') ans.pb(k + '0');
				}
				ind = j, vis[j] = 1;
			}
		}
	}
	deb1(ans.size())
	debv(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	//cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}