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

ll a[Maxn];
ll cnt[Maxn][30];

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	str s;
	cin >> s;
	ll n = s.size();
	for(int i = 0; i < n; i++) a[i] = s[i] - 'a';
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < 26; j++)
			cnt[i][j] = cnt[i - 1][j] + (a[i - 1] == j);
	
	ll q;
	cin >> q;
	ll l, r;
	for(int i = 0; i < q; i++){
		cin >> l >> r;
		l --;
		ll d = 0;
		for(int j = 0; j < 26; j++) if(cnt[l][j] != cnt[r][j]) d ++;
		if(r - l == 1){
			cout << "Yes\n";
			continue;
		}
		if(s[l] != s[r - 1]){
			cout << "Yes\n";
			continue;
		}
		if(d > 2){
			cout << "Yes\n";
		} else cout << "No\n";
		
	}
	
	return 0;
}