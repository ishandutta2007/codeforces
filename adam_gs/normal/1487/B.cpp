#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
const int LIM=1e5+7, MOD=1e9+7;
void solve() {
	int n, k;
	cin >> n >> k;
	if(n%2==0) {
		cout << ((k-1)%n)+1 << '\n';
	} else {
		int p=n/2;
		p=(k-1)/p;
		k+=p;
		cout << ((k-1)%n)+1 << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	//t=1;
	while(t--) solve();
}