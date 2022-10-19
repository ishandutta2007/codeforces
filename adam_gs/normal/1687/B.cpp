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
	int n, m;
	cin >> n >> m;
	pair<int,int>T[m];
	rep(i, m) {
		cout << "? ";
		rep(j, m) if(j==i) cout << '1'; else cout << '0';
		cout << endl;
		cin >> T[i].st;
		T[i].nd=i;
	}
	sort(T, T+m);
	ll ans=0;
	int P[m];
	rep(i, m) P[i]=0;
	rep(i, m) {
		P[T[i].nd]=1;
		cout << "? ";
		rep(j, m) cout << P[j];
		cout << endl;
		ll x;
		cin >> x;
		if(x==ans+T[i].st) ans=x;
		else P[T[i].nd]=0;
	}
	cout << "! " << ans << endl;
}
int main() {
	int _=1;
	while(_--) solve();
}