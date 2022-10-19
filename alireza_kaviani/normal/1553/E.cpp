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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , m , A[MAXN] , cnt[MAXN] , par[MAXN] , sz[MAXN];

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

	cin >> q;
	while(q--){
		cin >> n >> m;
		fill(cnt , cnt + n + 10 , 0);
		for(int i = 1 ; i <= n ; i++){
			cin >> A[i];
			cnt[(A[i] + n - i) % n]++;
		}
		vector<int> ans;
		for(int i = 0 ; i < n ; i++){
			if(cnt[i] < n / 3)	continue;
			fill(par , par + n + 10 , -1);
			fill(sz , sz + n + 10 , 1);
			for(int j = 1 ; j <= n ; j++){
				int pos = (j + i - 1) % n + 1;
				Union(pos , A[j]);
			}
			int cur = 0;
			for(int j = 1 ; j <= n ; j++){
				if(Find(j) == j){
					cur += sz[j] - 1;
				}
			}
			if(cur <= m){
				ans.push_back((n - i) % n);
			}
		}
		sort(all(ans));
		cout << SZ(ans) << sep;
		for(int i : ans)	cout << i << sep;
		cout << endl;
	}

    return 0;
}
/*

*/