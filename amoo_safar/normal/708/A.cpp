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


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	str s;
	cin >> s;
	n = s.size();
	s = s + '!';
	int ind = n - 1;
	for(int i = n - 1; i >= 0; i--) if(s[i] != 'a') ind = i;
	for(int i = ind; i < n; i++){
		s[i] = (s[i] == 'a' ? 'z' : s[i] - 1);
		if(s[i + 1] == 'a') break;
	}
	cout << s.substr(0, n);
	return 0;
}