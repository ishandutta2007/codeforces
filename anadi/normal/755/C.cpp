#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double DD;

#define PLL pair <LL, LL>
#define PII pair <int, int>
#define PDD pair <DD, DD>
#define mp make_pair
#define st first
#define nd second
#define pb push_back

const int N = 1e4 + 7;

int n;
int rep[N];

int Find(int a){
	if(rep[a] == a)
		return a;
	return rep[a] = Find(rep[a]);
}

void Union(int a, int b){
	rep[a] = rep[Find(b)];
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		rep[i] = i;
	
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		Union(i, a);
	}
	
	int cnt = 0;
	for(int i = 1; i <= n; ++i)
		if(Find(i) == i)
			++cnt;
	
	printf("%d\n", cnt);
	return 0;
}