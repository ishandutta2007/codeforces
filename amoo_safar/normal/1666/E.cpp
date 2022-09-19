// Son
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const ll Mod = 1000000007LL;
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int a[N];
int l, n;

vector<pii> V;
int find_min(){
	int lw = 1, hg = l + 1, mid;
	while(lw + 1 < hg){
		mid = (lw + hg) / 2;
		bool fail = false;

		int nw = 0;
		for(auto [ls, rs] : V){
			nw += mid;
			if(nw > rs){
				fail = true;
				break;
			}
			nw = max(nw, ls);
		}
		if(fail) hg = mid;
		else lw = mid;
	}
	return lw;
}
int find_max(){
	int lw = 0, hg = l, mid;
	while(lw + 1 < hg){
		mid = (lw + hg) / 2;
		bool fail = false;

		int nw = 0;
		for(auto [ls, rs] : V){
			nw += mid;
			if(nw < ls){
				fail = true;
				break;
			}
			nw = min(nw, rs);
		}
		if(!fail) hg = mid;
		else lw = mid;
	}
	return hg;
}


int la[N], ra[N];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> l >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i < n; i++) V.pb({a[i], a[i + 1]});
	V.pb({l, l});
	int mn = find_min();
	int mx = find_max();

	int l = 0, r = 0;
	for(int i = 1; i <= n; i++){
		l += mn;
		r += mx;
		r = min(r, V[i - 1].S);
		l = max(l, V[i - 1].F);
		assert(l <= r);
		la[i] = l;
		ra[i] = r;
	}
	vector<int> ans = {l};
	for(int i = n - 1; i >= 0; i--){
		int x = ans.back();
		int lg = max(x - mx, la[i]);
		int rg = min(x - mn, ra[i]);
		ans.pb(lg);
	}
	reverse(all(ans));
	for(int i = 0; i < n; i++) cout << ans[i] << ' ' << ans[i + 1] << '\n';
	return 0;
}