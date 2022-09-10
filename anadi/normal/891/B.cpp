#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const int inf = 1e9 + 9;

int n, m;
int tab[N];
vector <pair <int, int> > V;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &tab[i]);
		V.pb({tab[i], i});
	}
	
	sort(V.begin(), V.end());
	for(int i = 1; i < V.size(); ++i)
		tab[V[i].second] = V[i - 1].first;
	tab[V[0].second] = V[n - 1].first;
	
	for(int i = 1; i <= n; ++i)
		printf("%d ", tab[i]);
	return 0;
}