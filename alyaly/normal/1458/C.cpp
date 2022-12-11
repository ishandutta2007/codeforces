//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define N 1000
//#define inf 999999999
using namespace std;
int T,n,a[N+1][N+1],m,hs,ls,b[N+1],nn[9];
char c[100001];
void mn(int&x){x=(x+n-1)%n+1;}
int s[100001],ps;
void pp(){
	for(int i=hs;;){
		for(int j=ls;;){
			a[i][j]+=nn[5],mn(a[i][j]);
			printf("%d ",a[i][j]);
			j++,mn(j);
			if(j==ls)break;
		}
		printf("\n");
		i++,mn(i);
		if(i==hs)break;
	}
	printf("\n");
}
void bl(int op){
	if(op==0){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				b[a[i][j]]=j;
			}
			for(int j=1;j<=n;j++)a[i][j]=b[j];
		}
	}else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				b[a[j][i]]=j;
			}
			for(int j=1;j<=n;j++)a[j][i]=b[j];
		}
	}
}
void pus(int x){
	if(s[ps]==x)ps--;
	else s[++ps]=x;
	if(ps==6){
		while(ps)s[ps--]=0;
	}
}
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>m;hs=ls=1;memset(nn,0,sizeof(nn));ps=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>a[i][j];
		for(int i=1;i<=m;i++){
			cin>>c[i];
			if(c[i]=='U')nn[3]--,mn(nn[3]);
			else if(c[i]=='D')nn[3]++,mn(nn[3]);
			else if(c[i]=='L')nn[2]--,mn(nn[2]);
			else if(c[i]=='R')nn[2]++,mn(nn[2]);
			else if(c[i]=='I')swap(nn[2],nn[5]),pus(1);
			else swap(nn[3],nn[5]),pus(2);
			//pp();
		}
		hs-=nn[3],mn(hs);
		ls-=nn[2],mn(ls);
		for(int i=1;i<=ps;i++)bl(s[i]-1);
		pp();
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=0;
		while(ps)s[ps--]=0;
	}
    return 0;
}
/*
1
7 20
2 3 4 5 6 7 1
1 2 3 4 5 6 7
3 4 5 6 7 1 2
4 5 6 7 1 2 3
6 7 1 2 3 4 5
5 6 7 1 2 3 4
7 1 2 3 4 5 6
ICICICICICICICICICICIC
*/