#include<bits/stdc++.h>
using namespace std;
const int N=99999;
char s[N],t[N];
int main(){
	int T,n,m,i,j,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m),m=min(m,n),k=-1e9;scanf("%s",s+1);
		s[0]=s[n+1]=0;
		for(i=1;i<=m;++i){
			for(j=1;j<=n;++j){
				k=0;
				if(s[j-1]=='1')++k;
				if(s[j+1]=='1')++k;
				if(k==1)t[j]='1';
				else t[j]=s[j];
			}
			for(j=1;j<=n;++j)swap(s[j],t[j]);
		}
		for(i=1;i<=n;++i)putchar(s[i]);putchar(10);
	}
	
	return 0;
}