#include<stdio.h>
int n,k,i,c,C;
int main()
{
	scanf("%d%d",&n,&k);
	if(k*3>n || k==1){printf("-1\n");return 0;}
	c=-1;
	for(i=1;i<=n;i++){
		c+=2;
		if(c>k){
			C++;
			c-=k;
			if(k&1){
				if(C%4==2)c++;
				if(C%4==0)c--;
			}
			else{
				if(C%4==1)c++;
				if(C%4==3)c--;
			}
		}
		printf("%d ",c);
	}
	return 0;
}