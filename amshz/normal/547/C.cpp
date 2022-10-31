# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair <ll, int> pii;
 
# define F first
# define S second
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 5e5+10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3+10;
const ll inf = 1e18+10;
 

 
ll n, q, a[xn], c[xn], ans, m;
vector <int> adj[xn], vec[xn];
bool p[xn], flag[xn];
 
void Build(){
	for (int i = 1; i <= 5e5; i++){
		for (int j = i; j <= xm; j += i){
			adj[j].pb(i);
			
		}
	}
	p[1] = true;
	for (int i = 2; i <= xm; i++){
		if (p[i]) continue;
		vec[i].pb(i);
		for (int j = i + i; j <= xm; j += i){
			p[j] = true;
			vec[j].pb(i);
		}
	}
}
 
ll fn1(int x, int pnt, ll s, bool f){
	if (pnt == vec[x].size()){
		if (s == 1) return 0;
		if (!f) return -c[s];
		return c[s];
	}
	return fn1(x, pnt + 1, s, f) + fn1(x, pnt + 1, s * vec[x][pnt], !f);
}
 
 
 
int main(){
	fast_io;
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	Build();
	
	
	while (q--){
		int x;
		cin >> x;
		
		ll t = fn1(a[x], 0, 1, 0);
		if (!flag[x]){
			ans += m - t;
			m++;
		}
		else{
			if (a[x] > 1) t--;
			ans -= (m - 1) - t;
			m--;
		}
		
		for (int i = 0; i < adj[a[x]].size(); i++){
			int y = adj[a[x]][i];
			if (flag[x]) c[y]--;
			else c[y]++; 
		}
		
		flag[x] = !flag[x];
		cout << ans << endl;
	}
	
	
	return 0;
}