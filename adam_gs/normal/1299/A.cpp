#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
void solve() {
	int n;
	cin >> n;
	int T[n], ile[31], odw[n];
	rep(i, 31) ile[i]=0;
	rep(i, n) {
		cin >> T[i];
		odw[i]=0;
		rep(j, 31) if(T[i]&(1<<j)) ++ile[j];
	}
	vector<int>ans;
	for(int j=30; j>=0; --j) if(ile[j]==1) {
		rep(i, n) if(T[i]&(1<<j)) {
			if(!odw[i]) {
				odw[i]=1;
				ans.pb(T[i]);
			}
		}
	}
	for(auto i : ans) cout << i << " ";
	rep(i, n) if(!odw[i]) cout << T[i] << " ";
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}