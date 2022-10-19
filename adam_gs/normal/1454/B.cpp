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
		pair<int,int>T[n];
		rep(i, n) {
			cin >> T[i].first;
			T[i].second=i+1;
		}
		sort(T, T+n);
		bool bl=true;
		rep(i, n) {
			bool k=true;
			if(i>0 && T[i].first==T[i-1].first) k=false;
			if(i<n-1 && T[i].first==T[i+1].first) k=false;
			if(k) {
				cout << T[i].second;
				bl=false;
				break;
			}
		}
		if(bl) cout << -1;
		cout << '\n';
	}
}