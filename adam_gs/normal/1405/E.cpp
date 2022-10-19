#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=3e5+7;
vector<pair<int,int>>V[LIM];
int T[LIM], odp[LIM], tr[4*LIM], N=1;
void upd(int l, int r) {
	l+=N; r+=N;
	++tr[l];
	if(l!=r) ++tr[r];
	while(l/2!=r/2) {
		if(l%2==0) ++tr[l+1];
		if(r%2==1) ++tr[r-1];
		l/=2; r/=2;
	}
}
int cnt(int v) {
	v+=N;
	int ans=0;
	while(v) {
		ans+=tr[v];
		v/=2;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q;
	cin >> n >> q;
	while(N<n) N*=2;
	rep(i, n) {
		cin >> T[i]; --T[i];
	}
	rep(i, q) {
		int x, y;
		cin >> x >> y;
		V[n-1-y].pb({x, i});
	}
	rep(i, n) {
		int p=i-T[i];
		if(p>=0 && cnt(0)>=p) {
			int po=0, ko=i;
			while(po<ko) {
				int sr=(po+ko+1)/2;
				if(cnt(sr)>=p) po=sr; else ko=sr-1;
			}
			upd(0, po);
		}
		for(auto j : V[i]) odp[j.nd]=cnt(j.st);
	}
	rep(i, q) cout << odp[i] << '\n';
}