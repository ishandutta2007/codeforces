#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
const int LIM=1e5+7;
int T[LIM], ile[LIM], ans[LIM], sum[LIM];
pair<int,int>pyt[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, n) {
		cin >> T[i];
		if(T[i]<=n) ++ile[T[i]];
	}
	rep(i, m) {
		cin >> pyt[i].st >> pyt[i].nd;
		--pyt[i].st; --pyt[i].nd;
	}
	rep(i, n) if(ile[i+1]>=i+1) {
		sum[0]=0;
		if(T[0]==i+1) ++sum[0];
		for(int j=1; j<n; ++j) {
			sum[j]=sum[j-1];
			if(T[j]==i+1) ++sum[j];
		}
		rep(j, m) {
			int ile=sum[pyt[j].nd];
			if(pyt[j].st) ile-=sum[pyt[j].st-1];
			if(ile==i+1) ++ans[j];
		}
	}
	rep(i, m) cout << ans[i] << '\n';
}