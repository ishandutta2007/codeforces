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
const int Maxn = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	if(n == 1 && m == 1){
		return cout << "0", 0;
	}
	if(n == 1){
		for(int i = 1; i <= m;i ++) cout <<i + 1 << ' ';
		return 0;
	}
	if(m == 1){
		for(int i = 1; i <= n; i++) cout << i + 1 << '\n';
		return 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = n + 1; j <= n + m; j++)
			cout << i * j << ' ';
		cout << '\n';
	}
	
	return 0;
}