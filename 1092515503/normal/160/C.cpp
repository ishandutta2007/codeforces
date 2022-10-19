#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,num[100010];
signed main(){
	scanf("%I64d%I64d",&n,&k),k--;
	for(int i=0;i<n;i++)scanf("%I64d",&num[i]);
	sort(num,num+n);
	int i,j;
	for(i=0;i<n;i+=j){
		for(j=1;num[i]==num[i+j];j++);
		if(j*n>k)break;
		k-=j*n;
	}
	printf("%I64d %I64d\n",num[i],num[k/j]);
	return 0;
}