// written by aitch
// on 2019 10/24 at 11:58:39
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

int solve(){
	int n;
	cin >> n;
	vi a(n);
	trav(x,a) cin >> x;
	map<int, int> ren;
	trav(x,a) ren[x];
	int ix = 0;
	trav(pa,ren) pa.second = ix++;
	vi mn(ix,n), mx(ix);
	rep(j,0,n){
		int i = ren[a[j]];
		mn[i] = min(mn[i], j);
		mx[i] = max(mx[i], j);
	}
	vi len(ix);
	len[ix-1] = 1;
	rrep(i,0,ix-1){
		if(mx[i] < mn[i+1]) len[i] = 1 + len[i+1];
		else len[i] = 1;
	}
	int rek = 0;
	trav(x, len) rek = max(rek, x);
	return ix - rek;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	rep(_,0,n) cout << solve() << endl;
}