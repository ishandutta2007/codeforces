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
	int n, m, x;
	cin >> n >> m >> x;
	int k=m-n;
	if(k>=0) {
		int p=x-k+1;
		if(p<0) {
			cout << 0 << '\n';
			return;
		}
		k+=(p+1)/2;
		cout << x-k+1 << '\n';
		return;
	}
	int p=x+k+1;
	if(p<=0) {
		cout << x+1 << '\n';
		return;
	}
	cout << x-(p+1)/2+1 << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}