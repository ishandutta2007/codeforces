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
	ll n, k, T[19];
	rep(i, 19) T[i]=-1;
	cin >> n >> k; ++k;
	rep(i, n) {
		int a;
		cin >> a;
		T[a]=1;
	}
	rep(i, 19) if(T[i]==-1) T[i]=T[i-1]*10;
	vector<ll>ans;
	ll sum=0;
	for(int i=0; sum<k; ++i) {
		ans.pb(9);
		sum+=T[i]*9;
	}
	for(int i=ans.size()-1; i>=0; --i) {
		while(ans[i]>0) {
			if(sum-T[i]<k) break;
			sum-=T[i];
			--ans[i];
		}
	}
	reverse(all(ans));
	for(auto i : ans) cout << i;
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}