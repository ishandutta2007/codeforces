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
const int Maxn = 4e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll a[Maxn], b[Maxn];;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k;
	cin >> n >> k;
	str s;
	cin >> s;
	for(int i = 0; i < n; i++){
		a[i] = s[i] - '0';
		b[i] = a[i];
	}
	for(int i = k; i < n; i++) b[i] = b[i - k];
	
	ll fl = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == b[i]) continue;
		if(a[i] > b[i]){
			fl = 1;
			break;
		} else {
			break;
		}
	}
	if(fl) a[k - 1] ++;
	for(int i = k - 1; i >= 0; i--){
		if(a[i] == 10){
			a[i] = 0;
			a[i-1] ++;
		}
	}
	for(int j = k; j < n; j++) a[j] = a[j - k];
	cout << n << '\n';
	
	for(int i = 0; i < n; i++) cout << a[i];
	
	return 0;
}