#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int P = 400;
const int N = 1e6 + 7;

int n, q;
int tab[N];
int cur[N];
pair <PII, int> req[N];

LL ans[N];
LL res = 0LL;
void change(int a, int t){
	res -= 1LL * a * cur[a] * cur[a];
	cur[a] += t;
	res += 1LL * a * cur[a] * cur[a];
}

int main(){
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &tab[i]);
	
	for(int i = 1; i <= q; ++i){
		scanf("%d %d", &req[i].st.st, &req[i].st.nd);
		req[i].nd = i;
	}
	
	sort(req + 1, req + q + 1, [](pair <PII, int> a, pair <PII, int> b) -> bool{if(a.st.st / P == b.st.st / P) return a.st.nd < b.st.nd; return a.st.st < b.st.st;});
	int p = 1, k = 1;
	for(int i = 1; i <= q; ++i){
		while(p < req[i].st.st)
			change(tab[p++], -1);
		while(p > req[i].st.st)
			change(tab[--p], 1);
		
		while(k <= req[i].st.nd)
			change(tab[k++], 1);
		while(k > req[i].st.nd + 1)
			change(tab[--k], -1);
		ans[req[i].nd] = res;
	}
	
	for(int i = 1; i <= q; ++i)
		printf("%lld\n", ans[i]);
	return 0;
}