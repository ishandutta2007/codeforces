#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PII pair <int, int>
#define PLL pair <LL, LL>
#define mp make_pair
#define st first
#define nd second
#define pb push_back

const int N = 2e5 + 7;

priority_queue <PLL> Q;
priority_queue <PLL> E;
int ind[N];
LL l[N];

bool ok(){
	while(!Q.empty()){
		PLL a = Q.top();
		Q.pop();
		
		if(a.nd < 0){
			if(E.size() == 0)
				continue;
			LL x = -E.top().st;
			if(x < -a.st)
				return false;
			
			ind[E.top().nd] = -a.nd;
			E.pop();
			continue;
		}
		
		E.push(mp(-l[a.nd], a.nd));
	}
	
	if(E.size() != 0)
		return false;
	return true;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	
	PLL last;
	scanf("%I64d %I64d", &last.st, &last.nd);
	for(int i = 2; i <= n; ++i){
		LL a, b;
		scanf("%I64d %I64d", &a, &b);
		Q.push(mp(last.nd - a, i));
		l[i] = b - last.st;
		last = mp(a, b);
	}
	
	for(int i = 1; i <= m; ++i){
		LL a;
		scanf("%I64d", &a);
		Q.push(mp(-a, -i));
	}
	
	if(!ok())
		puts("No");
	else{
		puts("Yes");
		for(int i = 2; i <= n; ++i)
			printf("%d ", ind[i]);
	}

	return 0;
}