
// nemibinam invara kasi mesle khodemono !
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
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll nx[N*Log][2], la = 0;
ll dp[N*Log];

void Add(ll x){
	int nw = 0;
	for(int i = Log - 1; i >= 0; i--){
		if(x >> i & 1){
			if(nx[nw][1] == -1){
				nx[nw][1] = la + 1;
				la ++;
			}
			nw = nx[nw][1];
		} else {
			if(nx[nw][0] == -1){
				nx[nw][0] = la + 1;
				la ++;
			}
			nw = nx[nw][0];
		}
	}
}
void Solve(int x){
	if(x == -1) return;
	if(nx[x][0] == -1 && nx[x][1] == -1){
		dp[x] = 1;
		return ;
	}
	Solve(nx[x][0]);
	Solve(nx[x][1]);

	if(nx[x][1] != -1)
		dp[x] = max(dp[x], dp[nx[x][1]] + (nx[x][0] == -1 ? 0 : 1));
	if(nx[x][0] != -1)
		dp[x] = max(dp[x], dp[nx[x][0]] + (nx[x][1] == -1 ? 0 : 1));
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(nx, -1, sizeof nx);
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++){
		ll v;
		cin >> v;
		Add(v);
	}
	Solve(0);
	cout << n - dp[0] << '\n';
	return 0;
}