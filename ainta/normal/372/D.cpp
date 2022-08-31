#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
#define N_ 100010
vector<int>E[N_];
multiset<int>Set, Set2;
int n, K, Dep[N_], ren[N_], ed[N_], C, p[18][N_], S, pp;
bool v[N_];
void DFS(int a, int depth){
	v[a] = true;
	ren[a] = ++C;
	Dep[C] = depth;
	int i;
	for (i = 0; i < E[a].size(); i++){
		if (!v[E[a][i]]){
			p[0][C + 1] = ren[a];
			DFS(E[a][i], depth + 1);
		}
	}
	ed[ren[a]] = C;
}
int LCA(int a, int b){
	if (Dep[a] < Dep[b])return LCA(b, a);
	int d = Dep[a] - Dep[b];
	int c = 0;
	while (d){
		if ((1 << c)&d)a = p[c][a], d ^= (1 << c);
		c++;
	}
	for (c = 16; c >= 0; c--){
		if (p[c][a] != p[c][b])a = p[c][a], b = p[c][b];
	}
	if (a != b)a = p[0][a], b = p[0][b];
	return a;
}
int LCA2(int a){
	multiset<int>::iterator it;
	it = Set2.lower_bound(a);
	int d = -1, d2 = -1;
	if (it != Set2.end()) d = LCA(*it, a);
	if (it != Set2.begin()){
		it--;
		d2 = LCA(*it, a);
	}
	if (d == -1 || (d2 != -1 && Dep[d] < Dep[d2])) d = d2;
	return d;
}
void ins(int a){
	if (Set2.empty()){
		S = 1;
		Set2.insert(a);
		pp = a;
		return;
	}
	int d = LCA2(a);
	S += Dep[a] - Dep[d];
	if (Dep[d] < Dep[pp]) S += Dep[pp] - Dep[d], pp = d;
	Set2.insert(a);
}
void Del(int a){
	Set2.erase(Set2.find(a));
	int d = LCA2(a);
	S -= Dep[a] - Dep[d];
	int t;
	if (Set.empty())t = *Set2.begin();
	else t = *Set.begin();
	if (pp != t){
		S -= Dep[t] - Dep[pp];
		pp = t;
	}
}
int Pro(){
	int i, pv = 1, r = 0;
	S = 0;
	for (i = 1; i <= n; i++){
		if(i != 1)Set.insert(LCA(ren[i], ren[i - 1]));
		ins(ren[i]);
		while (S > K){
			Set.erase(Set.find(LCA(ren[pv], ren[pv + 1])));
			Del(ren[pv]);
			pv++;
		}
		if (r < i - pv + 1)r = i - pv + 1;
	}
	return r;
}
void Make(){
	int i, j;
	for (i = 1; i < 17; i++){
		for (j = 1; j <= n; j++)p[i][j] = p[i - 1][p[i - 1][j]];
	}
}
int main()
{
	int i, a, b;
	scanf("%d%d", &n, &K);
	for (i = 1; i < n; i++){
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	DFS(1, 0);
	Make();
	printf("%d\n", Pro());
}