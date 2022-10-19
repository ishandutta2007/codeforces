#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int ans=2;
	rep(i, n) ans*=(i+1);
	ans/=n*n;
	cout << ans << '\n';
}