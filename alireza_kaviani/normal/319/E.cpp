#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())
#define lc							id << 1
#define rc							lc | 1

const ll MAXN = 3e5+ 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , cur , par[MAXN] , sz[MAXN] , L[MAXN] , R[MAXN];
vector<pair<int, pii>> vec;
vector<int> compress , seg[MAXN << 2];

int Find(int v){
	return (par[v] == -1 ? v : par[v] = Find(par[v]));
}

void Union(int v , int u){
	v = Find(v); u = Find(u);
	if(v == u)	return;
	if(sz[v] < sz[u])	swap(v , u);
	par[u] = v;
	sz[v] += sz[u];
	L[v] = min(L[v] , L[u]);
	R[v] = max(R[v] , R[u]);
}

void add(int pos , int num , int id = 1 , int l = 0 , int r = MAXN){
	for(int i : seg[id])	Union(i , num);
	seg[id] = {};
	if(r - l == 1)	return;
	int mid = l + r >> 1;
	if(pos < mid)	add(pos , num , lc , l , mid);
	else	add(pos , num , rc , mid , r);
}

void insert(int ql , int qr , int num , int id = 1 , int l = 0 , int r = MAXN){
	if(qr <= l || r <= ql)	return;
	if(ql <= l && r <= qr){
		seg[id].push_back(num);
		return;
	}
	int mid = l + r >> 1;
	insert(ql , qr , num , lc , l , mid);
	insert(ql , qr , num , rc , mid , r);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	fill(par , par + MAXN , -1);
	fill(sz , sz + MAXN , 1);

	cin >> n;
	for(int i = 0 ; i < n ; i++){
		int type , x , y;
		cin >> type >> x >> y;
		vec.push_back({type , {x , y}});
		if(type == 1){
			compress.push_back(x); compress.push_back(x + 1);
			compress.push_back(y);// compress.push_back(y - 1);
		}
	}
	sort(all(compress));
	compress.resize(unique(all(compress)) - compress.begin());
	for(auto &i : vec){
		int type = i.X , x = i.Y.X , y = i.Y.Y;
		if(type == 1){
			cur++;
			x = lower_bound(all(compress) , x) - compress.begin();
			y = lower_bound(all(compress) , y) - compress.begin();
			L[cur] = x; R[cur] = y;
			add(x , cur); add(y , cur);
			x = L[Find(cur)] , y = R[Find(cur)];
			insert(x + 1 , y , cur);
		}
		if(type == 2){
			if(L[Find(y)] <= L[Find(x)] && R[Find(x)] <= R[Find(y)])	cout << "YES" << endl;
			else	cout << "NO" << endl;
		}
	}

    return 0;
}
/*

*/