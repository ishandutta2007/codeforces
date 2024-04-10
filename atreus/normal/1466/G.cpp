#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll maxn = 1e5 + 10;
const ll mod = 1e9 + 7;
const int maxlen = 1e6 + 10;

int par[maxn][28], pw[maxn], revpw[maxn];
int f[4*maxlen];

int kmp;

int occur(string &s, string &t){
	int n = s.size(), m = t.size();
	f[0] = f[1] = 0;
	int k = 0;
	for (int i = 1; i < m; i++){
		while (k > 0 and t[i] != t[k])
			k = f[k];
		k += (t[i] == t[k]);
		f[i+1] = k;
	}
	int ret = 0;
	k = 0;
	for (int i = 0; i < n; i++){
		while (k > 0 and s[i] != t[k])
			k = f[k];
		k += (s[i] == t[k]);
		if (k == m){
			ret ++;
			k = f[k];
		}
	}
	kmp = k;
	return ret;
}

int power(int a, int b){
	if (b == 0)
		return 1;
	int ret = power(a,b/2);
	ret = 1LL*ret*ret % mod;
	if (b & 1)
		ret = 1LL * ret * a % mod;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	pw[0] = 1;
	for (int i = 1; i <= n; i++)
		pw[i] = 2LL*pw[i-1] % mod;
	revpw[n] = power(pw[n],mod-2);
	for (int i = n-1; i >= 0; i--)
		revpw[i] = 2LL*revpw[i+1]%mod;
	string s0, t;
	cin >> s0 >> t;
	for (int i = n; i >= 1; i--){
		for (int j = 0; j < 26; j++)
			par[i][j] = par[i+1][j];
		int alph = (int)(t[i-1]-'a');
		par[i][alph] = (par[i][alph]+pw[n-i]) % mod;
	}
	while (q--){
		int siren;
		string w;
		cin >> siren >> w;
		string s = s0;
		int i;
		for (i = 1; i <= siren and s.size() < w.size(); i++)
			s = s + t[i-1] + s;
		i--;
		int A = occur(s,w);
		if (i == siren){
			cout << A << '\n';
			continue;
		}
		int answer = 1LL*A*pw[siren-i] % mod;
		for (char c = 'a'; c <= 'z'; c++){
			int diff = 0;	
			int k = kmp;
			while (k > 0 and w[k] != c)
				k = f[k];
			k += (w[k] == c);
			if (k == (int)w.size())
				diff++, k = f[k];
			for (int i = 0; i+1 < (int)w.size(); i++){
				while (k > 0 and w[k] != s[i])
					k = f[k];
				k += (w[k] == s[i]);
				if (k == (int)w.size())
					diff++, k = f[k];
			}
			string tmp = s + c + s;
			int alph = (int)c - 'a';
			int num = 1LL*(par[i+1][alph]-par[siren+1][alph]+mod)*revpw[n-siren] % mod;
			answer = (answer + 1LL*diff*num) % mod;
		}
		cout << answer << '\n';
	}
}