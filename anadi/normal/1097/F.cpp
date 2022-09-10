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
const LL INF = 1e18 + 9LL;

int n, q;
vector <int> dv[7001];
bitset <7001> maybe[7001];

bool ok[7001];
bitset <7001> tmp;
bitset <7001> B[N];

int main(){
	for(int i = 1; i <= 7000; ++i)
		for(int j = i; j <= 7000; j += i)
			dv[j].push_back(i);
	
	ok[1] = true;
	for(int i = 2; i <= 7000; ++i)
		for(int v: dv[i])
			if(v < i)
				ok[i] ^= ok[v];
	
	for(int i = 1; i <= 7000; ++i)
		for(int j = i; j <= 7000; j += i)
			maybe[i][j] = ok[j / i];
	
	scanf("%d %d", &n, &q);
	while(q--){
		int t, x;
		scanf("%d %d", &t, &x);
		
		if(t == 1){
			int v;
			scanf("%d", &v);
			
			B[x].reset();			
			for(int u: dv[v])
				B[x][u] = true;
		}
		
		if(t == 2){
			int y, z;
			scanf("%d %d", &y, &z);			
			B[x] = B[y] ^ B[z];
		}
		
		if(t == 3){
			int y, z;
			scanf("%d %d", &y, &z);
			B[x] = B[y] & B[z];
		}
		
		if(t == 4){
			int v;
			scanf("%d", &v);
			tmp = B[x] & maybe[v];
			printf("%d", (int)tmp.count()%2);
		}
	}

	return 0;
}