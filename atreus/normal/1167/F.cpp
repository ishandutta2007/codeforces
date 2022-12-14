#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 5e5 + 10;
const int mod = 1e9 + 7;

int a[maxn], b[maxn], n, fen[maxn];

int get(int idx){
	int ret = 0;
	for (; idx; idx -= idx & -idx){
		ret += fen[idx];
		if (ret >= mod)
			ret -= mod;
	}
	return ret;
}

void add(int idx, int val){
	for (; idx <= n; idx += idx & -idx){
		fen[idx] += val;
		if (fen[idx] >= mod)
			fen[idx] -= mod;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	vector<int> v;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		v.push_back(a[i]);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (int i = 1; i <= n; i++)
		b[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
	int answer = 0;
	for (int i = 1; i <= n; i++){
		answer = (answer + 1ll * i * (n - i + 1) % mod * a[i] % mod) % mod;
		int k = get(b[i] - 1);
		answer = (answer + 1ll * k * (n - i + 1) % mod * a[i] % mod) % mod;
		add(b[i], i);
	}
	memset(fen, 0, sizeof fen);
	for (int i = n; i >= 1; i--){
		int k = get(b[i]);
		answer = (answer + 1ll * k * i % mod * a[i] % mod) % mod;
		add(b[i], n - i + 1);
	}
	cout << answer << endl;
}