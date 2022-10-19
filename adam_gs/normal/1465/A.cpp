#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pr(a, b) make_pair(a, b)
#define pb(a) push_back(a)
typedef long long ll;
const int LIM=1e5+7;
const ll MOD=1e9+7;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string x;
		cin >> x;
		int l=n-1;
		while(l>=0) {
			if(x[l]!=')') break;
			--l;
		}
		if(l+1<n-l-1) cout << "Yes"; else cout << "No";
		cout << '\n';
	}
}