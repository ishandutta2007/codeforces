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
	int ile[3], l=0, ans=s.size()+1;
	rep(i, 3) ile[i]=0;
	rep(i, s.size()) {
		while(l<s.size() && min(ile[0], min(ile[1], ile[2]))==0) {
			++ile[s[l]-'1'];
			++l;
		}
		if(min(ile[0], min(ile[1], ile[2]))==0) break;
		ans=min(ans, l-i);
		--ile[s[i]-'1'];
	}
	ans%=s.size()+1;
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}