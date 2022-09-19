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
const int N = 1e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll ans = 0, fu = 0;
void Up(ll a, ll b){
	if(a == ans) fu = min(fu, b);
	if(a > ans){
		ans = a;
		fu = b;
	}
}
vector<ll> A[4];
ll c[N], f[N], l[N];
bool CMP(ll i, ll j){
	return f[i] < f[j];
}
ll ps[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, d, S;
	cin >> n >> d >> S;
	for(int i = 0; i < n; i++){
		cin >> c[i] >> f[i] >> l[i];
		if(l[i] >= d) l[i] = 1;
		else l[i] = 0;
		A[l[i] + (c[i]>0) + (c[i] > 0)].pb(i);
	}
	for(int i = 0; i < 4; i++) sort(all(A[i]), CMP);
	ll cnt = 0, sm = 0;
	for(auto i : A[1]){
		if(sm + f[i] <= S){
			cnt ++;
			sm += f[i];
		}
	}
	Up(cnt, sm);
	for(int i = 1; i <= A[1].size(); i++) ps[i] = ps[i - 1] + f[A[1][i - 1]];
	cnt = 0, sm = 0;
	ll R = 0;
	for(auto i : A[3]) R += c[i] - 1;
	for(auto i : A[2]) R += c[i] - 1;
	ll F = 0;
	for(int i = 1; i <= A[3].size(); i++){
		F += f[A[3][i - 1]];
		if(F > S) break;
		cnt = A[3].size() + A[2].size();
		sm = F;
		ll rq = R + i;
		ll d = min(rq, (ll)A[0].size());
		rq -= d;
		cnt += d;

		d = min(rq, (ll)A[1].size());
		cnt += d;
		ll y = upper_bound(ps, ps + (A[1].size() - d) + 1, S - F) - ps;
		cnt += y - 1;
		Up(cnt, sm + ps[y - 1]);
	}
	cout << ans << ' ' << fu << '\n';
	return 0;
}