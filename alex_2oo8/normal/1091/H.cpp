#include <bits/stdc++.h>

using namespace std;

const int MX = 200000, MV = 100;

int g[MX], f[MX];
bool notPrime[MX], good[MX];
vector<int> pos[MV];

int main() {
	int n, v = 0, f;
	ignore = scanf("%d %d", &n, &f);
	
	vector<int> d;
	for (int x = 2; x < MX; x++)
		if (notPrime[x] == false) {
			d.push_back(x);
			for (int y = 2 * x; y < MX; y += x) notPrime[y] = true;
		}
	
	size_t pCnt = d.size();
	for (size_t i = 0; i < pCnt; i++)
		for (size_t j = 0; j < pCnt && d[i] * d[j] < MX; j++)
			d.push_back(d[i] * d[j]);
	
	sort(d.begin(), d.end());
	
	for (int x : d) good[x] = true;
	
	good[f] = false;
	
	g[0] = 0;
	pos[0].push_back(0);
	for (int i = 1; i < MX; i++) {
		for (int v = 0; true; v++) {
			g[i] = v;
			bool ok = true;
			for (int p : pos[v]) {
				if (good[i - p]) {
					ok = false;
					break;
				}
			}
			if (ok) break;
		}
		
		pos[g[i]].push_back(i);
	}
	
	for (int i = 0; i < n; i++) {
		int a, b, c;
		ignore = scanf("%d %d %d", &a, &b, &c);
		v ^= g[b - a - 1] ^ g[c - b - 1];
	}
	
	if (v != 0) printf("Alice\nBob\n");
	else printf("Bob\nAlice\n");
	
	return 0;
}