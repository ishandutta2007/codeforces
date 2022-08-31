#include<cstdio>
#include<algorithm>
#include<set>
#define SZ 262144
#define N_ 201000
using namespace std;
int n, w[N_], IT[SZ+SZ][3];
char p[N_];
void Add(int a, int pv, int x) {
	a += SZ;
	while (a) {
		IT[a][pv] += x;
		a >>= 1;
	}
}
int Sum(int b, int e, int pv) {
	b += SZ, e += SZ;
	int r = 0;
	while (b <= e) {
		if (b & 1)r += IT[b][pv];
		if (!(e & 1))r += IT[e][pv];
		b = (b + 1) >> 1, e = (e - 1) >> 1;
	}
	return r;
}
int First(int pv) {
	int b = SZ, e = SZ+SZ-1;
	while (b <= e) {
		if (IT[b][pv])break;
		b = (b + 1) >> 1;
		e = (e - 1) >> 1;
	}
	if (b > e)return n + 1;
	while (b < SZ) {
		b *= 2;
		if (!IT[b][pv])b++;
	}
	return b - SZ;
}
int Last(int pv) {
	int b = SZ, e = SZ+SZ-1;
	while (b <= e) {
		if (IT[e][pv])break;
		b = (b + 1) >> 1;
		e = (e - 1) >> 1;
	}
	if (b > e)return -1;
	while (e < SZ) {
		e = e*2+1;
		if (!IT[e][pv])e--;
	}
	return e - SZ;
}
char tt[4] = "RPS";
int Num[200];
int Get() {
	int bR = First(0), bP = First(1), bS = First(2);
	int eR = Last(0), eP = Last(1), eS = Last(2);
	int cR = Sum(1, n, 0), cP = Sum(1, n, 1), cS = Sum(1, n, 2);
	int res = 0;
	if (eS == -1 && eP != -1)res += cR;
	else res += Sum(bP, bS, 0) + Sum(eS, eP, 0);
	if (eR == -1 && eS != -1)res += cP;
	else res += Sum(bS, bR, 1) + Sum(eR, eS, 1);
	if (eP == -1 && eR != -1)res += cS;
	else res += Sum(bR, bP, 2) + Sum(eP, eR, 2);
	return n-res;
}
int main() {
	int i, Q;
	for (i = 0; i < 3; i++)Num[tt[i]] = i;
	scanf("%d%d", &n,&Q);
	scanf("%s", p + 1);
	for (i = 1; i <= n; i++) {
		Add(i,Num[p[i]],1);
	}
	printf("%d\n", Get());
	int a;
	char pp[3];
	while (Q--) {
		scanf("%d", &a);
		scanf("%s", pp);
		Add(a, Num[p[a]], -1);
		p[a] = pp[0];
		Add(a, Num[p[a]], 1);
		printf("%d\n",Get());
	}
}