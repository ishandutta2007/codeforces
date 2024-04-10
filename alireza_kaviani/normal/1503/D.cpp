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

int n , ans , match[MAXN] , ind[MAXN] , mark[MAXN];
vector<int> vec;

void solve(vector<int> vec){
	ll cur = 0;
	for(int i : vec)	cur += (ind[i] == 1);
	ans += min(cur , SZ(vec) - cur);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 0 ; i < n ; i++){
		int v , u;
		cin >> v >> u;
		match[u] = v;
		match[v] = u;
		ind[v] = 1; ind[u] = 2;
	}
	int cnt = 0 , cur = 0 , mx = 0;
	for(int i = 1 ; i <= n + n ; i++){
		if(mark[i]){
			cur++;
			continue;
		}
		if(cnt == cur){
			solve(vec);
			vec.clear();
		}
		mark[i] = 1; mark[match[i]] = 2; vec.push_back(i); cnt++; cur++;
		//cout << i << sep << match[i] << endl;
		int r = n + n + 1;
		for(int j = match[i] + 1 ; j <= n + n ; j++){
			if(mark[j] == 2){
				if(j < match[j])	return cout << -1 << endl , 0;
				r = j;
				break;
			}
			if(j < match[j])	return cout << -1 << endl , 0;
		}
		for(int j = r - 1 ; j > match[i] ; j--){
			if(match[j] < mx)	return cout << -1 << endl , 0;
			mx = match[j];
			mark[j] = 1;
			mark[match[j]] = 2;
			vec.push_back(j); cnt++;
		}
	}
	solve(vec);
	cout << ans << endl;

    return 0;
}
/*

*/