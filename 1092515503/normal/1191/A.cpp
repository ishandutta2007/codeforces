#include<bits/stdc++.h>
using namespace std;
int n,mst,pls;
bool cmp(int a,int b){
	if(a==1)return true;
	if(b==1)return false;
	if(a==3)return true;
	if(b==3)return false;
	if(a==2)return true;
	if(b==2)return false;
	return true;
}
int main(){
	scanf("%d",&n);
	mst=n%4,pls=0;
	for(int i=1;i<=2;i++)if(cmp((n+i)%4,mst))mst=(n+i)%4,pls=i;
	if(mst==1)printf("%d %c\n",pls,'A');
	if(mst==2)printf("%d %c\n",pls,'C');
	if(mst==3)printf("%d %c\n",pls,'B');
	if(mst==0)printf("%d %c\n",pls,'D');
	return 0;
}