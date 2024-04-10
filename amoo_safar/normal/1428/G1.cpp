// I'll Crush you !
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
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll dp[N], mx[N];
ll k, f[N];
ll z[N];

typedef pair<int, ll> pil;

deque<pil> dq;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> k;

	for(int i = 0; i < 6; i++) cin >> f[i];
	
	if(k == 1){	
		ll q;
		cin >> q;
		ll v;
		for(int i = 0; i < q; i++){
			cin >> v;
			ll res = 0;
			for(int t = 0; t < 6; t++){
				int x = v%10; v/= 10;
				if(x % 3 == 0) res += f[t] * (x/3);
			}
			cout << res << '\n';
		}

		return 0;
	}
	for(int i = 0; i <= 18; i++){
		if(i <= 9) z[i] = (i / 3);
		else {
			z[i] = (i % 3 == 0 ? i/3 : 3);
		}
	}

	fill(dp, dp + N, -Inf);
	dp[0] = 0;
	for(int t = 0, pw = 1; t < 6; t++, pw *= 10){
		//debug(t);
		// fill mx
		int st = 9*pw;
		for(int md = 0; md < st; md ++){
			//debug(md);
			while(!dq.empty()) dq.pop_back();

			for(int i = md, p = 0; i < N; i += st, p++){
				//debug(i);
				while((!dq.empty()) && (dp[i] > dq.back().S + 3ll * f[t] * (p - dq.back().F)))
					dq.pop_back();
				//debug(i);
				while((!dq.empty()) && (p - dq.front().F > k - 2))
					dq.pop_front();
				//debug(i);
				dq.pb({p, dp[i]});
				mx[i] = dq.front().S + 3ll * f[t] * (p - dq.front().F);
			}
		}
		// fill dp
		for(int i = 0; i < N; i++){
			dp[i] = -Inf;
			for(int j = 0; j <= 18; j++){
				if(j * pw > i) break;
				dp[i] = max(dp[i], mx[i - j*pw] + z[j] * f[t]);
			}
		}
	}
	ll q;
	cin >> q;
	ll v;
	for(int i = 0; i < q; i++){
		cin >> v;
		cout << dp[v] << '\n';
	}

	return 0;
}
/*
1
1 2 3 4 5 6
3
57
319
23

*/