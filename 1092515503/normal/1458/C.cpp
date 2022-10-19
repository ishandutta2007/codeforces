#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[1010][1010],b[1010][1010],p[3],d[3],t[3];
char s[100100];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&a[i][j]),a[i][j]--;
		scanf("%s",s);
		for(int i=0;i<3;i++)p[i]=i,d[i]=0;
		for(int i=0;i<m;i++){
			if(s[i]=='U')(d[p[0]]+=n-1)%=n;
			if(s[i]=='D')(++d[p[0]])%=n;
			if(s[i]=='L')(d[p[1]]+=n-1)%=n;
			if(s[i]=='R')(++d[p[1]])%=n;
			if(s[i]=='I')swap(p[1],p[2]);
			if(s[i]=='C')swap(p[0],p[2]);
		}
		for(t[0]=0;t[0]<n;t[0]++)for(t[1]=0;t[1]<n;t[1]++){
			t[2]=a[t[0]][t[1]];
			b[(t[p[0]]+d[p[0]])%n][(t[p[1]]+d[p[1]])%n]=(t[p[2]]+d[p[2]])%n;
		}
		for(int i=0;i<n;i++){for(int j=0;j<n;j++)printf("%d ",b[i][j]+1);puts("");}puts("");
	}
	return 0;
}