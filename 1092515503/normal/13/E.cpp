#include<bits/stdc++.h>
using namespace std;
int n,m,BBB,to[101000],tim[101000],jump[100100],BLK[100100];
void Work(int x){
	if(x+jump[x]>=n)to[x]=-1,tim[x]=1;
	else if(BLK[x+jump[x]]!=BLK[x])to[x]=x+jump[x],tim[x]=1;
	else to[x]=to[x+jump[x]],tim[x]=tim[x+jump[x]]+1;
}
void Change(int x){
	for(int i=x;i>=BLK[x]*BBB;i--)Work(i);
}
int main(){
	scanf("%d%d",&n,&m),BBB=sqrt(n);
	for(int i=0;i<n;i++)scanf("%d",&jump[i]),BLK[i]=i/BBB;
	for(int i=n-1;i>=0;i--)Work(i);
	for(int i=1,t1,t2,t3;i<=m;i++){
		scanf("%d",&t1);
		if(t1==0)scanf("%d%d",&t2,&t3),t2--,jump[t2]=t3,Change(t2);
		else{
			scanf("%d",&t2),t2--;
			int s=0;
			while(to[t2]!=-1)s+=tim[t2],t2=to[t2];
			s+=tim[t2];
			while(t2+jump[t2]<n)t2+=jump[t2];
			printf("%d %d\n",t2+1,s);
		}
	}
	return 0;
}