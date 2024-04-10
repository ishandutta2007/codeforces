#include<stdio.h>
#include<algorithm>
#include<vector>
#include<unordered_set>Set;
#include<unordered_map>
using namespace std;
int n, m, C[101000], QQ, PP[100010], G[101000];
bool chk[101000];
unsigned short P[501][100010];
unordered_set<long long>Set;
unordered_map<long long, int>Map;
vector<int>E[101000];
struct Edge{
	int a, b, col;
	bool operator <(const Edge &p)const{
		return col < p.col;
	}
}w[101000];
int find(int a){
	if (PP[a] == a)return a;
	return PP[a] = find(PP[a]);
}
void Do(int num, int b, int e){
	int i, x, y, ct = 0;
	for (i = b; i <= e; i++){
		PP[w[i].b] = w[i].b;
		PP[w[i].a] = w[i].a;
	}
	for (i = b; i <= e; i++){
		x = find(w[i].a), y = find(w[i].b);
		if (x != y)PP[x] = y;
	}
	for (i = b; i <= e; i++){
		PP[w[i].a] = find(w[i].a);
		PP[w[i].b] = find(w[i].b);
		chk[PP[w[i].a]] = true;
		chk[PP[w[i].b]] = true;
	}
	for (i = 1; i <= n; i++){
		if (chk[i]){
			ct++;
			G[i] = ct;
			chk[i] = false;
		}
	}
	for (i = 1; i <= n; i++){
		P[num][i] = G[PP[i]];
		PP[i] = 0;
	}
}
int L[220], cc;
bool v[110000];
void DFS(int a){
	v[a] = true;
	L[cc++] = a;
	int i;
	for (i = 0; i < E[a].size(); i++){
		if (!v[E[a][i]])DFS(E[a][i]);
	}
}
void Inp(){
	int i, j, t1, t2;
	long long t;
	for (i = 0; i < cc; i++){
		for (j = i + 1; j < cc; j++){
			t1 = L[i], t2 = L[j];
			if (t1 > t2)swap(t1, t2);
			t = (long long)t1 * (n + 1) + t2;
			if (Set.find(t) != Set.end()) Map[t]++;
		}
	}
}
void Do2(int b, int e){
	int i;
	for (i = b; i <= e; i++){
		E[w[i].a].push_back(w[i].b);
		E[w[i].b].push_back(w[i].a);
	}
	for (i = b; i <= e; i++){
		if (!v[w[i].a]){
			cc = 0;
			DFS(w[i].a);
			Inp();
		}
	}
	for (i = b; i <= e; i++){
		E[w[i].a].clear();
		E[w[i].b].clear();
		v[w[i].a] = false;
		v[w[i].b] = false;
	}
}
struct Query{
	int a, b;
}Q[101000];
int main()
{
	int i, j, ed, cnt = 0, Res;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++){
		scanf("%d%d%d", &w[i].a, &w[i].b, &w[i].col);
		C[w[i].col]++;
	}
	sort(w, w + m);
	scanf("%d", &QQ);
	for (i = 0; i < QQ; i++){
		scanf("%d%d", &Q[i].a, &Q[i].b);
		if (Q[i].a > Q[i].b)swap(Q[i].a, Q[i].b);
		Set.insert((long long)Q[i].a*(n + 1) + Q[i].b);
	}
	for (i = 0; i < m; i++){
		ed = i + C[w[i].col] - 1;
		if (C[w[i].col] >= 200){
			cnt++;
			Do(cnt, i, ed);
		}
		else{
			Do2(i, ed);
		}
		i = ed;
	}
	int a, b;
	for (i = 0; i < QQ; i++){
		a = Q[i].a, b = Q[i].b;
		Res = 0;
		for (j = 1; j <= cnt; j++){
			if (P[j][a] == P[j][b] && P[j][a])Res++;
		}
		printf("%d\n", Res + Map[(long long)a*(n + 1) + b]);
	}
}