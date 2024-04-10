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
	map<int,int>mp;
	int ma=0;
	rep(i, n) {
		int a;
		cin >> a;
		++mp[a];
		ma=max(ma, mp[a]);
	}
	int ans=n-ma, p=n-ma;
	while(p>0) {
		++ans;
		p-=ma;
		ma*=2;
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}