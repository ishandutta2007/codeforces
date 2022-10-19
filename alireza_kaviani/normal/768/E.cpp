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
const ll LOG = 70;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , xr;
map<ll , int> gr[LOG];

int solve(int n , ll x){
	if(n == 0)	return 0;
	if(gr[n].find(x) != gr[n].end())	return gr[n][x];
	vector<int> mark(LOG , 0);
	for(int i = 1 ; i <= n ; i++){
		if(x & (1ll << i))	continue;
		mark[solve(n - i , x + (1ll << i))] = 1;
	}
	for(int i = 0 ; i < LOG ; i++){
		if(!mark[i]){
			gr[n][x] = i;
			break;
		}
	}
	return gr[n][x];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	while(n--){
		int x;
		cin >> x;
		xr ^= solve(x , 0);
	}
	cout << (xr == 0 ? "YES" : "NO") << endl;

    return 0;
}
/*

*/