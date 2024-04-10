#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
const int INF=1e9+7;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		pair<int,int>T[n], Tp[n];
		rep(i, n) {
			cin >> T[i].first >> T[i].second;
			Tp[i].first=T[i].second;
			Tp[i].second=T[i].first;
		}
		sort(T, T+n);
		sort(Tp, Tp+n);
		int ans=INF;
		rep(i, n) {
			int p=0, k=n-1, z;
			while(p<k) {
				int sr=(p+k+1)/2;
				if(Tp[sr].first>=T[i].first) k=sr-1; else p=sr;
			}
			z=p+1;
			if(Tp[0].first>=T[i].first) z=0;
			p=0; k=n-1;
			while(p<k) {
				int sr=(p+k)/2;
				if(T[sr].first<=T[i].second) p=sr+1; else k=sr;
			}
			if(T[n-1].first>T[i].second) {
				z+=n-p;
			}
			ans=min(ans, z);
		}
		cout << ans << '\n';
	}
}