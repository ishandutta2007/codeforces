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
	cin >> n;
	ll T[n], sum=0, lst=0;
	rep(i, n) {
		cin >> T[i];
		sum+=T[i];
		if(T[i]!=0) lst=i+1;
	}
	n=lst;
	if(!n) {
		cout << "Yes\n";
		return;
	}
	ll akt=0;
	rep(i, n-1) {
		akt+=T[i];
		if(akt<=0) {
			cout << "No\n";
			return;
		}
	}
	akt=0;
	for(int i=n-1; i; --i) {
		akt+=T[i];
		if(akt==0 && T[i]!=0) {
			cout << "No\n";
			return;
		}
		if(akt>0) {
			cout << "No\n";
			return;
		}
	}
	cout << (sum==0?"Yes":"No") << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}