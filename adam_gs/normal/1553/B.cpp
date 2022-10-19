#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
#define all(a) a.begin(), a.end()
ll pow(ll a,ll b,ll c){ll w=1;while(b){if(b&1)w=(w*a)%c;b/=2;a=(a*a)%c;}return w;}
void solve() {
	string s, t;
	cin >> s >> t;
	rep(pocz, s.size()) {
		for(int kon=pocz; kon<s.size(); ++kon) {
			string akt="";
			int p=pocz;
			while(p<=kon) {
				akt+=s[p];
				++p;
			}
			--p;
			while(p>0 && akt.size()<t.size()) {
				--p;
				akt+=s[p];
			}
			if(akt==t) {
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	cin >> t;
	while(t--) solve();
}