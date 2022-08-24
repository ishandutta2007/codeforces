#include<stdio.h>
#include<algorithm>
#include<vector>
#define SZ 1048576
using namespace std;
vector<int>E[1010000];
int n, K, oto[1010000], num[1010000], ed[1010000], cnt, IT[SZ+SZ+1];
char p[1010000];
void DFS(int a, int pp){
	int i;
	num[a] = ++cnt;
	for (i = 0; i < E[a].size(); i++){
		if (E[a][i] != pp)DFS(E[a][i], a);
	}
	ed[num[a]] = cnt;
}
void Add(int b, int e, int x){
	b += SZ, e += SZ;
	while (b <= e){
		if (b & 1)IT[b] += x;
		if (!(e & 1))IT[e] += x;
		b = (b + 1) >> 1, e = (e - 1) >> 1;
	}
}
int Gap(int x){
	int r = 0;
	x += SZ;
	while (x){
		r += IT[x];
		x >>= 1;
	}
	return r;
}
int main(){
	int i, t, b, e, pb, pe;
	scanf("%d%d", &n, &K);
	scanf("%s", p);
	oto[0] = -1;
	for (i = 1; i <= n; i++){
		t = oto[i - 1];
		while (t != -1 && p[i - 1] != p[t]) t = oto[t];
		oto[i] = t + 1;
		E[oto[i]].push_back(i);
	}
	DFS(0, -1);
	b = 0, e = -1;
	for (i = 1; i <= n; i++){
		pb = i / K, pe = i / (K + 1);
		if (pe*(K + 1) < i)pe++;
		pb = i - pb, pe = i - pe;
		while (b < pb){
			Add(num[b], ed[num[b]], -1);
			b++;
		}
		while (e < pe){
			e++;
			Add(num[e], ed[num[e]], 1);
		}
		if (Gap(num[i]))printf("1");
		else printf("0");
	}
}