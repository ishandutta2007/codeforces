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
const int xn = 2e5 + 10;
const int xm = 1e5 + 10;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

int qq, n, cnt[xn], f[xn], ans, ted, S;
vector <int> adj[xn];
set <pii, greater <pii> > st;

int main(){
	fast_io;
	
	cin >> qq;
	while (qq --){
		for (int i = 0; i <= n; i ++) cnt[i] = f[i] = 0;
		ans = ted = 0;
		st.clear();
		cin >> n;
		for (int i = 0; i < n; i ++){
			int x, y;
			cin >> x >> y;
			cnt[x] ++;
			f[x] += y;
		}
		for (int i = 0; i <= n; i ++) adj[i].clear();
		for (int i = 1; i <= n; i ++) adj[cnt[i]].push_back(f[i]);
		S = 0;
		for (int i = n; i > 0; i --){
			for (int x : adj[i]) st.insert({x, S ++});
			if (st.size()){
				int x = st.begin() -> F;
				st.erase(st.begin());
				ans += i;
				ted += min(x, i);
			}
		}
		cout << ans << sep << ted << endl;
	}
	
	return 0;
}