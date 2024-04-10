#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
void solve() {
	int n, k;
	cin >> n >> k;
	int T[n];
	bool zawiera=false;
	rep(i, n) {
		cin >> T[i];
		if(T[i]==k) zawiera=true;
	}
	if(!zawiera) {
		cout << "no\n";
		return;
	}
	rep(i, n-1) if(T[i]>=k && T[i+1]>=k) {
		cout << "yes\n";
		return;
	}
	rep(i, n-2) if(T[i]>=k && T[i+2]>=k) {
		cout << "yes\n";
		return;
	}
	if(n==1 && T[0]==k) {
		cout << "yes\n";
		return;
	}
	cout << "no\n";
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}