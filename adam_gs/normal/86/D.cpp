#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e5+7, K=500;
ll T[LIM], ans[LIM], ile[5*LIM], akt;
vector<pair<pair<int,int>,int>>V[K];
void zmien(ll x, ll p) {
	akt-=ile[x]*ile[x]*x;
	ile[x]+=p;
	akt+=ile[x]*ile[x]*x;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q;
	cin >> n >> q;
	rep(i, n) cin >> T[i];
	rep(i, q) {
		int l, r;
		cin >> l >> r; --l; --r;
		V[l/K].pb({{r, l}, i});
	}
	rep(i, K) sort(all(V[i]));
	rep(i, K) {
		rep(j, n) ile[T[j]]=0;
		akt=0;
		int p=i*K, k=i*K-1;
		for(auto j : V[i]) {
			int l=j.st.nd, r=j.st.st;
			while(k<r) {
				++k;
				zmien(T[k], 1);
			}
			while(p<l) {
				zmien(T[p], -1);
				++p;
			}
			while(p>l) {
				--p;
				zmien(T[p], 1);
			}
			ans[j.nd]=akt;
		}
	}
	rep(i, q) cout << ans[i] << '\n';
}