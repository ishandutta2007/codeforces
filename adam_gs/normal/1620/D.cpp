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
	int T[n];
	rep(i, n) cin >> T[i];
	sort(T, T+n);
	reverse(T, T+n);
	int x=0;
	if(T[0]%3==0) {
		rep(i, n) if(T[i]%3) x=1;
		cout << T[0]/3+x << '\n';
		return;
	}
	if(T[0]%3==2) {
		rep(i, n) if(T[i]%3==1) x=1;
		cout << T[0]/3+x+1 << '\n';
		return;
	}
	bool ok=true;
	rep(i, n) if(T[i]%3==2) ok=false;
	if(ok) {
		cout << T[0]/3+1 << '\n';
		return;
	}
	int ma=-3;
	ok=true;
	rep(i, n) {
		if(T[i]==1) ok=false;
		if(T[i]%3==0) ma=max(ma, T[i]);
	}
	if(ok && ma/3<T[0]/3) {
		cout << T[0]/3+1 << '\n';
		return;
	}
	cout << T[0]/3+2 << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}