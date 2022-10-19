#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
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
	map<int,int>mp;
	int n;
	cin >> n;
	int ans=0;
	rep(i, n) {
		int a;
		cin >> a;
		if(a==0) {
			++mp[0];
			if(mp[0]==1) ++ans;
			continue;
		}
		++mp[abs(a)];
		if(mp[abs(a)]<=2 ) ++ans;
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}