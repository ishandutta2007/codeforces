#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<bitset>
using namespace std;
int dp[50][50]={};
int p;
int e[1<<20];
int ans[1<<20][22];
int cmb(int n,int m){
	if(n<m||m<0) return 0;
	if(n==m||m==0) return 1;
	if(dp[n][m]) return dp[n][m];
	if(n-m<m) return dp[n][m]=cmb(n,n-m);
	return dp[n][m]=(cmb(n-1,m-1)+cmb(n-1,m))%p;
}
void mpow(int v[],int m,long long t){
	int r[30]={1},x[30],i,j,k;
	while(t){
		if(t&1){
			memset(x,0,(m+1)*sizeof(int));
			for(i=0;i<=m;i++){
				for(j=0;j<=m-i;j++){
					for(k=0;k<=i;k++){
						x[i]+=1LL*cmb(m-i,j)*cmb(i,k)%p*r[k+j]%p*v[i-k+j]%p;
						x[i]%=p;
					}
				}
			}
			memcpy(r,x,(m+1)*sizeof(int));
		}
		t>>=1;
		memset(x,0,(m+1)*sizeof(int));
		for(i=0;i<=m;i++){
			for(j=0;j<=m-i;j++){
				for(k=0;k<=i;k++){
					x[i]+=1LL*cmb(m-i,j)*cmb(i,k)%p*v[k+j]%p*v[i-k+j]%p;
					x[i]%=p;
				}
			}
		}
		memcpy(v,x,(m+1)*sizeof(int));
	}
	memcpy(v,r,(m+1)*sizeof(int));
}
void mvmul(int st,int m,int os){
	if(m==0){
		ans[st][21]=ans[st][os];
		return;
	}
	for(int i=0;i<(1<<m-1);i++){
		for(int j=0;j<=m;j++){
			ans[st+i][j+os]+=ans[st+(1<<m)-i-1][m-j+os];
			ans[st+i][j+os]%=p;
		}
	}
	for(int i=0;i<(1<<m-1);i++){
		for(int j=0;j<=m;j++){
			ans[st+i+(1<<m-1)][j+os]=ans[st+i][j+os];
		}
	}
	mvmul(st,m-1,os);
	mvmul(st+(1<<m-1),m-1,os+1);
}
			
int main(){
	int m,b[30],i,j;
	long long t;
	scanf("%d%I64d%d",&m,&t,&p);
	for(i=0;i<(1<<m);i++) scanf("%d",&e[i]);
	for(i=0;i<=m;i++) scanf("%d",&b[i]);
	mpow(b,m,t);
	for(i=0;i<(1<<m);i++){
		for(j=0;j<=m;j++){
			ans[i][j]=1LL*b[j]*e[i]%p;
		}
	}
	mvmul(0,m,0);
	for(i=0;i<(1<<m);i++){
		printf("%d\n",ans[i][21]);
	}
	return 0;
}