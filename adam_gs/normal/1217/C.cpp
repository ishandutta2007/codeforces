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
	string s;
	cin >> s;
	int n=s.size(), lewo[s.size()], ans=0;
	rep(i, n) {
		if(s[i]=='1') {
			lewo[i]=0;
			int akt=0;
			for(int j=i; j<min(i+20, (int)s.size()); ++j) {
				akt=2*akt+s[j]-'0';
				if(akt==j-i+1) ++ans;
				else if(akt>j-i+1) {
					int p=j-akt+1;
					if(i && i-lewo[i-1]<=p) ++ans;
				}
			}
		} else if(i) lewo[i]=lewo[i-1]+1;
		else lewo[i]=1;
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}