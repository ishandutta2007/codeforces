#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 5e2 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll n, dis[Maxn][Maxn];

vector<ll> pos, pos2;

ll get(){
	ll mn = Inf, ind = -1, sm;
	for(auto x : pos){
		sm = 0;
		for(auto y : pos) sm += dis[x][y];
		if(sm < mn){
			mn = sm;
			ind = x;
		}
	}
	return ind;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(dis, 31, sizeof dis);
	ll m, k;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) dis[i][i] = 0;
	ll la, u;
	for(int i = 0; i < m; i++){
		cin >> k >> la;
		for(int j = 1; j < k; j++){
			cin >> u;
			dis[u][la] = dis[la][u] = 1;
			la = u;
		}
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	
	str res;
	ll nx, cent;
	for(int iter = 1; iter <= n; iter ++){
		pos.clear();
		for(int i = 1; i <= n; i++) pos.pb(i);
		
		while(true){
			cent = get();
			cout << cent << endl;
			cin >> res;
			if(res == "FOUND") break;
			cin >> nx;
			//debug(nx);
			pos2.clear();
			for(auto x : pos) if(dis[x][nx] < dis[x][cent]) pos2.pb(x);
			pos2.swap(pos);
			
		}
	}
	return 0;
}
/*
5 2
5 1 2 3 4 5
2 1 3

*/