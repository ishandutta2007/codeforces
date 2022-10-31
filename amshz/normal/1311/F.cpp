# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 2e5+10;
const int xm = 5e5;
const int SQ = 250;
const int sq = 1e3+10;
const ll inf = 1e18+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}

int n;
map <int, int> mp;
pair <ll, ll> X[xn];
ll x[xn], v[xn], PS[xn], t[xn], ans;


void Get(int l, int r, int ind){
	for (int i = l; i <= r;){
		if (i%SQ == 0 && i + SQ - 1 <= r){
			ans -= PS[i/SQ] - x[ind] * t[i/SQ];
			i += SQ;
		}
		else{
			if (v[i] <= v[ind]) ans += x[ind] - x[i];
			i ++;
		}
	}
}
void Update(int ind){
	PS[ind/SQ] += x[ind];
	t[ind/SQ] ++;
}



int main(){
	fast_io;
	
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> x[i];
	for (int i = 0; i < n; i ++) cin >> v[i];
	
	for (int i = 0; i < n; i ++) X[i] = {x[i], v[i]};
	sort(X, X + n);
	
	for (int i = 0; i < n; i ++) x[i] = X[i].F, v[i] = X[i].S, swap(X[i].F, X[i].S), mp[x[i]] = i;
	sort(X, X + n);
	
	for (int i = 0; i < n; i ++){
		Get(0, mp[X[i].S] - 1, mp[X[i].S]);
		Update(mp[X[i].S]);
	}
	
	cout << ans << endl;
	
	
	return 0;
}