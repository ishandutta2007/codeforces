#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const int LIM=1e6+7;
int a[LIM], b[LIM], ans[LIM];
void solve() {
	int n;
	cin >> n;
	int sum=0;
	rep(i, n) {
		cin >> a[i] >> b[i];
		sum+=a[i];
	}
	rep(i, n) {
		if(abs(sum)<=500) break;
		ans[i]=1;
		sum-=1000;
	}
	rep(i, n) cout << (ans[i]?"G":"A");
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}