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
	string s;
	cin >> s;
	int ile[2], T[2];
	ile[0]=ile[1]=0;
	T[0]=T[1]=5;
	// zawodnik jeden strzela ciagle
	int ans=9;
	rep(i, 10) {
		if(i%2==0) {
			if(s[i]!='0') {
				++ile[0];
			}
			--T[0];
		} else {
			if(s[i]=='1') {
				++ile[1];
			}
			--T[1];
		}
		if(ile[0]-ile[1]>T[1]) {
			ans=min(ans, i);
			break;
		}
	}
	ile[0]=ile[1]=0;
	T[0]=T[1]=5;
	rep(i, 10) {
		if(i%2==0) {
			if(s[i]=='1') ++ile[0];
			--T[0];
		} else {
			if(s[i]!='0') ++ile[1];
			--T[1];
		}
		if(ile[1]-ile[0]>T[0]) {
			ans=min(ans, i);
			break;
		}
	}
	cout << ans+1 << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	cin >> t;
	while(t--) solve();
}