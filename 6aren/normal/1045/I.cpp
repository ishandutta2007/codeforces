#include<bits/stdc++.h>

using namespace std;

string s;
int n;
map<int, int> cnt;

long long calc(int u) {
	long long res = 0;
	if (cnt[u] == 0) return 0;
	bitset<26> b(u);
	for (int i = 0; i < 26; i++) {
		b[i] = !b[i];
		res += 1LL * cnt[b.to_ulong()] * cnt[u];
		b[i] = !b[i];
	}
	res += 1LL * cnt[u] * (cnt[u] - 1);
	return res;
}

void proC(string t) {
	int cntD[30];
	memset(cntD, 0, sizeof(cntD));
	for (auto u : t) {
		cntD[u - 'a']++;
	}
	bitset<26> b;
	for (int i = 0; i < 26; i++) {
		b[i] = cntD[i] % 2;
	}
	cnt[b.to_ulong()]++;
} 

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	long long res = 0;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		proC(s);
	}
	for (auto i : cnt) {
		res += calc(i.first);
	}
	cout << res / 2;
	return 0;
}