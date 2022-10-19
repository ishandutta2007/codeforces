#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
const int LIM=2e5+7;
int T[LIM][2];
void solve() {
	int n;
	cin >> n;
	rep(j, 2) rep(i, n) {
		char a;
		cin >> a;
		if(a>'2') T[i][j]=1; else T[i][j]=0;
	}
	int p=0;
	rep(i, n) {
		if(T[i][p]) {
			if(T[i][p^1]) {
				p^=1;
			} else {
				cout << "NO\n";
				return;
			}
		}
	}
	cout << (p?"YES":"NO") << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}