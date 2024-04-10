#include<stdio.h>
int n,r,i,x,y,p,M,save[1000001],S,tp[1000001],c,sc,j;
int main(){
	scanf("%d%d",&n,&r);
	M=n+1;
	for(i=r;i>=1;i--){
		x=r,y=i,p=n-1;
		c=0,S=0;
		while(x>0&&y>0&&x+y>0&&p>0){
			p--;
			if(x>y){x=x-y;tp[++c]=1;}
			else{y=y-x;tp[++c]=2;}
			if(tp[c]==tp[c-1])S++;}
		if(x==1&&y==1){
			if(S<M){
				M=S,sc=c+1;
				if(tp[c]==2){
					for(j=1;j<=c;j++)save[j]=tp[j];save[sc]=1;}
				else{
					for(j=1;j<=c;j++)save[j]=3-tp[j];save[sc]=1;}
			}
		}
	}
	if(M==n+1){
		printf("IMPOSSIBLE\n");
		return 0;
	}
	printf("%d\n",M);
	for(i=n;i>=1;i--){
		if(save[i]==1)printf("T");
		else printf("B");
	}
}