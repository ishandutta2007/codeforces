#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
char p[300100];
int L1, L2, m, Rank[300100], Count[300100], num[300100], LL;
long long S[300100], Mod = 1000000007;
struct multi{
	int a, b, num;
	bool operator<(const multi &p)const{
		return a != p.a ? a < p.a : b < p.b;
	}
}ord[330000], ord2[330000];
void Suffix_Array()
{
	int i, L = 1, cnt;
	for (i = 0; i < m; i++){
		ord[i].a = p[i];
		ord[i].b = 0;
		ord[i].num = i;
	}
	sort(ord, ord + m);
	while (1){
		cnt = 0;
		for (i = 0; i < m; i++){
			if (!i || ord[i - 1] < ord[i])cnt++;
			Rank[ord[i].num] = cnt;
		}
		if (L >= m)break;
		for (i = 0; i < m; i++){
			ord[i].a = Rank[i];
			ord[i].b = (i + L < m) ? Rank[i + L] : 0;
			ord[i].num = i;
			Count[ord[i].b]++;
		}
		for (i = 1; i <= cnt; i++)Count[i] += Count[i - 1];
		for (i = 0; i < m; i++){
			ord2[--Count[ord[i].b]] = ord[i];
		}
		for (i = 1; i <= cnt; i++)Count[i] = 0;
		for (i = 0; i < m; i++)Count[ord[i].a]++;
		for (i = 1; i <= cnt; i++)Count[i] += Count[i - 1];
		for (i = m - 1; i >= 0; i--){
			ord[--Count[ord2[i].a]] = ord2[i];
		}
		for (i = 1; i <= cnt; i++)Count[i] = 0;
		L *= 2;
	}
}
int LCP[300010];
void build_LCP()
{
	int i, x, L = 0, y, j;
	for (i = 0; i < m; i++){
		x = Rank[i];
		if (x == 1)continue;
		y = ord[x - 2].num;
		while (p[i + L] == p[y + L])L++;
		LCP[x - 1] = L;
		L--;
		if (L < 0)L = 0;
	}
	for (i = 0; i < m; i++){
		if (ord[i].num < L1) num[i] = 0;
		else if (ord[i].num < L2)num[i] = 1;
		else num[i] = 2;
	}
}
struct point{
	int a, x;
	bool operator <(const point &p)const{
		return a < p.a;
	}
}w[300010];
int par[300010];
long long SZ[300010][3];
int find(int a){
	if (a == par[a])return a;
	return par[a] = find(par[a]);
}
void Do()
{
	int i, p, q, j;
	for (i = 1; i < m; i++){
		w[i].a = LCP[i];
		w[i].x = i - 1;
	}
	sort(w + 1, w + m);
	for (i = 0; i < m; i++){
		par[i] = i;
		SZ[i][num[i]] = 1;
	}
	for (i = m - 1; i >= 1; i--){
		if (!w[i].a)break;
		p = find(w[i].x);
		q = w[i].x + 1;
		S[w[i].a] -= (SZ[p][0] * SZ[p][1] % Mod * SZ[p][2] + SZ[q][0] * SZ[q][1] % Mod * SZ[q][2]) % Mod;
		for (j = 0; j < 3; j++){
			SZ[p][j] += SZ[q][j];
			SZ[q][j] = 0;
		}
		par[q] = p;
		S[w[i].a] += SZ[p][0] * SZ[p][1] % Mod * SZ[p][2] % Mod;
		S[w[i].a] = (S[w[i].a] + Mod) % Mod;
	}
	for (i = LL - 1; i >= 1; i--){
		S[i] = (S[i] + S[i + 1]) % Mod;
	}
}
int main()
{
	int i;
	scanf("%s", p);
	for (i = 0; p[i]; i++);
	L1 = i; p[i] = ' ';
	scanf("%s", p + L1 + 1);
	for (i = L1; p[i]; i++);
	L2 = i; p[i] = ' ';
	scanf("%s", p + L2 + 1);
	for (i = L2; p[i]; i++);
	m = i;
	LL = min(min(L1, L2 - L1 - 1), m - L2 - 1);
	Suffix_Array();
	build_LCP();
	Do();
	for (i = 1; i <= LL; i++)printf("%lld ", S[i] % Mod);
}