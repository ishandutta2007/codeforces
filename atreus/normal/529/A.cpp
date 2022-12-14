#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e6 + 10;
const int mod = 1e9 + 9;
const int base = 11;

string s;
int n;
int hsh[maxn], pw[maxn];
int pm[maxn], sm[maxn], a[maxn];

int get_hsh(int f, int len){
	int s = f + len - 1;
	if (f == 0)
		return hsh[s];
	return (hsh[s] - 1ll * hsh[f-1] * pw[len] % mod + mod) % mod; 
}

int get_min(int v, int u, int times = 0){
	if (v > u)
		return 1 ^ get_min(u, v, times);
	int lo = 0, hi = n - u + 1;
	while (hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if (get_hsh(v, mid) == get_hsh(u, mid))
			lo = mid;
		else
			hi = mid;
	}
	if (lo != n - u)
		return (s[v + lo] == '(');
	if (times == 3)
		return true;
	v = (v + lo) % n, u = (u + lo) % n;
	return get_min(v, u, times + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++)
		a[i] = (i > 0 ? a[i - 1] : 0) + (s[i] == '(') - (s[i] == ')');
	int tot = a[n - 1];
	for (int i = 0; i < n; i++)
		pm[i] = min((i > 0 ? pm[i - 1] : n), a[i]);
	for (int i = n - 1; i >= 0; i--)
		sm[i] = min((i < n-1 ? sm[i + 1] : n), a[i]);
	vector<int> candid;
	for (int i = 0; i < n; i++){
		int mnm;
		if (i == 0)
			mnm = sm[0];
		else
			mnm = min(sm[i] - a[i - 1], pm[i - 1] + (a[n - 1] - a[i - 1]));
		if (tot >= 0){
			if (mnm >= 0)
				candid.push_back(i);
		}
		else{
			if (mnm == tot)
				candid.push_back(i);
		}
	}
	pw[0] = 1;
	for (int i = 1; i < n; i++)
		pw[i] = 1ll * pw[i - 1] * base % mod;
	if (s[0] == '(')
		hsh[0] = 1;
	else
		hsh[0] = 2;
	for (int i = 1; i < n; i++)
		hsh[i] = (1ll * hsh[i - 1] * base + 1 + (s[i] == ')')) % mod;
	int m = candid.size();
	while (candid.size() > 1){
		int i = candid[m - 1], j = candid[m - 2];
		m --;
		candid.pop_back(), candid.pop_back();
		if (get_min(i, j) == true)
			candid.push_back(i);
		else
			candid.push_back(j);
	}
	int st = candid[0];
	if (tot < 0)
		for (int i = 0; i < abs(tot); i++)
			cout << '(';
	for (int i = st; i < n; i++)
		cout << s[i];
	for (int i = 0; i < st; i++)
		cout << s[i];
	if (tot > 0)
		for (int i = 0; i < tot; i++)
			cout << ')';
	cout << endl;
}