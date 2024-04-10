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
		int n, ans=0;
		string a, b;
		cin >> n >> a >> b;
		rep(i, n) if(a[i]>b[i]) ++ans; else if(a[i]<b[i]) --ans;
		if(ans==0) cout << "EQUAL";
		if(ans<0) cout << "BLUE";
		if(ans>0) cout << "RED";
		cout << '\n';
	}
}