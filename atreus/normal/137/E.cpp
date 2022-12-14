#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;

int n, par[maxn], fen[maxn];
map<char, int> vowel;

int get(int val, int idx){
	int now = 0;
	for (int i = 20; i >= 0; i--){
		if (now + (1 << i) > n + 1)
			continue;
		if (val < fen[now + (1 << i)])
			now += (1 << i);
	}
	return idx - now;
}

void add(int idx, int val){
	idx ++;
	for (; idx <= n + 1; idx += idx & -idx)
		fen[idx] = min(fen[idx], val);
}

int main(){
	ios_base::sync_with_stdio(false);
	memset(fen, 63, sizeof fen);
	string s;
	cin >> s;
	n = s.size();
	vowel['A'] = vowel['a'] = vowel['O'] = vowel['o'] = vowel['E'] = vowel['e'] = vowel['U'] = vowel['u'] = vowel['I'] = vowel['i'] = 1;
	for (int i = 1; i <= n; i++){
		if (vowel[s[i - 1]] == 1)
			par[i] = -1;
		else
			par[i] = 2;
		par[i] += par[i - 1];
	}
	int mx = -1;
	add(0, 0);
	for (int i = 1; i <= n; i++){
		if (par[i] >= 0)
			mx = i;
		else
			mx = max(mx, get(par[i], i));
		add(i, par[i]);
	}
	if (mx == -1)
		return cout << "No solution\n", 0;
	cout << mx << " ";
	int cnt = 0;
	for (int i = mx; i <= n; i++)
		if (par[i] - par[i - mx] >= 0)
			cnt ++;
	cout << cnt << '\n';
}