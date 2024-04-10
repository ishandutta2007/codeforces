#include<cstdio>
#include<algorithm>
using namespace std;
int C[101000], w[101000];
long long D[101000], A[101000];
int n, K;
long long S = 0;
void Put(int a) {
	S += C[w[a]];
	C[w[a]]++;
}
void Del(int a) {
	C[w[a]]--;
	S -= C[w[a]];
}
void Make(int b1, int e1, int b2, int e2) {
	int i;
	if (e1 < b2 || e2 < b1) {
		for (i = b1; i <= e1; i++)Del(i);
		for (i = b2; i <= e2; i++)Put(i);
	}
	else {
		for (i = b1; i < b2; i++)Del(i);
		for (i = b2; i < b1; i++)Put(i);
		for (i = e1; i > e2; i--)Del(i);
		for (i = e2; i > e1; i--)Put(i);
	}
}
void Do(int b, int e, int s, int l, int bb, int ee) {
	if (b > e)return;
	l = min(l, e - 1);
	int mid = (b + e) >> 1, pv = 0, i;
	Make(bb, ee, s + 1, mid);
	long long M = 1e18;
	for (i = s; i <= min(mid - 1, l); i++) {
		long long t = A[i] + S;
		if (M > t)M = t, pv = i;
		Del(i + 1);
	}
	D[mid] = M;
	for (i = min(l, mid - 1); i >= pv; i--)Put(i + 1);
	Do(mid + 1, e, pv, l, pv+1, mid);
	Do(b, mid - 1, s, pv, pv+1, mid);
	Make(pv+1, mid, bb, ee);
}
int main() {
	int i, j;
	scanf("%d%d", &n,&K);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		A[i] = 1e18;
	}
	for (i = 1; i <= K; i++) {
		Do(i, n, 0, n - 1, 0, -1);
		for (j = 0; j <= n; j++)A[j] = D[j];
	}
	printf("%lld\n", D[n]);
}