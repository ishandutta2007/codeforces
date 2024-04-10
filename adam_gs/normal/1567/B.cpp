#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=3e5+7;
int pre[LIM];
void solve() {
	int a, b;
	cin >> a >> b;
	if(pre[a-1]==b) {
		cout << a << '\n';
		return;
	}
	if((pre[a-1]^b)==a) {
		cout << a+2 << '\n';
		return;
	}
	cout << a+1 << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int i=1; i<LIM; ++i) {
		pre[i]=pre[i-1]^i;
	}
	int _;
	cin >> _;
	while(_--) solve();
}