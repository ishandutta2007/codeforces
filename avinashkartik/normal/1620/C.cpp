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

const ll   N     =  5e5 + 2;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

ll n, k, x, a[N];
string s;

void solve() {
	cin >> n >> k >> x;
	cin >> s;
	vector <int> v;
	for (auto it : s) {
		if (it == 'a') v.pb(0);
		else if (v.size() && v.back()) v[v.size() - 1]++;
		else v.pb(1);
	}
	vector <int> ans(v.size(), 0);
	ll cur = 1;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i] == 0) continue;
		if (v[i] * k + 1 >= (x + cur - 1) / cur) {
			for (int j = i; j < v.size(); j++) {
				if (v[j] == 0) continue;
				if (j != i) cur /= (v[j] * k + 1);
				// deb3(j, x, cur)
				for (int no = 0; no <= v[j] * k; no++) {
					if (x <= cur) break;
					x -= cur;
					ans[j] = no + 1;
				}
			}
			break;
		}
		cur *= (v[i] * k + 1);
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 0) {
			cout << 'a';
			continue;
		}
		for (int j = 0; j < ans[i]; j++) cout << 'b';
	}
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