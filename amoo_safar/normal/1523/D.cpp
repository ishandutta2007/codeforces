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

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const int Log = 15;

ll A[N];
str S[N];
int sub[(1 << Log) + 10];

int Get(ll x){
	return __builtin_popcountll(x);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n, m, p;
	cin >> n >> m >> p;
	uniform_int_distribution<> Amoo(1, n);

	for(int i = 1; i <= n; i++){
		cin >> S[i];
		for(int j = 0; j < m; j++)
			if(S[i][j] == '1')
				A[i] |= (1ll << j);
	}
	int rq = (n + 1) / 2;
	int tof = 40;
	ll ans = 0;
	for(int it = 0; it < tof; it++){
		int id = Amoo(rng);
		vector<int> b;
		for(int i = 0; i < m; i++)
			if(S[id][i] == '1')
				b.pb(i);
		memset(sub, 0, sizeof sub);
		for(int i = 1; i <= n; i++){
			ll ad = A[i] & A[id];
			ll res = 0;
			int cnt = 0;
			for(auto x : b){
				if(ad >> x & 1)
					res |= (1 << cnt);
				cnt ++;
			}
			// debug(res);
			sub[res] ++;
		}
		for(int j = 0; j < Log; j++){
			for(int i = 0; i < (1 << Log); i++)
				if(i >> j & 1)
					sub[i ^ (1 << j)] += sub[i];
		}
		// debug(sub[9]);
		// debug(rq);
		for(int i = 0; i < (1 << Log); i++)
			if(sub[i] >= rq && Get(i) > Get(ans)){
				ans = 0;
				for(int j = 0; j < (int) b.size(); j++){
					if(i >> j & 1)
						ans |= (1ll << b[j]);
				}
			}
	}
	for(int i = 0; i < m; i++){
		cout << ans%2;
		ans /= 2;
	}
	cout << '\n';
	return 0;
}