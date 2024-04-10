#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=35e3+7, INF=1e9+7;
int T[LIM], tr[4*LIM][107], lazy[4*LIM][107], ostatni[LIM], N=1;
void spl(int v, int k) {
	tr[2*v][k]+=lazy[v][k];
	tr[2*v+1][k]+=lazy[v][k];
	lazy[2*v][k]+=lazy[v][k];
	lazy[2*v+1][k]+=lazy[v][k];
	lazy[v][k]=0;
}
void dodaj(int v, int l, int r, int a, int b, int k, int x) {
	if(b<l || r<a) return;
	if(a<=l && r<=b) {
		tr[v][k]+=x;
		lazy[v][k]+=x;
		return;
	}
	if(lazy[v][k]) spl(v, k);
	int mid=(l+r)/2;
	dodaj(2*v, l, mid, a, b, k, x);
	dodaj(2*v+1, mid+1, r, a, b, k, x);
	tr[v][k]=min(tr[2*v][k], tr[2*v+1][k]);
}
int licz(int v, int l, int r, int a, int b, int k) {
	if(b<l || r<a) return INF;
	if(a<=l && r<=b) return tr[v][k];
	if(lazy[v][k]) spl(v, k);
	int mid=(l+r)/2;
	int ans=min(licz(2*v, l, mid, a, b, k), licz(2*v+1, mid+1, r, a, b, k));
	tr[v][k]=min(tr[2*v][k], tr[2*v+1][k]);
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	while(N<=n) N*=2;
	rep(i, n) {
		cin >> T[i+1]; --T[i+1];
	}
	rep(j, k) dodaj(1, 0, N-1, 0, 0, j+1, INF);
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=min(k, i); ++j) {
			if(ostatni[T[i]]) {
				dodaj(1, 0, N-1, 0, ostatni[T[i]]-1, j-1, i-ostatni[T[i]]);
			}
			int mi=licz(1, 0, N-1, 0, i-1, j-1);
			dodaj(1, 0, N-1, i, i, j, mi);
		}
		ostatni[T[i]]=i;
		for(int j=min(k, i)+1; j<=k; ++j) {
			dodaj(1, 0, N-1, i, i, j, INF);
		}
		dodaj(1, 0, N-1, i, i, 0, INF);
	}
	cout << licz(1, 0, N-1, n, n, k) << '\n';
}