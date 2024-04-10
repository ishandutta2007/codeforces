# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair <ll, ll> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 1e3+10;
const int xm = 1e6+10;

ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}


int dis[xm], a[xn], n, k;
queue <int> q;

 
int main(){
	fast_io;
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	for (int i = 0; i <= 1e6; i++) dis[i] = -1;
	
	q.push(a[0]*k);
	dis[a[0]*k] = 0;
	while (q.size()){
		int x = q.front();
		q.pop();
		for (int i = 1; i < n; i++){
			int y = x + a[i] - a[0];
			if (dis[y] != -1) continue;
			dis[y] = dis[x] + 1;
			q.push(y);
		}
	}
	for (int i = 1; i <= 1e6; i++) if (dis[i] != -1 && dis[i] <= k) cout << i << sep;
	cout << endl;
	
	return 0;
}