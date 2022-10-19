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
	int T[n], ile=0;
	rep(i, n) {
		cin >> T[i];
		if(T[i]<0) {
			T[i]*=-1;
			++ile;
		}
	}
	while(ile--) T[ile]*=-1;
	rep(i, n-1) if(T[i]>T[i+1]) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}