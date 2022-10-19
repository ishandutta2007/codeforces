#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	// jesli B ma cos poza A to odpowiedz tak
	vector<ll>A(26), B(26);
	A[0]=B[0]=1;
	int q;
	cin >> q;
	while(q--) {
		ll t, k;
		string x;
		cin >> t >> k >> x;
		if(t==1) {
			for(auto i : x) A[i-'a']+=k;
		} else {
			for(auto i : x) B[i-'a']+=k;
		}
		bool ok=false;
		rep(i, 25) if(B[i+1]) ok=true;
		if(ok) {
			cout << "YES\n";
			continue;
		}
		rep(i, 25) if(A[i+1]) ok=true;
		if(ok) {
			cout << "NO\n";
			continue;
		}
		cout << (A[0]<B[0]?"YES":"NO") << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}