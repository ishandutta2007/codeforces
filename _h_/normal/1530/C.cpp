#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

void solve(){
	int k;
	cin >> k;
	vi as(k), bs(k);
	trav(x, as) cin >> x;
	trav(x, bs) cin >> x;

	sort(all(as));
	sort(all(bs));

	vi apre(k+1), bpre(k+1);

	rep(i,0,k) apre[i+1] = apre[i] + as[i];
	rep(i,0,k) bpre[i+1] = bpre[i] + bs[i];

	for(int ans = 0; ; ++ans){
		int drop = (k + ans) / 4;
		int myscore = 100 * ans + apre[k] - apre[drop];
		int yourscore = bpre[k] - bpre[max(0, drop - ans)];
		if(myscore >= yourscore){
			cout << ans << endl;
			return;
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(_,0,n){
		solve();
	}
}