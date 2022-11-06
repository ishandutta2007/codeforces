#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int solve(){
	int n, k;
	cin >> n >> k;
	vi a(n);
	trav(x, a) cin >> x;
	int jumps = 0;
	rep(i,1,n) if(a[i] != a[i-1]) ++jumps;
	if(k == 1){
		return (jumps==0 ? 1 : -1);
	} else {
		int ans = 1;
		while(ans * (k-1) < jumps) ++ ans;
		return ans;
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;
	rep(_,0,n) cout << solve() << endl;
}