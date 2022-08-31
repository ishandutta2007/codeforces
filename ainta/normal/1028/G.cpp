#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<long long>V;
int DEBUG = 1;
long long ww[10100], res, D[10100][6];
void Add(long long a) {
	V.push_back(a);
}
int Query() {
	printf("%d ", V.size());
	for (auto &x : V)printf("%lld ", x);
	printf("\n");
	fflush(stdout);
	int a;
	scanf("%d", &a);
	V.clear();
	return a;
}
void Calc(long long b, long long e, int cur) {
	long long i;
	if (e - b + 1 <= b && e-b+1 <= 10000) {
		for (i = b; i <= e; i++)Add(i);
		Query();
		return;
	}
	int c = min(b, 10000ll);
	long long pv = min(b + D[min(b,10000ll)][cur],e);
	int k;
	int cnt = 0;
	Add(pv);
	ww[cnt++] = pv;
	for (k = 1; k < c; k++) {
		pv = pv + 1 + D[min(pv + 1, 10000ll)][cur];
		if (pv <= e) {
			Add(pv);
			ww[cnt++] = pv;
		}
		else break;
	}
	int r = Query();
	if (r < 0)return;
	if (r == 0)Calc(b, ww[0] - 1, cur - 1);
	else if (r == cnt)Calc(ww[cnt - 1] + 1, e, cur - 1);
	else Calc(ww[r - 1] + 1, ww[r] - 1, cur - 1);
}
int main() {
	int i, j, k;
	for (i = 1; i <= 10000; i++)D[i][1] = i;
	for (i = 2; i <= 5; i++) {
		for (j = 1; j <= 10000; j++) {
			long long pv = j + D[j][i - 1];
			for (k = 1; k < j; k++) {
				if (pv >= 10000) {
					pv += (j - k) * (D[10000][i - 1]+1);
					break;
				}
				pv = pv + 1 + D[min(pv + 1,10000ll)][i - 1];
			}
			D[j][i] = pv + D[min(pv + 1, 10000ll)][i - 1] - j + 1;
			if (i == 5 && j == 1)break;
		}
	}
	Calc(1, 10004205361450474ll, 4);
}