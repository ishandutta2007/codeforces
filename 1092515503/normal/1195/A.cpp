#include<bits/stdc++.h>
using namespace std;
int n,k,t,num[1001],tot;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&t),num[t]++;
	for(int i=1;i<=k;i++)tot+=num[i]&1;
	printf("%d\n",n-tot/2);
	return 0;
}