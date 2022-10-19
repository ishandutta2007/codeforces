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

int n , m , q , ans , inDeg[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m;
	for(int i = 0 ; i < m ; i++){
		int v , u;
		cin >> v >> u;
		if(v > u)	swap(v , u);
		inDeg[v]++;
	}
	for(int i = 1 ; i <= n ; i++)	ans += (inDeg[i] == 0);
	cin >> q;
	while(q--){
		int type , v , u;
		cin >> type;
		if(type == 3){
			cout << ans << endl;
			continue;
		}
		cin >> v >> u;
		if(v > u)	swap(v , u);
		ans -= (inDeg[v] == 0);
		inDeg[v] += (type == 1 ? 1 : -1);
		ans += (inDeg[v] == 0);
	}

    return 0;
}
/*

*/