#include<stdio.h>
int main()
{
	int a,t,v[10],i;
	scanf("%d",&a);
	a++;
	for(;;a++){
		for(i=0;i<10;i++)v[i]=false;
		t=a;
		while(t){
			if(v[t%10])break;
			v[t%10]=true;
			t/=10;
		}
		if(!t){printf("%d\n",a);break;}
	}
}