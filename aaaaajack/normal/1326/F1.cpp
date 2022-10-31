#include<bits/stdc++.h>
#define N 14
using namespace std;
int stc[1<<N][N][1<<7];
int edc[1<<N][N][1<<6];
int dig[1<<N];
int rev[1<<N];
long long ans[1<<N];
char s[N+100][N+100];
void search(int i, int n, int last, int st, int vis){
	if(i==n/2){
		//printf("ed %d %d %d\n",last,vis,rev[st]);
		edc[vis][last][rev[st]]++;
	}
	if(i==(n+1)/2){
		for(int j=0;j<n;j++){
			if(vis&(1<<j)) continue;
			stc[vis][j][st<<1|s[last][j]]++;
			//printf("st %d %d %d\n",j,vis,st<<1|s[last][j]);
		}
		return;
	}
	for(int j=0;j<n;j++){
		if(vis&(1<<j)) continue;
		search(i+1,n,j,st<<1|s[last][j],vis|(1<<j));
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);
		for(int j=0;j<n;j++) s[i][j]-='0';
	}
	for(int i=1;i<(1<<n);i++){
		dig[i]=dig[i^(i&-i)]+1;
	}
	for(int i=0;i<(1<<n/2-1);i++){
		for(int j=0;j<(n/2-1);j++){
			rev[i]<<=1;
			if(i&(1<<j)){
				rev[i]|=1;
			}
		}
		//printf("%d %d\n",i,rev[i]);
	}
	search(0,n,n,0,0);
	int msk=(1<<n)-1,low=(1<<n/2-1)-1;
	if(low<0) low=0;
	for(int i=0;i<(1<<n);i++){
		if(dig[i]!=(n+1)/2) continue;
		int j=i^msk;
		for(int l=0;l<n;l++){
			if(i&(1<<l)) continue;
			for(int st=0;st<(1<<n-1);st++){
				if(!stc[i][l][st>>n/2-1]){
					st+=low;
					continue;
				}
				ans[st]+=1LL*stc[i][l][st>>n/2-1]*edc[j][l][st&low];
			}
		}
	}
	for(int i=0;i<(1<<n-1);i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}