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
	int n, k;
	string s;
	cin >> n >> k >> s;
	if(k&1) rep(i, n) s[i]=((s[i]-'0')^1)+'0';
	int T[n];
	rep(i, n) {
		T[i]=0;
		if(s[i]=='0' && k) {
			s[i]='1';
			T[i]=1;
			--k;
		}
	}
	if(k) {
		if(k&1) s[n-1]='0';
		T[n-1]+=k;
	}
	cout << s << '\n';
	rep(i, n) cout << T[i] << " ";
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}