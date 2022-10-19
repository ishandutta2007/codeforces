#include<bits/stdc++.h>
using namespace std;
const int p=1e9+7;
int pov(int x,int y){
	if(!y)return 1;
	int tmp=pov(x,y>>1);
	tmp=1ll*tmp*tmp%p;
	if(y&1)tmp=1ll*tmp*x%p;
	return tmp; 
}
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	printf("%d\n",pov(pov(2,m)-1,n));
	return 0;
}