#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
int in[N];
set <int> S;
vector <int> val[N];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &in[i]);
		S.insert(i);
		val[in[i]].push_back(i);
	}
	
	if(val[m].size() == 0){
		bool ok = false;
		for(int i = 1; i <= n; ++i)
			if(in[i] == 0){
				val[m].push_back(i);
				in[i] = m;
				ok = true;
				break;
			}
		
		if(!ok){
			puts("NO");
			return 0;
		}
	}
	
	for(int i = m; i >= 1; --i){
		int from = n + 1, to = 0;
		for(int v: val[i]){
			from = min(from, v);
			to = max(to, v);
		}
		
		if(from > to)
			continue;
		
		auto it = S.lower_bound(from);
		while(it != S.end() && *it <= to){
			if(in[*it] != i && in[*it] != 0){
				puts("NO");
				return 0;
			}
			
			in[*it] = i;
			S.erase(it);
			it = S.lower_bound(from);
		}
	}
	
	for(int v: S)
		in[v] = 1;
	
	puts("YES");
	for(int i = 1; i <= n; ++i)
		printf("%d ", in[i]);
	return 0;
}