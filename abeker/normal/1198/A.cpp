#include <bits/stdc++.h>
using namespace std;

int N, I, K;
map <int, int> occ;

int main() {
	scanf("%d%d", &N, &I);
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		occ[x]++;
	}
	
	vector <int> pref = {0};
	for (auto it : occ)
		pref.push_back(it.second);
	
	int sz = pref.size();
	for (int i = 1; i < sz; i++)
		pref[i] += pref[i - 1];
		
	int bits = 8 * I / N;
	if (bits > 20 || (1 << bits) > sz - 1)
		K = sz - 1;
	else
		K = 1 << bits;
	
	int ans = 0;
	for (int i = 1; i + K - 1 < sz; i++)
		ans = max(ans, pref[i + K - 1] - pref[i - 1]);
	
	printf("%d\n", N - ans);
	
	return 0;
}