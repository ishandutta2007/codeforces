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
const int Maxn = 1e2 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

str w = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

str s[Maxn];
char a[Maxn][Maxn];

int MAIN(){
	ll r, c, k;
	cin >> r >> c >> k;
	for(int i = 0; i < r; i++) cin >> s[i];
	ll cnt = 0;
	for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) cnt += (s[i][j] == 'R');
	
	ll nd = cnt / k;
	ll md = cnt % k;
	int p = 0;
	ll hv = 0;
	for(int i = 0; i < r; i++){
		if(i % 2==0)
		for(int j = 0; j < c; j++){
			if(p == k) p --;
			a[i][j] = w[p];
			if(s[i][j] == 'R') hv ++;
			if((p >= md && hv == nd) || (p < md && hv == nd + 1)) p++, hv = 0;
		}
		else
		for(int j = c - 1; j >= 0; j--){
			if(p == k) p --;
			a[i][j] = w[p];
			if(s[i][j] == 'R') hv ++;
			if((p >= md && hv == nd) || (p < md && hv == nd + 1)) p++, hv = 0;
		}
	}
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++) cout << a[i][j]; cout << '\n';
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//cerr << w.size();
	ll T;
	cin >> T;
	while(T--) MAIN();
	return 0;
}