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

	vi p(n);
	trav(x, p) cin >> x;

	sort(all(p));
	reverse(all(p));

	vector<ll> pre(n+1);
	rep(i,0,n) pre[i+1] = pre[i] + p[i];

	int x, a, y, b;
	cin >> x >> a >> y >> b;

	if(x < y){
		swap(x,y);
		swap(a,b);
	}

	ll k;
	cin >> k;

	ll m = ll(a) / __gcd(a, b) * b;

	auto works = [&](int to){
		int xy = (int)(to / m);
		int xx = to / a - xy;
		int yy = to / b - xy;

		ll res = 0;
		res += (pre[xy] - pre[0])*(x+y);
		res += (pre[xx+xy] - pre[xy])*x;
		res += (pre[yy+xx+xy] - pre[xx+xy])*y;
		res /= 100;

		return res >= k;
	};

	int lo = 0, hi = n+1;
	while(lo+1 < hi){
		int mi = (lo + hi)/2;
		if(works(mi)) hi = mi;
		else lo = mi;
	}
	return hi<=n ? hi : -1;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	rep(_,0,n) cout << solve() << endl;
}