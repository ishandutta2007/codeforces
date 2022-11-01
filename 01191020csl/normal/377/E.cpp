#include<bits/stdc++.h>
using namespace std;
long long read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	long long num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
struct factory {
	int v, c, p, t;
}fac[200001];
bool operator<(const factory &a, const factory &b) {
	if (a.c == b.c) return a.v > b.v;
	return a.c < b.c;
}
bool getresult1(factory f1, factory f2, factory f3) {
	__int128 tmp1 = ((__int128)f1.v*f2.v*(f2.t-f1.t)+(__int128)f1.p*f2.v-(__int128)f1.v*f2.p)*(f3.v-f2.v);
	__int128 tmp2 = ((__int128)f2.v*f3.v*(f3.t-f2.t)+(__int128)f2.p*f3.v-(__int128)f2.v*f3.p)*(f2.v-f1.v);
	return tmp1 < tmp2;
}
bool check1(factory f1, factory f2, int c) {
	__int128 tmp = (__int128)f1.v*f2.v*(f2.t-f1.t)+(__int128)f1.p*f2.v-(__int128)f1.v*f2.p;
	return tmp < 1ll * c * (f2.v-f1.v);
}
bool getresult2(factory f1, factory f2, factory f3) {
	__int128 tmp1 = (f1.p-f2.p+(__int128)f2.v*f2.t-(__int128)f1.v*f1.t)*(f3.v-f2.v);
	__int128 tmp2 = (f2.p-f3.p+(__int128)f3.v*f3.t-(__int128)f2.v*f2.t)*(f2.v-f1.v);
	return tmp1 < tmp2;
}
bool check2(factory f1, factory f2, int t) {
	__int128 tmp = f1.p-f2.p+(__int128)f2.v*f2.t-(__int128)f1.v*f1.t;
	return tmp < 1ll * t * (f2.v-f1.v);
}
factory q1[200001], q2[200001];
int main() {
//	freopen("collect.in", "r", stdin);
//	freopen("collect.out", "w", stdout);
	int n;
	long long S;
	n = read(), S = read();
	for (int i = 1; i <= n; i++) fac[i].v = read(), fac[i].c = read();
	sort(fac + 1, fac + n + 1);
	int p = 0, maxv = 0;
	for (int i = 1; i <= n; i++)
		if (fac[i].v > maxv) {
			maxv = fac[i].v;
			fac[++p] = fac[i];
		}
	int s1 = 1, t1 = 1, s2 = 1, t2 = 1;
	q1[1] = q2[1] = fac[1];
	long long ans = (S-1)/fac[1].v+1;
	for (int i = 2; i <= p; i++) {
		while (t1 - s1 && check1(q1[s1], q1[s1+1], fac[i].c)) ++s1;
		fac[i].t = q1[s1].t+(fac[i].c-q1[s1].p+q1[s1].v-1)/q1[s1].v;
		while (t2 - s2 && check2(q2[s2], q2[s2+1], fac[i].t)) ++s2;
		fac[i].p = q1[s2].p+q1[s2].v*(fac[i].t-q1[s2].t)-fac[i].c;
		while (t1 - s1 && !getresult1(q1[t1-1],q1[t1],fac[i])) --t1;
		while (t2 - s2 && !getresult2(q2[t2-1],q2[t2],fac[i])) --t2;
		q1[++t1] = q2[++t2] = fac[i];
		if (fac[i].p < S) ans = min(ans, fac[i].t+(S-fac[i].p+fac[i].v-1)/fac[i].v);
	}
	cout << ans << endl;
}