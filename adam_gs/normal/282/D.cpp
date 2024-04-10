#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const int LIM=307;
int dp[LIM][LIM][LIM], T[3];
void solve() {
	int n;
	cin >> n;
	rep(i, n) cin >> T[i];
	if(n==3) {
		if((T[0]^T[1]^T[2])!=0) {
			cout << "BitLGM\n";
		} else {
			cout << "BitAryo\n";
		}
		return;
	}
	rep(a, T[0]+1) rep(b, T[1]+1) rep(c, T[2]+1) {
		for(int i=1; i<=a; ++i) if(!dp[a-i][b][c]) {
			dp[a][b][c]=1;
			break;
		}
		if(dp[a][b][c]) continue;
		for(int i=1; i<=b; ++i) if(!dp[a][b-i][c]) {
			dp[a][b][c]=1;
			break;
		}
		if(dp[a][b][c]) continue;
		for(int i=1; i<=c; ++i) if(!dp[a][b][c-i]) {
			dp[a][b][c]=1;
			break;
		}
		if(dp[a][b][c]) continue;
		if(n==2) {
			int p=min(a, b);
			for(int i=1; i<=p; ++i) if(!dp[a-i][b-i][c]) {
				dp[a][b][c]=1;
				break;
			}
		} else if(n==3) {
			int p=min(min(a, b), c);
			for(int i=1; i<=p; ++i) if(!dp[a-i][b-i][c-i]) {
				dp[a][b][c]=1;
				break;
			}
		}
	}
	cout << (dp[T[0]][T[1]][T[2]]?"BitLGM":"BitAryo") << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}