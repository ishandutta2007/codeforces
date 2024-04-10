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
const int MAXA=512, INF=1e9+7;
int mi[MAXA];
void solve() {
	int n;
	cin >> n;
	rep(i, MAXA-1) mi[i+1]=INF;
	rep(i, n) {
		int a;
		cin >> a;
		rep(j, MAXA) {
			if(mi[a^j]<a) mi[j]=min(mi[j], a);
		}
	}
	vector<int>ans;
	rep(i, MAXA) if(mi[i]<INF) ans.pb(i);
	cout << ans.size() << '\n';
	for(auto i : ans) cout << i << " ";
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}