#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll Mod = 998244353;
ll qpow(ll b, ll p){
	ll ret = 1;
	while(p){
		if(p & 1)
			ret = ret * b % Mod;
		b = b * b % Mod;
		p >>= 1;
	}
	return ret;
}

int n, m;
int s[200200], t[200200];
int cnt[200200];
ll fact[200200], invfact[200200];
ll nowval = 1;
ll bit[200200];
void update(int pos, ll val){
	if(!pos)
		return ;
	while(pos <= 200001){
		bit[pos] = (bit[pos] + val) % Mod;
		pos += pos & -pos;
	}
}
ll query(int pos){
	ll ret = 0;
	while(pos > 0){
		ret = (ret + bit[pos]) % Mod;
		pos -= pos & -pos;
	}
	return ret;
}

int main(){
	fact[0] = 1;
	for(int i = 1; i <= 200000; i++)
		fact[i] = fact[i - 1] * i % Mod;
	invfact[200000] = qpow(fact[200000], Mod - 2);
	for(int i = 200000; i >= 1; i--)
		invfact[i - 1] = invfact[i] * i % Mod;
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, n)
		cin >> s[i];
	rep(i, m)
		cin >> t[i];
	rep(i, n)
		cnt[s[i]]++;
	nowval = fact[n];
	rep(i, 200001)
		nowval = nowval * invfact[cnt[i]] % Mod;
	rep(i, 200002)
		update(i, cnt[i]);
	ll ans = 0;
	rep(i, m){
		if(i == n){
			ans = (ans + 1) % Mod;
			break;
		}
		int x = t[i];
		nowval = nowval * qpow(n - i, Mod - 2) % Mod;
//		cout << i << ": " << query(x - 1) << " * " << nowval << endl;
		ans = (ans + query(x - 1) * nowval) % Mod;
//		cout << nowval << " *= " << cnt[x] << endl;
		nowval = nowval * cnt[x] % Mod;
		cnt[x]--;
		if(cnt[x] < 0)
			break;
		update(x, -1);
	}
	cout << ans << endl;
	return 0;
}