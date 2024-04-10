// har ki ro didi goft mikhad beshe meslemon !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int n, m, k;
int con(str X){
	int res = 0;
	for(int i = 0; i < k; i++)
		res |= ((X[i] - '0') << i);
	return res;
}
int swp(int num, int x, int y){
	int res = 0;
	for(int i = 0; i < k; i++){
		if(i != x && i != y && (num >> i &1))
			res |= (1 << i);
		if(i == x && (num >> y & 1))
			res |= (1 << i);
		if(i == y && (num >> x & 1))
			res |= (1 << i);	
	}
	return res;
}
int ps1[N], ps2[N], p[N];
int mn[N], mx[N];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	iota(p, p + N, 0);
	cin >> n >> m >> k;
	str S; cin >> S;
	ps1[0] = con(S);
	cin >> S;
	ps2[0] = con(S);
	int a, b;
	for(int i = 1; i <= n; i++){
		cin >> a >> b;
		a--; b--;
		ps1[i] = swp(ps1[i - 1], p[a], p[b]);
		ps2[i] = swp(ps2[i - 1], p[a], p[b]);
		swap(p[a], p[b]);
		// debug(ps1[i]);
		// debug(ps2[i]);
	}
	fill(mn, mn + N, Inf);
	for(int i = 0; i <= n; i++) mn[ps1[i]] = min(mn[ps1[i]], i);
	fill(mx, mx + N, -Inf);
	for(int i = 0; i <= n; i++) mx[ps2[i]] = max(mx[ps2[i]], i);
	int ans = -1, l = -1, r = -1;
	for(int i = (1 << k) - 1; i >= 0; i--){
		for(int j = 0; j < k; j++){
			if(i >> j & 1){
				mn[i ^ (1 << j)] = min(mn[i ^ (1 << j)], mn[i]);
				mx[i ^ (1 << j)] = max(mx[i ^ (1 << j)], mx[i]);
			}
		}
		if(mx[i] - mn[i] >= m && __builtin_popcount(i) > ans){
			ans = __builtin_popcount(i);
			l = mn[i] + 1;
			r = mx[i];
		}
	}
	// debug(ans);
	// debug(ps1[0]);
	// debug(ps2[0]);
	// debug(__builtin_popcount(ps1[0])+__builtin_popcount(ps2[0]) - 2*ans);
	// debug(k);
	cout << k - (__builtin_popcount(ps1[0])+__builtin_popcount(ps2[0]) - 2*ans) << '\n' << l << ' ' << r << '\n';
	return 0;
}