# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 1e5+10;
const int xm = 2e5+10;
const int SQ = 1000;
const int sq = 1e3+10;
const int inf = 1e9+10;
 
 
ll n, A[xn], m, B[xn], C[xn], ans, D[xn], E[xn];
 
 
ll Index(int i, int j){
	return A[i * m + j];
}
 
bool cmp(ll i, ll j){
	return i > j;
}
 
void F4(){
	for (int i = 0; i < n; i++) D[i] = B[i];
	for (int j = 0; j < m; j++) E[j] = C[j];
	sort(D, D + n, cmp);
	sort(E, E + m, cmp);
	ll s = 0;
	for (int i = 0; i < min(n, ll(4)); i++) s += D[i];
	ans = max(ans, s);
	s = 0;
	for (int i = 0; i < min(m, ll(4)); i++) s += E[i];
	ans = max(ans, s);
	return;
}
void F1_3(){
	for (int k = 0; k < n; k++){
		for (int i = 0; i < m; i++) E[i] = C[i] - Index(k, i);
		sort(E, E + m, cmp);
		ll s = B[k];
		for (int i = 0; i < min(m, ll(3)); i++) s += E[i];
		ans = max(ans, s);
	}
	for (int k = 0; k < m; k++){
		for (int i = 0; i < n; i++) D[i] = B[i] - Index(i, k);
		sort(D, D + n, cmp);
		ll s = C[k];
		for (int i = 0; i < min(n, ll(3)); i++) s += D[i];
		ans = max(ans, s);
	}
}
ll m2min(){
	ll x = D[0], y = D[1];
	if (x > y) swap(x, y);
	for (int i = 2; i < n; i++){
		if (D[i] < x) continue;
		x = D[i];
		if (x > y) swap(x, y);
	}
	return x + y;
}
ll m2minn(){
	ll x = E[0], y = E[1];
	if (x > y) swap(x, y);
	for (int i = 2; i < n; i++){
		if (E[i] < x) continue;
		x = E[i];
		if (x > y) swap(x, y);
	}
	return x + y;
}
 
 
void F2_2(){
	if (n < 2 || m < 2) return;
	if (n < m){
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				for (int k = 0; k < m; k++) E[k] = C[k] - Index(i, k) - Index(j, k);
				ll s = B[i] + B[j] + m2minn();
				ans = max(ans, s);
			}
		}
	}
	if (n < m) return;
	for (int i = 0; i < m; i++){
		for (int j = i + 1; j < m; j++){
			for (int k = 0; k < n; k++) D[k] = B[k] - Index(k, i) - Index(k, j);
			ll s = C[i] + C[j] + m2min();
			ans = max(ans, s);
		}
	}
}
 
 
int main(){
	fast_io;
	
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) cin >> A[i];
	
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) B[i] += Index(i, j), C[j] += Index(i, j);
	
	F4();
	F1_3();
	F2_2();
	
	cout << ans << endl;
	
	
	return 0;
}