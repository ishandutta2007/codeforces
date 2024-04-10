#include<bits/stdc++.h>
using namespace std;
int n,a[2500];
int Query(int x,int y){
	printf("? %d %d\n",x,y),fflush(stdout);
	int z;
	scanf("%d",&z);
	return z;
}
int Rnd(int x){
	int y=rand()%n+1;
	while(x==y)y=rand()%n+1;
	return y; 
}
int Get(int x){
	int Ful=(1<<11)-1;
	for(int i=0;i<15;i++)Ful&=Query(x,Rnd(x));
	return Ful;
}
int main(){
	srand(17680321);
	scanf("%d",&n);
	int p=rand()%n+1,v=Get(p);
	for(int i=1;i<=n;i++){
		if(i==p)continue;
		if((Query(i,p)|v)!=v)continue;
		p=i,v=Get(i);
	}
	for(int i=1;i<=n;i++)a[i]=((i==p)?0:Query(p,i));
	printf("!");
	for(int i=1;i<=n;i++)printf(" %d",a[i]);
	puts("");fflush(stdout);
	return 0;
}