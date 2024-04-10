#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int INF=1e9+7;
void solve() {
	int n;
	string s;
	cin >> n >> s;
	int ans=INF;
	rep(i, 26) {
		bool ok=true;
		int ile=0, p=0, k=n-1;
		while(p<k) {
			if(s[p]==s[k]) {
				++p;
				--k;
				continue;
			}
			if(s[p]=='a'+i) {
				++ile;
				++p;
			} else if(s[k]=='a'+i) {
				++ile;
				--k;
			} else {
				ok=false;
				break;
			}
		}
		if(ok) ans=min(ans, ile);
	}
	cout << (ans==INF?-1:ans) << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}