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

int gcd(int x, int y){
	x = abs(x), y = abs(y);
	while(x){
		y %= x;
		swap(x, y);
	}
	return y;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, k;
	cin >> n >> k;

	vector<pii> xy(n);

	trav(p, xy) cin >> p.first >> p.second;

	map<pii, int> ren;
	trav(p, xy){
		int d = gcd(p.first, p.second);
		pii q = d ? pii( p.first / d, p.second / d) : pii(0,0);
		ren[q] = 0;
	}
	int ix = 0;
	trav(pa, ren) pa.second = ix++;

	vector<vector<ll>> ls(ix);

	trav(p, xy){
		int d = gcd(p.first, p.second);
		pii q = d ? pii( p.first / d, p.second / d) : pii(0,0);
		ls[ren[q]].push_back(ll(p.first) * p.first + ll(p.second) * p.second);
	}

	trav(v, ls) sort(all(v));

	vi l(ix), r(ix);
	vector<double> sm(ix);

	auto get_nxt = [&](int i){
		if(l[i] + r[i] == sz(ls[i])) return -1e100;
		if(2 * r[i] >= k){
			double d = sqrt(ls[i][l[i]]);
			double ans =  d * (k-1 - 2 * r[i]) - 2 * sm[i];
			sm[i] += d;
			++l[i];
			return ans;
		} else {
			double ans = sqrt(ls[i][sz(ls[i])-1-r[i]]) * (k-1-2*r[i]);
			++r[i];
			return ans;
		}
	};

	double ans = 0;
	priority_queue<pair<double, int>> pq;
	rep(i,0,ix) pq.push({get_nxt(i), i});
	rep(_, 0, k){
		auto pa = pq.top();
		pq.pop();
		ans += pa.first;
		pq.push({get_nxt(pa.second), pa.second});
	}
	cout.precision(8);
	cout << ans << endl;
}