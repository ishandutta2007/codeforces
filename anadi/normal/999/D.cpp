#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
int tab[N];
int balance[N];
vector <int> V[N];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &tab[i]);
		V[tab[i]%m].push_back(i);
	}
	
	for(int i = 0; i < m; ++i)
		balance[i] = int(V[i].size()) - (n / m);
	
	vector <int> cur;
	for(int i = 0; i < m + m; ++i){
		if(balance[i%m] > 0){
			while(balance[i%m] > 0){
				cur.push_back(V[i%m].back());
				V[i%m].pop_back();
				--balance[i%m];
			}
		}
		else if(balance[i%m] < 0){
			while(cur.size() && balance[i%m] < 0){
				++balance[i%m];
				V[i%m].push_back(cur.back());
				cur.pop_back();
			}
		}
	}
	
	long long int moves = 0;
	for(int i = 0; i < m; ++i){
		for(int v: V[i]){
			int diff = (m + i - tab[v]%m)%m;
			moves += diff;
			tab[v] += diff;
		}
	}
	
	printf("%lld\n", moves);
	for(int i = 1; i <= n; ++i)
		printf("%d ", tab[i]);
	return 0;
}