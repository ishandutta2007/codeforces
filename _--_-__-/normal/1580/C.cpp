#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;
const int MAGIC = 450;

int n, m, x[200005], y[200005], cur, sum;
int d0[200005], d1[455][455];
int beg[200005];

int main()
{
	scanf("%d%d", &n, &m);
	rep1(i, n) scanf("%d%d", &x[i], &y[i]);
	
	rep(i, m) {
		int op, k, coef = 1;
		scanf("%d%d", &op, &k);
		if(op == 1) beg[k] = i;
		else {
			coef = -1;
			if((i - 1 - beg[k]) % (x[k] + y[k]) < x[k]) cur --;
		}
		sum += coef;
		if(x[k] + y[k] < MAGIC) {
			d1[x[k] + y[k]][beg[k] % (x[k] + y[k])] += coef; d1[x[k] + y[k]][(beg[k] + x[k]) % (x[k] + y[k])] -= coef;
		} else {
			for(LL tmp = beg[k]; tmp < m; tmp += x[k] + y[k]) d0[tmp] += coef;
			for(LL tmp = beg[k] + x[k]; tmp < m; tmp += x[k] + y[k]) d0[tmp] -= coef;
		}
		cur += d0[i];
		for(int tmp = 2; tmp < MAGIC; tmp ++) cur += d1[tmp][i % tmp];
		printf("%d\n", sum - cur);
	}
	return 0;
}