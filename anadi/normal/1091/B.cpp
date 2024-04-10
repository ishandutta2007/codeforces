#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
PII ob[N];
map <PII, int> M;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d %d", &ob[i].st, &ob[i].nd);
	
	for(int i = 1; i <= n; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		for(int j = 1; j <= n; ++j)
			M[{ob[j].st + x, ob[j].nd + y}]++;
	}
	
	for(auto v: M)
		if(v.nd == n){
			printf("%d %d\n", v.st.st, v.st.nd);
			return 0;
		}
	
	assert(false);
	return 0;
}