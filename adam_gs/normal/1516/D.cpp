#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e5+7, LG=20;
vector<int>dziel[LIM];
int T[LIM], ile[LIM], nxt[LIM][LG];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int i=2; i<LIM; ++i) {
		if(dziel[i].size()) continue;
		for(int j=i; j<LIM; j+=i) dziel[j].pb(i);
	}
	int n, q;
	cin >> n >> q;
	rep(i, n) cin >> T[i];
	int l=0, k=n-1;
	for(int i=n-1; i>=0; --i) {
		for(auto j : dziel[T[i]]) {
			++ile[j];
			if(ile[j]==2) ++l;
		}
		while(l) {
			for(auto j : dziel[T[k]]) {
				--ile[j];
				if(ile[j]==1) --l;
			}
			--k;
		}
		nxt[i][0]=k+1;
	}
	rep(i, LG) nxt[n][i]=n;
	for(int j=1; j<LG; ++j) {
		rep(i, n) nxt[i][j]=nxt[nxt[i][j-1]][j-1];
	}
	while(q--) {
		int l, r, ans=1;
		cin >> l >> r; --l; --r;
		for(int i=LG-1; i>=0; --i) if(nxt[l][i]<=r) {
			ans+=1<<i;
			l=nxt[l][i];
		}
		cout << ans << '\n';
	}
}