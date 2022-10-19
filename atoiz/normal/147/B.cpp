#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef vector< vector<int> > Matrix;

const int INF = 1e8, LOG = 11;
int N, m;

Matrix operator+ (const Matrix &a, const Matrix &b)
{
    Matrix c (N, vector<int> (N, -INF));
    for (int k = 0; k < N; ++k) for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
    	c[i][j] = max (c[i][j], a[i][k] + b[k][j]);
    }
    return c;
}

bool check (const Matrix &a)
{
    for (int i = 0; i < N; ++i) if (a[i][i] > 0) return 1; return 0;
}

Matrix mtrxs[LOG];

int main()
{
	scanf("%d %d", &N, &m);

	mtrxs[0].assign(N, vector<int>(N, -INF));
    for (int i = 0; i < N; ++i) mtrxs[0][i][i] = 0;
	Matrix curMtrx = mtrxs[0]; int curNum = 0;

    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        --u, --v;
        scanf("%d %d", &mtrxs[0][u][v], &mtrxs[0][v][u]);
    }

    for (int i = 1; i < LOG; ++i) mtrxs[i] = mtrxs[i-1] + mtrxs[i-1];

	if (!check(mtrxs[LOG - 1])) return 0 * puts("0");
    for (int i = LOG - 1; i >= 0; --i) {
		Matrix tmp = curMtrx + mtrxs[i];
		if (!check(tmp)) {
            curMtrx = move (tmp);
            curNum += 1 << i;
		}
    }
    printf("%d\n", curNum + 1);
}