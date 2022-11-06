#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const ll inf = 1e14;

struct UF {

	vi t;

	UF(int n) {
		t.assign(n,-1);
	}

	int find(int a){
		return t[a] < 0 ? a : t[a] = find(t[a]);
	}

	void merge(int a, int b){
		a = find(a), b = find(b);
		if(a == b) return;
		t[a] = b;
	}

};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	cin >> n >> m;
	vi x(n);
	vector<pii> pc(m);
	trav(a, x) cin >> a;
	sort(all(x));
	rep(j,0,m) cin >> pc[j].first >> pc[j].second;
	sort(all(pc));
	vi p(m), c(m);
	rep(j,0,m){
		p[j] = pc[j].first;
		c[j] = pc[j].second;
	}

	vector<vector<ll>> dp(2, vector<ll>(n+1, inf));
	dp[1][0] = 0;

	rep(j,0,m){
		vector<ll> pre(n+1), dif(n+1);;
		rep(i,0,n) pre[i+1] = pre[i] + abs(p[j] - x[i]);
		rep(i,0,n+1) dif[i] = dp[!(j&1)][i] - pre[i];

		UF u(n+1);
		stack<pair<int,ll>> st;

		rep(b,0,n+1){
			while(!st.empty() && st.top().second >= dif[b]){
				u.merge(st.top().first, b);
				st.pop();
			}
			st.push({b, dif[b]});
			dp[j&1][b] = pre[b] + dif[u.find(max(0,b-c[j]))];
		}
	}
	ll ans = dp[(m-1)&1][n];
	if(ans >= inf) ans = -1;
	cout << ans << endl;
}