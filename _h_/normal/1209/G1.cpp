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

const int amax = 2e5+1;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	vi as(n);
	trav(x, as) cin >> x;
	vi mn(amax,n), mx(amax,-1), cnt(amax);
	rep(i,0,n) mn[as[i]] = min(mn[as[i]], i);
	rep(i,0,n) mx[as[i]] = max(mx[as[i]], i);
	rep(i,0,n) cnt[as[i]]++;
	vector<vector<pii>> ut(n);
	
	int ans = 0;
	for(int pos = 0; pos < n;){
		int cur = 0;
		int nxt = pos+1;
		int i = pos;
		while(i < nxt){
			cur = max(cur, cnt[as[i]]);
			nxt = max(nxt, mx[as[i]]+1);
			++i;
		}
		ans += cur;
		pos = nxt;
	}
	cout << n - ans << endl;
}