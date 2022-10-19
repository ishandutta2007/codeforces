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
	string x;
	cin >> x;
	int ile[26];
	rep(i, 26) ile[i]=0;
	for(auto i : x) {
		++ile[i-'a'];
	}
	int ans=0, l=0;
	rep(i, 26) {
		if(ile[i]>=2) ++ans;
		if(ile[i]==1) ++l;
	}
	cout << ans+l/2 << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	cin >> t;
	while(t--) solve();
}