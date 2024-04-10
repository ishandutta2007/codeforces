#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
char p[6010];
int n, m, S[900];
double Ans;
int main() {
	int i, j, k;
	scanf("%s", p);
	for (i = 0; p[i]; i++);
	n = i;
	for (i = 0; i < 26; i++) {
		vector<int>T;
		for (j = 0; j < n; j++) {
			if (p[j] == 'a' + i) {
				T.push_back(j);
			}
		}
		double res = 0.0;
		for (j = 1; j < n; j++) {
			int c1 = 0, c2 = 0;
			for (auto &t : T) {
				int tp = (p[t] - 'a') * 26 + p[(t + j) % n] - 'a';
				S[tp]++;
				c1++;
			}
			for (k = 0; k < 700; k++) {
				if (S[k] == 1)c2++;
				S[k] = 0;
			}
			res = max(res, 1.0*c2 / c1);
		}
		Ans += res * (int)T.size() / n;
	}
	printf("%.10f\n", Ans);
}