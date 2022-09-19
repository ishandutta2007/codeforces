// vaziat meshki-ghermeze !
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

// const ll Mod = 1000000007LL;
const int N = 4e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll dp[N];
// vector<int> V[N];
int g[N];

vector<int> dv;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = 2; i < N; i++){
		if(g[i] != 0) continue;
		for(int j = i; j < N; j += i)
			g[j] = i;
	}
	dp[1] = 1;
	dp[0] = 0;
	ll Sum = 1;
	ll Sd = 0;

	int n;
	ll Mod;
	cin >> n >> Mod;
	for(int i = 2; i <= n; i++){
		dv.clear();
		dv = {1};
		int y = i;
		while(y > 1){
			int pr = g[y];
			int cnt = 0;
			// int tmp = i;
			while(y % pr == 0) y /= pr, cnt ++;
			int sz = dv.size();
			for(int i = 0; i < sz; i++){
				for(int j = 1, pw = pr; j <= cnt; j++, pw *= pr)
					dv.pb(pw * dv[i]);
			}
		}
		// cerr << "!! " << i << ' ';
		// for(auto x : dv) cerr << x << ' ';
		// cerr << '\n'; 
		for(auto x : dv){
			if(x == 1) continue;
			Sd = Sd - dp[(i - 1)/x] + dp[i / x];
		}
		Sd %= Mod;
		// debug(Sd);
		dp[i] = Sd + Sum;
		Sum += dp[i];
		Sum %= Mod;
		// Sd += 1;
	}
		// debug(dp[2]);
		// debug(dp[3]);
	cout << ((dp[n] % Mod) + Mod) % Mod << '\n';
	return 0;
}