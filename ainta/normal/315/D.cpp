#include<stdio.h>
#include<string.h>
int n,m,a,b,i,j,w[101][101],w2[101][101],t,T1,T2;
char p[110],q[110];
int main()
{
	scanf("%d%d",&a,&b);
	scanf("%s%s",p,q);
	n=strlen(p),m=strlen(q);
	int pv=0;
	for(i=0;i<n;i++)for(j=0;j<m;j++)w[i][j]=-1;
	for(i=0;i<n*a;i++){
		if(!pv && i>=n)break;
		if(p[i%n]==q[pv%m]){
			if(w[i%n][pv%m]!=-1)break;
			w[i%n][pv%m]=i,w2[i%n][pv%m]=pv;
			pv++;
		}
	}
	if(i==n*a || !pv){
		printf("%d\n",pv/m/b);
		return 0;
	}
	t=n*a-(i+1);
	T1=i-w[i%n][pv%m];
	T2=pv-w2[i%n][pv%m];
	t/=T1;
	i+=T1*t;
	pv+=T2*t;
	i++,pv++;
	for(i=i;i<n*a;i++){
		if(p[i%n]==q[pv%m])pv++;
	}
	printf("%d\n",pv/m/b);
}