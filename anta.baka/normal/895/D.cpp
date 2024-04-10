#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int maxn = 1e6;

int fac[maxn + 1], invfac[maxn + 1], inv[maxn + 1];

inline int add(int a, int b) {
    a += b;
    if(a >= mod) a -= mod;
    return a;
}

inline int mul(int a, int b) {
    return (ll)a * b % mod;
}

inline int sub(int a, int b) {
    a -= b;
    if(a < 0) a += mod;
    return a;
}

inline int pw (int a, int n) {
	int res = 1;
	while(n) {
		if(n & 1) res = mul(res, a);
        a = mul(a, a);
		n >>= 1;
	}
	return res;
}

inline int cnk(int n, int k) {
    return mul(mul(fac[n], invfac[k]), invfac[n - k]);
}

int suff[26];
string s1, s2;

inline int f(string &s) {
    vector<int> cnt(26, 0);
    for(char x : s1) cnt[x - 'a']++;
    ll ret = 0;
    for(int i = 0; i < s.size(); i++) {
        int ch = s[i] - 'a';
        suff[25] = cnt[25];
        int m = 1;
        for(int j = 24; j >= 0; j--) {
            suff[j] = cnt[j] + suff[j + 1];
            m = mul(m, cnk(suff[j], cnt[j]));
        }
        for(int j = 0; j < ch; j++) {
            if(cnt[j]) ret = add(ret, mul(m, mul(cnt[j], inv[suff[j]])));
            m = mul(m, mul(inv[suff[j]], sub(suff[j], cnt[j])));
        }
        if(cnt[ch] == 0) break;
        cnt[ch]--;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fac[0] = invfac[0] = 1;
    for(int i = 1; i <= maxn; i++) {
        fac[i] = mul(fac[i - 1], i);
        invfac[i] = pw(fac[i], mod - 2);
        inv[i] = pw(i, mod - 2);
    }
    cin >> s1 >> s2;
    cout << sub(sub(f(s2), f(s1)), 1);
}