#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200005
#define INF 101111111111111
using namespace std;
ll xres[N], a[N], n;
vector<ll> d[N];
bool was[2][N];
int main(){
	FAST;
	cin >> n;
	for(ll i =1;i<=n;i++){
		cin >> a[i];
		if(i-a[i] >= 1) d[i-a[i]].pb(i);
		if(i+a[i] <= n) d[i+a[i]].pb(i);
		xres[i] = INF;
	}
	queue<pll> q;
	for(ll i = 1;i<=n;i++) if(a[i]&1) {was[0][i] = 1; q.push({i, 0});}
	while(!q.empty()){
		pll nn = q.front();
		ll v = nn.x, l = nn.y;
		q.pop();
		if((~a[v])&1){
			xres[v] = l;
		}
		for(auto i : d[v]) if(!was[0][i]) {q.push({i, l+1});was[0][i]= 1;}
	}

	for(ll i = 1;i<=n;i++) if((~a[i])&1) {was[1][i] = 1; q.push({i, 0});}
	while(!q.empty()){
		pll nn = q.front();
		ll v = nn.x, l = nn.y;
		q.pop();
		if(a[v]&1){
			xres[v] = l;
		}
		for(auto i : d[v]) if(!was[1][i]) {q.push({i, l+1}); was[1][i]= 1;}
	}

	for(ll i =1;i<=n;i++) cout << (xres[i] == INF ? -1 : xres[i]) << " ";
	cout << endl;
}