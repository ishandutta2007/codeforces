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

const ll Mod = 1000000007LL;
const int N = 5e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll ans[N];
vector<pll> V;
ll val[N];
ll a[N];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	ll S = 0;
	for(int i = 0; i < n; i++){
		ll cnt = 1;
		while(!V.empty() && V.back().F >= a[i]){
			cnt += V.back().S;
			S -= V.back().F * V.back().S;
			V.pop_back();
		}
		S += cnt * a[i];
		V.pb({a[i], cnt});
		val[i] = S;
	}
	S = 0;
	V.clear();
	
	for(int i = n-1; i >= 0; i--){
		ll cnt = 1;
		while(!V.empty() && V.back().F >= a[i]){
			cnt += V.back().S;
			S -= V.back().F * V.back().S;
			V.pop_back();
		}
		S += cnt * a[i];
		V.pb({a[i], cnt});
		val[i] += S - a[i];
	}
	ll idx = max_element(val, val + n) - val;
	for(int i = idx + 1; i < n; i++) a[i] = min(a[i - 1], a[i]);
	for(int i = idx - 1; i >= 0; i--) a[i] = min(a[i + 1], a[i]);
	for(int i = 0; i < n; i++) cout << a[i] << ' ';
	return 0;
}