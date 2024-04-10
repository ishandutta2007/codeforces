#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1e5 + 7;

int n, m;
int att[N];
PII in[N];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &att[i]);
	for(int i = 1; i <= m; ++i)
		scanf("%d %d", &in[i].st, &in[i].nd);
	sort(in + 1, in + m + 1);
	
	for(int i = 1; i <= m; ++i)
		in[i].nd += in[i - 1].nd;
	
	for(int i = 1; i <= n; ++i){
		int p = 0, k = m;
		while(p < k){
			int mid = (p + k + 1) / 2;
			if(in[mid].st <= att[i])
				p = mid;
			else
				k = mid - 1;
		}
		
		printf("%d ", in[p].nd);
	}
	
	return 0;
}