#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
const int LIM=1e5+7, MOD=1e9+7;
int T[LIM], dp[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	rep(i, n) cin >> T[i];
	if(n==1) {
		cout << 1;
		return 0;
	}
	vector<int>a, li;
	a.pb(T[0]);
	a.pb(T[1]);
	for(int i=2; i<n; ++i) {
		if(T[i]!=a[a.size()-1] || T[i]!=a[a.size()-2]) a.pb(T[i]);
	}
	vector<pair<int,int>>V;
	V.pb({a[0], 1});
	for(int i=1; i<a.size(); ++i) {
		if(V[V.size()-1].st==a[i]) {
			++V[V.size()-1].nd;
			li.pb(V.size()-1);
		}
		else V.pb({a[i], 1});
	}
	int ans=a.size();
	if(li.size()<2) {
		cout << ans;
		return 0;
	}
	rep(i, li.size()-1) {
		if(V[li[i]].st==V[li[i+1]].st) {
			int dost=2, z=V[li[i]].st;
			for(int j=li[i]+1; j<li[i+1]; ++j) {
				if(V[j].st==z) ++dost;
				else --dost;
				dost=max(dost, 0);
			}
			ans-=dost;
		}
	}
	cout << ans << '\n';
}