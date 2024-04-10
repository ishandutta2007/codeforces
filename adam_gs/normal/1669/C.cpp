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
	int ile[2][2];
	rep(i, 2) rep(j, 2) ile[i][j]=0;
	rep(i, n) {
		int a;
		cin >> a;
		ile[i%2][a%2]=1;
	}
	cout << (min(ile[0][0], ile[0][1])==0 && min(ile[1][0], ile[1][1])==0?"YES":"NO") << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}