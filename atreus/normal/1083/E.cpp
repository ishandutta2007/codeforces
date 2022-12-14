#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
const int maxn = 1e6 + 5;
const int inf = 1e9;

vector <pair <ll, ll> > v;
pair <pii, ll> rec[maxn];

bool mustremove(pii fi, pii se, pii th) {
	return 1. * (se.S - fi.S) / (fi.F - se.F) >= 1. * (th.S - se.S) / (se.F - th.F);
}

void add(ll a, ll b){ // ax + b
	if (!v.empty() and b < v.back().second)
		return;
	while (v.size() > 1){
		pair <ll, ll> last = v.back();
		v.pop_back();
		if (!mustremove({a, b}, last, v.back())){
			v.push_back(last);
			break;
		}
	}
	v.push_back({a, b});
}

ll gety(ll x, pii ln) {
	return ln.S + ln.F * x;
}

ll get(ll x) {
	int lo = 0, hi = v.size() - 1;
	while (hi - lo > 1){
		int mid = (hi + lo) >> 1;
		if (gety(x, v[mid]) < gety(x, v[mid + 1]))
			lo = mid;
		else
			hi = mid;
	}
	return max(gety(x, v[lo]), gety(x, v[hi]));
}

ll dp[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> rec[i].F.F >> rec[i].F.S >> rec[i].S;
	}
	sort(rec + 1, rec + n + 1);
	
	dp[1] = rec[1].F.F * rec[1].F.S - rec[1].S;
	add(-rec[1].F.F, dp[1]);
	ll ans = dp[1];
	for (int i = 2; i <= n; i++){
		dp[i] = max(rec[i].F.F * rec[i].F.S - rec[i].S, get(rec[i].F.S) + rec[i].F.F * rec[i].F.S - rec[i].S);
		add(-rec[i].F.F, dp[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}