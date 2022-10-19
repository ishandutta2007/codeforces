#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
const int LIM=3e5+7;
int T[LIM][10], n, m, ans1, ans2;
bool spr(int x) {
	vector<int>V[1<<m];
	rep(i, n) {
		int l=0;
		rep(j, m) {
			if(T[i][j]>=x) l+=1<<j;
		}
		V[l].pb(i);
	}
	rep(i, 1<<m) {
		if(!V[i].size()) continue;
		rep(j, 1<<m) {
			if(!V[j].size()) continue;
			if((i|j)==(1<<m)-1) {
				ans1=V[i][0];
				ans2=V[j][0];
				return true;
			}
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	rep(i, n) rep(j, m) cin >> T[i][j];
	int p=0, k=1000000000;
	while(p<k) {
		int sr=(p+k+1)/2;
		if(spr(sr)) p=sr; else k=sr-1;
	}
	spr(p);
	cout << ans1+1 << " " << ans2+1 << '\n';
}