#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
void write(int num) {
	if (num >= 10) write(num / 10);
	putchar(num % 10 + '0');
}
int a[100001];
int maxn[100001], id[100001];
struct Add {
	int id, typ, b;
	long long las;
}add[100001];
vector<Add> v[100001];
bool operator<(const Add &a, const Add &b) {
	return a.b*b.las > b.b*a.las;
}
bool cmp(const Add &a, const Add &b) {
	return a.b > b.b;
}
bool put(const Add &a, const Add &b) {
	return a.typ < b.typ;
}
struct Mul {
	int b, id;
}mul[100001];
bool operator<(const Mul &a, const Mul &b) {
	return a.b > b.b;
}
int ans1, ans2;
int main(){
	int k, n, m, cadd = 0, cmul = 0;
	k = read(), n = read(), m = read();
	for (int i = 1; i <= k; i++) a[i] = read();
	for (int i = 1; i <= n; i++) {
		int t, j, b;
		t = read(), j = read(), b = read();
		if (t == 1) {
			if (b > maxn[j]) {
				maxn[j] = b;
				id[j] = i;
			}
		}
		if (t == 2) {
			Add tmp;
			tmp.typ = 2, tmp.id = i, tmp.b = b, tmp.las = a[j];
			v[j].push_back(tmp);
		}
		if (t == 3) {
			++cmul;
			mul[cmul].b = b, mul[cmul].id = i;
		}
	}
	for (int i = 1; i <= k; i++) {
		if (maxn[i] > a[i]) {
			Add tmp;
			tmp.id = id[i], tmp.typ = 1, tmp.b = maxn[i] - a[i];
			v[i].push_back(tmp);
		}
		sort(v[i].begin(), v[i].end(), cmp);
		if (v[i].begin() != v[i].end()) v[i][0].las = a[i];
		for (int j = 1; j < v[i].size(); j++) v[i][j].las = v[i][j-1].las + v[i][j-1].b;
		for (int j = 0; j < v[i].size(); j++) add[++cadd] = v[i][j];
	}
	sort(add + 1, add + cadd + 1);
	sort(mul + 1, mul + cmul + 1);
	int p = min(cmul, m);
	ans2 = min(cmul, m);
	for (int i = 1; i <= m && i <= cadd; i++) {
		if (i + p <= m) {
			ans1 = i;
			continue;
		}
		if (add[i].las + add[i].b > mul[p].b * add[i].las) {
			--p;
			ans1 = i, ans2 = p;
			continue;
		}
		break;
	}
	sort(add + 1, add + ans1 + 1, put);
	write(ans1 + ans2), putchar('\n');
	for (int i = 1; i <= ans1; i++) write(add[i].id), putchar(' ');
	for (int i = 1; i <= ans2; i++) write(mul[i].id), putchar(' ');
	return 0;
}