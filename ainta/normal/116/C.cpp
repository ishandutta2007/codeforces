#include<stdio.h>
int p[10000],n,i,j,oo[10000],o[10000],c,tc,cc,v[10000];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&p[i]);if(p[i]!=-1)oo[i]=o[i]=1;
	}
	while(1){
		cc++;
		tc=0;
		for(i=1;i<=n;i++){if(o[i]==0&&v[i]==0){v[i]=1;c++;for(j=1;j<=n;j++)if(p[j]==i)oo[j]=0;}}
		for(i=1;i<=n;i++){o[i]=oo[i];if(v[i]==0)tc=1;}
		if(!tc)break;}
	printf("%d\n",cc);
}