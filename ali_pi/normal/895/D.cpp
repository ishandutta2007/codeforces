#include<bits/stdc++.h>

#define LL long long
using namespace std;
const int N = 1e6 + 5;
const LL M = 1e9 + 7;
using namespace std;

string a, b;
LL c[26], t[26], f[N] = { 1 }, tmp, k, sm, n, m;

LL pw(LL x, LL y) { 
    return y ? (y & 1 ? x*pw(x, y - 1) % M : pw(x*x%M, y >> 1)) : 1; }
LL find(string s) {
	sm = 0, k = 1;
	memcpy(t,c,sizeof t);
	for (int i = 0; i < n; i++) {
		tmp = 0; m = s[i] - 'a';
		for (int j = 0; j < m; j++)tmp += t[j];
		sm += tmp*f[n - i - 1] % M*k%M; sm %= M;
		if (!t[m])break;
		k = k*t[m]-- % M;
	}
	for (int i = 0; i < 26; i++)
		sm = sm* pw(f[c[i]], M - 2) % M;
	return sm;
}
int main() {
	for (int i = 1; i < N; i++)f[i] = f[i - 1] * i%M;
	cin >> a >> b; n = a.size();
	for (auto i : a)c[i - 'a']++;
	cout << (find(b) - find(a) + M - 1) % M;
}