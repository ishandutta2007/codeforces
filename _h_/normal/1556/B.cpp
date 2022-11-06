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

const ll inf = 1e11;

ll calc(const vi &as){
	vi des, act;	
	rep(i,0,sz(as)){
		if(i%2 == 0){
			des.push_back(i);
		}
		if(as[i]%2 == 0){
			act.push_back(i);
		}
	}
	if(sz(des) != sz(act)) return inf;
	ll ans = 0;
	rep(i,0,sz(des)) ans += abs(des[i] - act[i]);
	return ans;
}

ll solve(){
	int n;
	cin >> n;
	vi as(n);
	trav(a, as) cin >> a;

	ll ans = inf;
	ans = min(ans, calc(as));
	trav(x, as) x += 1;
	ans = min(ans, calc(as));
	return ans == inf ? -1 : ans;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(_,0,n){
		cout << solve() << endl;
	}
}