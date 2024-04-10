#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll Mod = 998244353;
ll qpow(ll b, ll p){
	ll ret = 1LL;
	while(p){
		if(p & 1)
			ret = ret * b % Mod;
		b = b * b % Mod;
		p >>= 1;
	}
	return ret;
}

int T;
int n;
string s;
ll fact[100100];
ll invfact[100100];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	fact[0] = 1;
	rep(i, 100000)
		fact[i + 1] = fact[i] * (i + 1) % Mod;
	rep(i, 100001)
		invfact[i] = qpow(fact[i], Mod - 2);
	while(T--){
		cin >> n;
		cin >> s;
		int cnt2 = 0, cnt0 = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == '1' && i + 1 < n && s[i + 1] == '1'){
				cnt2++;
				i++;
			} else if(s[i] == '0'){
				cnt0++;
			}
		}
		cout << fact[cnt2 + cnt0] * invfact[cnt2] % Mod * invfact[cnt0] % Mod << endl;
	}
	return 0;
}