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
	int zero[k], jeden[k];
	rep(i, k) zero[i]=jeden[i]=0;
	rep(i, n) if(s[i]=='0') zero[i%k]=1; else if(s[i]=='1') jeden[i%k]=1;
	rep(i, k) if(zero[i] && jeden[i]) {
		cout << "NO\n";
		return;
	}
	int ilez=0, ilej=0;
	rep(i, k) {
		ilez+=zero[i];
		ilej+=jeden[i];
	}
	cout << (max(ilez, ilej)<=k/2?"YES":"NO") << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}