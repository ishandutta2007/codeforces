#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const int LIM=1e7+7;
int odw[LIM], T[LIM], cp[LIM], mi[LIM];
vector<int>pi;
pair<int,int>ans[LIM];
void solve() {
	for(int i=2; i<LIM; ++i) {
		if(cp[i]) continue;
		pi.pb(i);
		for(int j=i; j<LIM; j+=i) {
			cp[j]=1;
			if(!mi[j]) mi[j]=i;
		}
	}
	int n;
	cin >> n;
	rep(i, n) {
		cin >> T[i];
		if(!odw[T[i]]) {
			odw[T[i]]=1;
			ans[T[i]]={-1, -1};
			int x=T[i], p=mi[x];
			while(x%p==0) x/=p;
			if(x>1) {
				ans[T[i]]={p, x};
			}
		}
	}
	rep(i, n) cout << ans[T[i]].st << " ";
	cout << '\n';
	rep(i, n) cout << ans[T[i]].nd << " ";
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}