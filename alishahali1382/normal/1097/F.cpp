#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
using namespace std;
const int K=7001;

int n, m, k, z, v, x, y, t, a, b, ans;
short mob[K];
bitset<K> A[100001], B[K], C[K];

int main(){
	for (int i=1; i<K; i++) for (int j=i; j<K; j+=i) B[j].set(i);
	mob[1]=1;
	for (int i=1; i<K; i++) for (int j=2*i; j<K; j+=i) mob[j]-=mob[i];
	for (int i=1; i<K; i++) for (int j=1; i*j<K; j++) if (mob[j]) C[i].set(i*j);
	scanf("%d%d", &n, &m);
	while (m--){
		scanf("%d%d", &t, &x);
		if (t==1){
			scanf("%d", &v);
			A[x]=B[v];
		}
		if (t==2){
			scanf("%d%d", &y, &z);
			A[x]=A[y]^A[z];
		}
		if (t==3){
			scanf("%d%d", &y, &z);
			A[x]=A[y]&A[z];		
		}
		if (t==4){
			scanf("%d", &v);
			printf("%d", ((C[v]&A[x]).count()&1));
		}
	}
	printf("\n");
	
	return 0;
}