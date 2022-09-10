#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>
#define PIII pair <int, PII>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const int inf  = 1e9 + 9;

int n, w, h;
PII ans[N];
int cur[2 * N];
vector <PIII> v[2];
vector <PII> V[2 * N];

int main(){
	scanf("%d %d %d", &n, &w, &h);
	for(int i = 1; i <= n; ++i){
		int g, x, t;
		scanf("%d %d %d", &g, &x, &t);
		v[g - 1].pb(mp(x, mp(t, i)));
	}
	
	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());

	for(int i = 0; i < v[0].size(); ++i)
		V[v[0][i].st - v[0][i].nd.st + N].pb({v[0][i].st, h});
	for(int i = v[1].size() - 1; i >= 0; --i)
		V[v[1][i].st - v[1][i].nd.st + N].pb({w, v[1][i].st});


	for(int i = v[1].size() - 1; i >= 0; --i)
		ans[v[1][i].nd.nd] = V[v[1][i].st - v[1][i].nd.st + N][cur[v[1][i].st - v[1][i].nd.st + N]++];
	for(int i = 0; i < v[0].size(); ++i)
		ans[v[0][i].nd.nd] = V[v[0][i].st - v[0][i].nd.st + N][cur[v[0][i].st - v[0][i].nd.st + N]++];
	
	for(int i = 1; i <= n; ++i)
		printf("%d %d\n", ans[i].st, ans[i].nd);
	return 0;
}