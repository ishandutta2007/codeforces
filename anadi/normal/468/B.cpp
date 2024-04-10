#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PII pair <int, int>
#define PLL pair <LL, LL>
#define nd second
#define st first
#define pb push_back

const int inf = 1e9 + 7;
const int N = 1e5 + 7;

int n, a, b;
int who[N];
int d[N][2];
queue <int> Q;
vector <int> V;
map <int, int> M;

int main(){
	scanf("%d %d %d", &n, &a, &b);
	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);
		M[x] = i;
		V.pb(x);
	}
	
	int i = 0;
	for(int x: V){
		++i;
		bool edge = false;
		if(M.count(a - x))
			d[i][0] = M[a - x],
			edge = true;
		if(M.count(b - x))
			d[i][1] = M[b - x],
			edge = true;
		
		if(!edge){
			puts("NO");
			return 0;
		}
		
		if(d[i][0] == 0){
			Q.push(i);
			who[i] = 1;
		}
		else
			who[i] = 0;
	}
	
	while(!Q.empty()){
		int k = Q.front();
		Q.pop();
		
		if(d[k][1] == 0){
			puts("NO");
			return 0;
		}
		
		if(who[d[k][1]] == 0){
			who[d[k][1]] = 1;
			Q.push(d[k][1]);
		}
		
		if(d[k][0] != 0 && who[d[k][0]] == 0){
			Q.push(d[k][0]);
			who[d[k][0]] = 1;
		}
	}
	
	puts("YES");
	for(int i = 1; i <= n; ++i)
		printf("%d ", who[i]);
	return 0;
}