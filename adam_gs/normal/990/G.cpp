#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
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
const int LIM=2e5+7;
vector<int>V[LIM], D[LIM], podzielne[LIM];
int T[LIM], odw[LIM], akt;
ll ans[LIM], rozmiar;
void DFS(int x, int o) {
	odw[x]=akt;
	++rozmiar;
	for(auto i : V[x]) if(i!=o && T[i]%akt==0) DFS(i, x);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int i=1; i<LIM; ++i) {
		for(int j=i; j<LIM; j+=i) D[j].pb(i);
	}
	int n;
	cin >> n;
	rep(i, n) {
		cin >> T[i];
		for(auto j : D[T[i]]) podzielne[j].pb(i);
	}
	rep(i, n-1) {
		int a, b;
		cin >> a >> b; --a; --b;
		V[a].pb(b);
		V[b].pb(a);
	}
	for(int i=1; i<LIM; ++i) {
		akt=i;
		for(auto j : podzielne[i]) if(odw[j]<akt) {
			rozmiar=0;
			DFS(j, j);
			ans[i]+=rozmiar*(rozmiar+1)/2;
		}
	}
	for(int i=LIM-1; i; --i) {
		for(auto j : D[i]) if(j!=i) {
			ans[j]-=ans[i];
		}
	}
	rep(i, LIM) if(ans[i]) cout << i << " " << ans[i] << '\n';
}