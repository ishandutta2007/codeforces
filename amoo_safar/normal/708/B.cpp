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
const int Maxn = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;
const ll Base = 101;

void SIK(){
	cout << "Impossible";
	exit(0);
}

ll C2(ll n){
	return n * (n - 1) / 2LL;
}

ll get(ll x){
	for(int i = 1; i <= 1000000; i++) if(C2(i) == x) return i;
	SIK();
}
void print(int cnt, char x){
	for(int i =0; i < cnt; i++) cout << x;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll c00, c01, c10, c11;
	cin >> c00 >> c01 >> c10 >> c11;
	ll g1 = get(c11);
	ll g0 = get(c00);
	if(c01 + c10 == 0){
		if(c11 > 0 && c00 > 0) SIK(); 
		if(c11){
			for(int i = 0; i < g1; i++) cout << '1';
			return 0;
		}
		if(c00){
			for(int i = 0; i < g0; i++) cout << '0';
			return 0;
		}
		cout << '1';
		return 0;
	}
	if(g1 * g0 != c10 + c01) SIK();
	
	if(c10 % g1 == 0){
		print(g0 - (c10/g1), '0');
		print(g1, '1');
		print(c10/g1, '0');
	} else {
		print(g0 - (c10/g1) - 1, '0');
		print(c10 % g1, '1');
		print(1, '0');
		print(g1 - (c10 % g1), '1');
		print(c10/g1, '0');
	}
	return 0;
}