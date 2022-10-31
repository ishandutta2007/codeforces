#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 100005
#define INF 101111111111111
using namespace std;
vector<pll> m, w;
void die(){
	cout << 0;
	exit(0);
}
ll dp[N][2];
int main(){
	FAST;
	string s;
	cin >> s;
	ll n = s.length();
	for(ll i = 0;i<n;i++){
		if(s[i] == 'm' || s[i] == 'w') die();
		if(s[i] == 'u' && i > 0 && s[i-1] == 'u'){
			if(w.size() == 0) w.pb({i-1, i});
			else{
				if(w[w.size()-1].y == i-1) w[w.size()-1].y++;
				else w.pb({i-1, i});
			}
		}
		if(s[i] == 'n' && i > 0 && s[i-1] == 'n'){
			if(m.size() == 0) m.pb({i-1, i});
			else{
				if(m[m.size()-1].y == i-1) m[m.size()-1].y++;
				else m.pb({i-1, i});
			}
		}
	}
	ll maxl = 0;
	for(auto i : w) maxl = max(maxl, i.y-i.x+1);
	for(auto i : m) maxl = max(maxl, i.y-i.x+1);
	dp[1][0] = 1;
	dp[2][0] = 1;
	dp[2][1] = 1;
	for(ll j = 3;j<=maxl;j++){
		dp[j][0] = dp[j-1][0] + dp[j-1][1];
		dp[j][1] = dp[j-1][0];
		dp[j][0] %= M;
	}
	ll res = 1;
	for(auto i : w) res = (res * ((dp[i.y-i.x+1][0] + dp[i.y-i.x+1][1])%M))%M;
	for(auto i : m) res = (res * ((dp[i.y-i.x+1][0] + dp[i.y-i.x+1][1])%M))%M;
	cout << res;
}