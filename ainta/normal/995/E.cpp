#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
int n, m, p, Q1[1010000], Q2[1010000], chk;
map<int,int>S1, S2;
int Pow(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1)r = (long long)r*a%p;
		a = (long long)a*a%p; b >>= 1;
	}
	return r;
}
int Prev(int a) {
	return (a + p - 1) % p;
}
int Next(int a) {
	return (a + 1) % p;
}
int h1 = 0, t1 = 0, h2 = 0, t2 = 0;
void Put1(int a, int pp) {
	if (S1.count(a))return;
	S1[a] = pp;
	Q1[++t1] = a;
}
void Put2(int a, int pp) {
	if (S2.count(a))return;
	S2[a] = pp;
	Q2[++t2] = a;
	if (S1.count(a)) {
		chk = a;
		return;
	}
}
int main() {
	int b, e;
	scanf("%d%d%d", &b, &e, &p);
	Q1[++t1] = b;
	Q2[++t2] = e;
	S1[b] = S2[e] = 0;
	while (1) {
		int x = Q1[++h1];
		Put1(Prev(x), 1);
		Put1(Next(x), 2);
		Put1(Pow(x, p-2), 3);
		x = Q2[++h2];
		Put2(Prev(x), 1);
		Put2(Next(x), 2);
		Put2(Pow(x, p - 2), 3);
		if (chk)break;
	}
	int x = chk;
	vector<int>T1, T2;
	while (S1[x]) {
		int t = S1[x];
		T1.push_back(t);
		if (t == 1)x = Next(x);
		else if (t == 2)x = Prev(x);
		else x = Pow(x, p - 2);
	}
	x = chk;
	while (S2[x]) {
		int t = S2[x];
		T2.push_back(t);
		if (t == 1)x = Next(x);
		else if (t == 2)x = Prev(x);
		else x = Pow(x, p - 2);
	}
	int i;
	vector<int>res;
	for (i = T1.size() - 1; i >= 0; i--)res.push_back(T1[i]);
	for (i = 0; i < T2.size(); i++) {
		if (T2[i] <= 2)res.push_back(3 - T2[i]);
		else res.push_back(3);
	}
	printf("%d\n", res.size());
	for (auto &t : res) {
		if (t < 3)t = 3 - t;
		printf("%d ", t);
	}
}