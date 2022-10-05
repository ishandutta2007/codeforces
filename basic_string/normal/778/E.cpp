#include<bits/stdc++.h>
using namespace std;
const int N=1007;
char a[N],b[N][N];
int c[13],u[N],v[N],x[N],y[N],t[13];
#define to(_) ((_)?((_)-'0'):0)
#define mo(_) ((_)>9?((_)-10):(_))
int main(){
	int n,i,j,k,l,o,w,m=0,*f=u,*g=v,*p=x,*q=y;
	scanf("%s%d",a+1,&n),reverse(a+1,a+(l=strlen(a+1))+1),m=max(m,l),memset(f+1,-63,n*4);
	for(i=1;i<=n;++i)scanf("%s",b[i]+1),p[i]=i,reverse(b[i]+1,b[i]+strlen(b[i]+1)+1),m=max(m,(int)strlen(b[i]+1));
	for(i=0,++m;i<=9;++i)scanf("%d",c+i);
	for(i=1;swap(f,g),swap(p,q),memset(t,0,52),memset(f,-63,n*4+4),i<=m;++i){
		for(j=1;j<=n;++j)++t[to(b[j][i])];
		for(j=1;j<=9;++j)t[j]+=t[j-1];
		for(j=1;j<=n;++j)p[n-(--t[to(b[q[j]][i])])]=q[j];
		for(j=(a[i]=='?'?(i==l):to(a[i]));j<=(a[i]=='?'?9:to(a[i]));++j){
			for(o=w=0;o<n&&j+to(b[p[o+1]][i])>9;++o);
			for(k=1;k<=n;++k)if(a[i]||b[k][i])w+=c[mo(j+to(b[k][i]))];
			for(k=1,f[o]=max(f[o],g[0]+w);k<=n;++k){
				if(o<n&&q[k]==p[o+1]&&j+to(b[q[k]][i])>8)++o;
				if(a[i]||b[q[k]][i])w-=c[mo(j+to(b[q[k]][i]))];
				w+=c[mo(j+to(b[q[k]][i])+1)],f[o]=max(f[o],g[k]+w);
			}
		}
	}
	for(i=j=0;i<=n;++i)j=max(j,g[i]);
	printf("%d",j);
	return 0;
}