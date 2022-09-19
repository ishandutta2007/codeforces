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

const ll Mod = 998244353;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;
const ll Base = 101;

ll ps[N];
ll mul(ll a, ll b){
	return (a * b) % Mod;
}
ll ph[N];
ll cnt[N];
ll sh[N], pw[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	pw[0] = 1;
	for(int i = 1; i < N; i++){
		pw[i] = mul(pw[i - 1], Base);
	}
	ll n;
	cin >> n;
	str t;
	cin >> t;
	//ll n = t.size();
	t = '#' + t;
	for(int i = 2; i <= n; i++) ps[i] = ps[i - 1] + (t[i] == '1' && t[i - 1] == '1');
	ph[0] = 0;
	for(int i = 1; i <= n; i++) ph[i] = (mul(ph[i - 1], Base) + t[i]) % Mod;
	for(int i = 1; i <= n; i++) cnt[i] = cnt[i - 1] + (t[i] == '0');
	ll x = 13;
	for(int i = 1; i <= n; i++){
		if(t[i] == '1') sh[i] = sh[i - 1];
		else {
			if(i % 2 == 0) sh[i] = (mul(sh[i - 1], Base) + x + Mod) % Mod;
			else sh[i] = (mul(sh[i - 1], Base) - x + Mod) % Mod;
		}
	}
	ll q;
	cin >> q;
	ll l1, l2, ln;
	for(int i = 0; i < q; i++){
		cin >> l1 >> l2 >> ln;
		ll f1 = ((ps[l1 + ln - 1] - ps[l1]) > 0);
		ll f2 = ((ps[l2 + ln - 1] - ps[l2]) > 0);
		ll H1 = (ph[l1 + ln - 1] - mul(ph[l1 - 1], pw[ln]) + Mod) % Mod;
		ll H2 = (ph[l2 + ln - 1] - mul(ph[l2 - 1], pw[ln]) + Mod) % Mod;
		ll S1 = (sh[l1 + ln - 1] - mul(sh[l1 - 1], pw[cnt[l1 + ln - 1] - cnt[l1 - 1]]) + Mod) % Mod;
		ll S2 = (sh[l2 + ln - 1] - mul(sh[l2 - 1], pw[cnt[l2 + ln - 1] - cnt[l2 - 1]]) + Mod) % Mod;
		if(l1 % 2 != l2 % 2){
			S1 = -S1;
			S1 += Mod;
			S1 %= Mod;
		}
		if(min(f1, f2) == 0){
			cout << (H1 == H2 ? "Yes\n" : "No\n");
			continue;
		}
		cout << (S1 == S2 ? "Yes\n" : "No\n");
	}
	return 0;
}