#include<cstdio>
#include<cstring>
#include<vector>
#define N 100100
using namespace std;
bool isprime[N];
bool used[N]={};
int prime[N];
int accu[N]={0};
int pcnt=0;
vector<int> g[N];
int main(){
	memset(isprime,-1,sizeof(isprime));
	int i,j,n,m;
	scanf("%d",&n);
	for(i=2;i<N;i++){
		accu[i]=accu[i-1];
		if(isprime[i]){
			g[pcnt].push_back(i);
			prime[pcnt++]=i;
			accu[i]++;
		}
		for(j=0;j<pcnt&&i*prime[j]<N;j++){
			isprime[i*prime[j]]=false;
			if(i*prime[j]<=n) g[j].push_back(i*prime[j]);
			if(i%prime[j]==0) break;
		}
	}
	printf("%d\n",(n-1-(accu[n]-accu[n/2]))/2);
	for(i=accu[n/2]-1;i>0;i--){
		for(j=g[i].size()-1;j>0;j-=2){
			printf("%d %d\n",g[i][j],g[i][j-1]);
		}
		if(g[i].size()&1){
			printf("%d %d\n",prime[i],prime[i]*2);
			used[2*prime[i]]=true;
		}
	}
	i=0;
	while(i<g[0].size()){
		while(i<g[0].size()&&used[g[0][i]]) i++;
		j=i+1;
		while(j<g[0].size()&&used[g[0][j]]) j++;
		if(j<g[0].size()){
			printf("%d %d\n",g[0][i],g[0][j]);
		}
		i=j+1;
	}
	return 0;
}