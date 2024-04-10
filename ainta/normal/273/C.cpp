#include<stdio.h>
int n,m,i,w[300001][3],C[300001],Q[1000000],h,t,x,p,C2[300001];
bool O[300001];
int main()
{
	int a,b;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		w[a][C[a]++]=b;
		w[b][C[b]++]=a;
	}
	for(i=1;i<=n;i++){
		if(C[i]>1)Q[++t]=i;
		C2[i]=C[i];
	}
	while(h<t){
		while(h<t && C[Q[h+1]]<2)h++;
		if(h==t)break;
		x=Q[++h];
		O[x]=!O[x];
		for(i=0;i<C2[x];i++){
			p=w[x][i];
			if(O[p]!=O[x])C[p]--;
			else{
				C[p]++;
				if(C[p]==2)Q[++t]=p;
			}
		}
		C[x]=C2[x]-C[x];
	}
	for(i=1;i<=n;i++){
		if(O[i])printf("1");
		else printf("0");
	}
	return 0;
}