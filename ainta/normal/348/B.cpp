#include<stdio.h>
#include<algorithm>
#include<vector>
#define INF 11111111111111111LL
using namespace std;
vector<int>E[101000];
int n,w[101000];
long long F[101000],G[101000],S;
bool v[101000];
long long gcd(long long a, long long b){
	return b ? gcd(b, a%b) : a;
}
void DFS(int a){
	int i;
	long long MM = 1, c = 0,tp,Mn=INF;
	v[a] = true;
	for (i = 0; i < E[a].size(); i++){
		if (!v[E[a][i]]){
			c++;
			DFS(E[a][i]);
			if (F[E[a][i]] == INF){
				F[a] = INF;
				return;
			}
			if (Mn>G[E[a][i]])Mn = G[E[a][i]];
			tp = F[E[a][i]];
			tp /= gcd(MM, F[E[a][i]]);
			if (MM > Mn / tp){
				F[a] = INF;
				return;
			}
			MM *= tp;
		}
	}
	if (!c){
		F[a] = w[a]?1:INF;
		G[a] = w[a];
		return;
	}
	F[a] = MM*c;
	tp = Mn / MM;
	tp = tp*MM*c;
	G[a] = tp;
}
int main()
{
	int i,a,b;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &w[i]);
		S = S + w[i];
	}
	for (i = 1; i < n; i++){
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	DFS(1);
	if (F[1] == INF){
		printf("%lld\n", S);
	}
	else{
		printf("%lld\n", S - G[1]);
	}
}