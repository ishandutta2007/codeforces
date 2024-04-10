#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n, it;
int rep[N];

int bal[N];
set <PII> S;

int Find(int a){
	if(rep[a] == a)
		return a;
	return rep[a] = Find(rep[a]);
}

void Union(int a, int b){
	rep[Find(a)] = Find(b);
}

int main(){
	scanf("%d", &n); it = n;
	for(int i = 1; i <= n; ++i){
		rep[i] = i;
		scanf("%d", &bal[i]);
		S.insert({bal[i], i});
	}
	
	int q;
	scanf("%d", &q);

	while(q--){
		int t, p, x;
		scanf("%d", &t);
		
		++it;
		if(t == 1){
			scanf("%d %d", &p, &x);			
			rep[p] = it;
		}
		else{
			scanf("%d", &x);
			while(S.size() > 0 && (*S.begin()).st < x){
				int cur = (*S.begin()).nd;
				S.erase(S.begin());
				
				if(rep[cur] == cur)
					rep[cur] = it;
			}
		}
		
		rep[it] = it;
		bal[it] = x;
		S.insert({bal[it], it});
	}
	
	for(int i = 1; i <= n; ++i)
		printf("%d ", bal[Find(i)]);
	puts("");
	return 0;
}