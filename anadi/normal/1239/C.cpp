#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, p;
LL ans[N];
LL curTime;
set <int> S, E;
priority_queue <PLL> Q;

int main(){
	scanf("%d %d", &n, &p);
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		Q.push({-a, -i});
	}
	
	while(!Q.empty()){
		LL t = -Q.top().st;
		int id = -Q.top().nd;
		Q.pop();
		
		if(id == N){
			int who = *S.rbegin();
			ans[who] = curTime + p;
			S.erase(who);
			
			curTime += p;
			if(S.size() + E.size() == 0)
				continue;
			
			Q.push({-curTime - p, -N});
			if(S.size() == 0){
				S.insert(*E.begin());
				E.erase(E.begin());
				continue;
			}

			if(E.size() && *E.begin() < *S.begin()){
				S.insert(*E.begin());
				E.erase(E.begin());
			}
			
			continue;
		}
		
		if(S.size() + E.size() == 0){
			curTime = t;
			S.insert(id);
			Q.push({-curTime - p, -N});
			continue;
		}
		
		E.insert(id);
		if(*E.begin() < *S.begin()){
			S.insert(*E.begin());
			E.erase(E.begin());
		}
	}
	
	for(int i = 1; i <= n; ++i)
		printf("%lld ", ans[i]);
	return 0;
}