#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define trav(x, v) for(auto &x : v)
#define all(v) v.begin(), v.end()
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<vi> vvi;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, k;
	cin >> n >> k;

	vi ilo(n, k), ihi(n, -1);
	rep(i,0,k){
		int x;
		cin >> x;
		--x;
		ilo[x] = min(ilo[x], i);
		ihi[x] = max(ihi[x], i);
	}
	int ans = 0;
	rep(i,0,n) if(ilo[i] == k) ++ans;
	rep(i,0,n) for(int j = i-1; j <= i+1; j += 2) if(j >= 0 && j < n){
		if(ilo[i] > ihi[j]) ++ans;
	}
	cout << ans << endl;
}