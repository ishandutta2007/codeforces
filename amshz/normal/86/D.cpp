# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 1e6 + 10;
const int xm = 1e3 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const ll inf = 1e18+ 10;
 
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

ll n, m, a[xn], Qind[xn], ptr, ans[xn], cnt[xn];
pii Q[xn];

void Solve(int ind){
	ll ted = 0;
	memset(cnt, 0, sizeof cnt);
	for (int i = ind; i < n; i ++){
		ted -= cnt[a[i]] * cnt[a[i]] * a[i];
		cnt[a[i]] ++;
		ted += cnt[a[i]] * cnt[a[i]] * a[i];
		while (ptr < m && Q[Qind[ptr]].S == i){
			int j = Qind[ptr];
			ll t = ted;
			for (int k = ind; k < Q[j].F; k ++){
				t -= cnt[a[k]] * cnt[a[k]] * a[k];
				cnt[a[k]] --;
				t += cnt[a[k]] * cnt[a[k]] * a[k];
			}
			for (int k = ind; k < Q[j].F; k ++) cnt[a[k]] ++;
			ans[j] = t;
			ptr ++;
		}
	}
}

bool cmp(ll i, ll j){
	if (Q[i].F / SQ != Q[j].F / SQ) return Q[i].F / SQ < Q[j].F / SQ;
	return Q[i].S < Q[j].S;
}

 
int main(){
	fast_io;
	
	cin >> n >> m;
	for (int i = 0; i < n; i ++) cin >> a[i];
	for (int i = 0; i < m; i ++){
		cin >> Q[i].F >> Q[i].S;
		Q[i].F --, Q[i].S --;
		Qind[i] = i;
	}
	sort(Qind, Qind + m, cmp);
	for (int i = 0; i < n; i += SQ) Solve(i);
	for (int i = 0; i < m; i ++) cout << ans[i] << endl;
	
	return 0;
}