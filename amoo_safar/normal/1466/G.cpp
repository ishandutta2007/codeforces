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
const int N = 1e6 + 10;
const int N2 = 5e5 + 10;
const ll Inf = 2242545357980376863LL;
const int Log = 23;

ll iv2 = (Mod + 1) / 2;
ll iv[N], ln[N];
const int Sig = 30;
ll cnt[N2][Sig];


ll mul(ll a, ll b){
	return (a * b) % Mod;
}

bitset<1000010> pr[Log + 2], sf[Log + 2];
ll p2[N];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// debug(pr[30][3]);
	iv[0] = 1;
	for(int i = 1; i < N; i++)
		iv[i] = mul(iv[i - 1], iv2);
	p2[0] = 1;
	for(int i = 1; i < N; i++)
		p2[i] = mul(p2[i - 1], 2);
	
	int n, q;
	cin >> n >> q;
	str s, t;
	cin >> s >> t;
	
	while(n < Log + 2){
		n ++;
		t += "a";
	}

	int m = s.size();
	ln[0] = s.size();
	for(int i = 1; i < Log; i++) ln[i] = (ln[i - 1] * 2ll + 1);

	ll z = 1;
	for(int i = n - 1; i >= 0; i--){
		memcpy(cnt[i], cnt[i + 1], sizeof cnt[i + 1]);
		(cnt[i][t[i] - 'a'] += z) %= Mod;
		z = mul(z, 2);
	}

	str r;
	for(int qi = 0; qi < q; qi++){
		int k, id;
		cin >> id;
		cin >> r;
		k = r.size();
		assert(k < N);

		ll ans = 0;

		for(int j = 0; j <= k; j++){
			int fl = 1;
			for(int y = 1; y <= m; y++){
				if(j >= y && r[j - y] != s[m - y]) fl = 0;
			}
			pr[0][j] = fl;
		}
		for(int j = 0; j <= k; j++){
			int fl = 1;
			for(int y = 0; y < m; y++){
				if(j + y < k && r[j + y] != s[y]) fl = 0;
			}
			sf[0][j] = fl;
		}
		for(int i = 1; i < Log; i++){
			for(int j = 0; j <= k; j++){
				pr[i][j] = pr[i - 1][j];
				if(ln[i - 1] < j)
					pr[i][j] = (pr[i][j] == 1) && (pr[i - 1][j - ln[i - 1] - 1] && (t[i - 1] == r[j - ln[i - 1] - 1]));
				
				sf[i][j] = sf[i - 1][j];
				if(j + ln[i - 1] < k)
					sf[i][j] = (sf[i][j] == 1) && (sf[i - 1][j + ln[i - 1] + 1] && (t[i - 1] == r[j + ln[i - 1]]));
			}
		}

		for(int j = 0; j < k; j++){
			for(int d = 1; d <= min(id, Log - 1); d++){
				if(j > ln[d - 1]) continue;
				if(k - j - 1 > ln[d - 1]) continue;
				if(!pr[d - 1][j]) continue;
				if(!sf[d - 1][j + 1]) continue;
				ans += mul(cnt[d - 1][r[j] - 'a'] - cnt[id][r[j] - 'a'], iv[n - id]);
				ans %= Mod;
				// cerr << "! " << j << ' ' << d << ' ' << iv[n - id] << '\n';
				// debug(cnt[d - 1][r[j] - 'a']);
				break;
			}
		}
		if(k <= m){
			for(int j = k - 1; j < m; j++){
				if(s.substr(j - k + 1, k) == r)
					ans = (ans + p2[id]) % Mod;
			}
		}
		cout << (ans+Mod) % Mod << '\n';
	}


	return 0;
}
/*
3 1
aa
bcd
20 aba

*/