#include<bits/stdc++.h>

using namespace std;

const int MX = 200000;

vector< pair<long long, pair<int, int> > > v;
int a[MX], b[MX], c[MX], t[MX], x[MX], y[MX];

int main() {
	int n, m, k, s;
	scanf("%d %d %d %d", &n, &m, &k, &s);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	for (int i = 0; i < n; i++) scanf("%d", b + i);
	for (int i = 0; i < m; i++) scanf("%d %d", t + i, c + i);
	
	int ans = 0;
	for (int i = (1 << 20); i > 0; i /= 2) {
		int A = a[0], Ai = 1, B = b[0], Bi = 1;
		for (int j = 0; j < ans + i && j < n; j++) {
			if (a[j] < A) {
				A = a[j];
				Ai = j + 1;
			}
			
			if (b[j] < B) {
				B = b[j];
				Bi = j + 1;
			}
		}
		
		v.clear();
		for (int j = 0; j < m; j++)
			v.push_back(make_pair(c[j] * 1ll * (t[j] == 1 ? A : B), make_pair(j + 1, t[j] == 1 ? Ai : Bi)));
		
		sort(v.begin(), v.end());
		
		long long S = 0;
		for (int j = 0; j < k; j++) S += v[j].first;
		
		if (S > s) ans += i;
		else {
			for (int j = 0; j < k; j++) {
				x[j] = v[j].second.first;
				y[j] = v[j].second.second;
			}
		}
	}
	
	ans += 1;
	
	if (ans > n) ans = -1;
	
	printf("%d\n", ans);
	
	if (ans != -1) for (int i = 0; i < k; i++) printf("%d %d\n", x[i], y[i]);
	
	return 0;
}