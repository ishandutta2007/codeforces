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
const int xn = 3e5+10;
const int xm = 1e2+10;
const int SQ = 1000;
const int sq = 1e3+10;
const int inf = 1e9+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}

ll n, m, L, a[xn], res;
int par[xn], sz[xn];



int main(){
	fast_io;
	
	cin >> n >> m >> L;
	for (int i = 1; i <= n; i++) cin >> a[i], res += (a[i] > L && a[i - 1] <= L);
	while (m--){
		int x, y;
		ll z;
		cin >> x;
		if (x == 0){
			cout << res << endl;
			continue;
		}
		cin >> y >> z;
		a[y] += z;
		if (a[y] <= L) continue;
		if (a[y] - z > L) continue; 
		int t = 0;
		t += (a[y - 1] > L) + (a[y + 1] > L);
		if (t == 0) res++;
		if (t == 2) res--;
	}
	
	return 0;
}