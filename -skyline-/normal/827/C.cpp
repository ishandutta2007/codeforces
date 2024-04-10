#include<bits/stdc++.h>
using namespace std;
int t[11][4][100005],n,f[11][100005],tr[200],q,a[100005],b[20];
void add(int*t,int x,int k){while(x<=n)t[x]+=k,x+=(x&-x);}
int get(int*t,int x){int s=0;while(x)s+=t[x],x-=(x&-x);return s;}
int main(){
	tr['T']=1,tr['G']=2,tr['C']=3;char c=getchar();while(c!='\n')a[++n]=tr[c],c=getchar();
	for(int k=1;k<=10;++k){int s=0;for(int i=1;i<=k;++i){for(int j=i;j<=n;j+=k)add(t[k][a[j]],f[k][j]=++s,1);}}
	scanf("%d",&q);
	while(q--){
		int T;
		scanf("%d",&T);
		if(T==1){int x;char c;scanf("%d %c",&x,&c);for(int k=1;k<=10;++k)add(t[k][a[x]],f[k][x],-1);a[x]=tr[c];for(int k=1;k<=10;++k)add(t[k][a[x]],f[k][x],1);continue;}
		int l,r,o=0,s=0;scanf("%d%d",&l,&r),getchar();char c=getchar();while(c!='\n')b[++o]=tr[c],c=getchar();
		for(int i=min(r,l+o-1);i>=l;--i){int j=(r-i)/o*o+i;s+=get(t[o][b[i-l+1]],f[o][j])-get(t[o][b[i-l+1]],f[o][i]-1);}
		printf("%d\n",s);
	}
	return 0;
}