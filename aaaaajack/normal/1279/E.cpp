#include<bits/stdc++.h>
using namespace std;
long long inf=2e18;
long long fac[60]={1};
long long total[60]={1};
long long bounded_prod(long long a,long long b){
	return a<=inf/b?a*b:inf;
}
int get_end(int f[],int x){
	if(f[x]==x) return x;
	return f[x]=get_end(f,f[x]);
}
void solve_fc(int st, long long k, int sz){
	//printf("\n cycle size = %d, index=%lld\n",sz,k);
	if(sz==1){
		printf("%d ",st);
		return;
	}
	int f[60]={};
	printf("%d ",st+sz-1);
	for(int i=0;i<sz-1;i++) f[i]=i;
	for(int i=1;i<sz-1;i++){
		for(int j=0;j<sz;j++){
			//if(f[j]==j && k==0) printf("\nnow %d,%d connect to %d\n",st+j,st+i,st+get_end(f,i));
			if(f[j]!=j || get_end(f,i)==j) continue;
			if(k<fac[sz-2-i]){
				printf("%d ",st+j);
				f[j]=i;
				break;
			}
			else k-=fac[sz-2-i];
		}
	}
	for(int i=0;i<sz;i++){
		if(f[i]==i) printf("%d ",st+i);
	}
}
void solve(int st, long long k, int sz){
	for(int j=1;j<=sz;j++){
		long long fc=(j>1?fac[j-2]:1);
		if(bounded_prod(fc, total[sz-j])<=k) k-=fc*total[sz-j];
		else{
			solve_fc(st, k/total[sz-j], j);
			solve(st+j, k%total[sz-j], sz-j);
			break;
		}
	}
}
int main(){
	for(int i=1;i<60;i++){
		fac[i]=bounded_prod(fac[i-1],i);
	}
	for(int i=1;i<60;i++){
		for(int j=1;j<=i;j++){
			long long fc=(j>1?fac[j-2]:1);
			total[i]+=bounded_prod(fc,total[i-j]);
			if(total[i]>inf) total[i]=inf;
		}
	}
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		long long k;
		scanf("%d%lld",&n,&k);
		if(k>total[n]) puts("-1");
		else{
			solve(1,--k, n);
			puts("");
		}
	}
	return 0;
}