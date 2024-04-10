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
	string s;
	cin >> s;
	if(s.size()==1) {
		cout << 0 << '\n';
		return;
	}
	ll sum=0, ans=1;
	for(auto i : s) sum+=i-'0';
	while(sum>=10) {
		ll p=0;
		while(sum) {
			p+=sum%10;
			sum/=10;
		}
		sum=p;
		++ans;
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}