#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

int n;
priority_queue <PII> Q;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int l, r;
		scanf("%d %d", &l, &r);
		Q.push({-l, 1});
		Q.push({-r, -1});
	}
	
	int cur = 0;
	while(!Q.empty()){
		int k = Q.top().nd;
		Q.pop();
		cur += k;
		
		if(cur > 2){
			puts("NO");
			exit(0);
		}
	}
	
	puts("YES");
	return 0;
}