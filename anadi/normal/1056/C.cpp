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

int n, m;
bool is[N];
int power[N];
int matched[N];

void write(int v){
	assert(!is[v]);
	is[v] = true;
	printf("%d\n", v);
	fflush(stdout);
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= 2 * n; ++i)
		scanf("%d", &power[i]);
	
	for(int i = 1; i <= m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		
		matched[u] = v;
		matched[v] = u;
	}
	
	int Turn;
	scanf("%d", &Turn);
	Turn--;

	int lastOpp = -1;
	for(int i = 0; i < 2 * n; ++i){
		bool t = i & 1;
		if((Turn ^ t) == 0){
//			printf("%d\n", i);
			if(lastOpp != -1 && matched[lastOpp] && !is[matched[lastOpp]])
				write(matched[lastOpp]);
			else{
				int notMatched = -1;
				for(int j = 1; j <= 2 * n; ++j)
					if(!is[j] && matched[j])
						notMatched = j;
				
				if(notMatched == -1){
					int best = 0;
					for(int j = 1; j <= 2 * n; ++j)
						if(power[j] > power[best] && !is[j])
							best = j;
					write(best);
				}
				else{
					if(power[notMatched] < power[matched[notMatched]])
						notMatched = matched[notMatched];
					write(notMatched);
				}
			}
		}
		else{
			scanf("%d", &lastOpp);
			assert(lastOpp != -1);
			is[lastOpp] = true;
		}
	}

	return 0;
}