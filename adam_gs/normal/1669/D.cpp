#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	int n;
	string s;
	cin >> n >> s;
	s+="W";
	string akt="";
	rep(i, n+1) {
		if(s[i]=='W') {
			if(!akt.size()) continue;
			int ilea=0, ileb=0;
			for(auto j : akt) if(j=='B') ++ilea; else ++ileb;
			if(min(ilea, ileb)==0 && max(ilea, ileb)!=0) {
				cout << "NO\n";
				return ;;
			}
			akt="";
		} else akt+=s[i];
	}
	cout << "YES\n";
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}