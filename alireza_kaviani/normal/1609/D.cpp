#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , d , sz[MAXN] , par[MAXN];

int Find(int v){
	return (par[v] == -1 ? v : par[v] = Find(par[v]));
}

void Union(int v , int u){
	v = Find(v); u = Find(u);
	if(v == u)	return;
	if(sz[v] < sz[u])	swap(v , u);
	par[u] = v;
	sz[v] += sz[u];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	fill(par , par + MAXN , -1);
	fill(sz , sz + MAXN , 1);

	cin >> n >> d;
	for(int i = 1 ; i <= d ; i++){
		int v , u;
		cin >> v >> u;
		Union(v , u);
		vector<int> vec;
		for(int j = 1 ; j <= n ; j++){
			if(Find(j) == j){
				vec.push_back(sz[j]);
			}
		}
		sort(all(vec) , greater<int>());
		int sum = 0 , cnt = SZ(vec) - (n - i) + 1;
		for(int j = 0 ; j < cnt ; j++)	sum += vec[j];
		cout << sum - 1 << endl;
	}

    return 0;
}
/*

*/