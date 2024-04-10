#include<stdio.h>
#include<algorithm>
using namespace std;
int n,w[100001],i,j;
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&w[i]);
	stable_sort(w,w+n);
	if(w[n-1]!=1) w[n-1]=1;
	else w[n-1]=2;
	stable_sort(w,w+n);
	for(i=0;i<n;i++)printf("%d ",w[i]);
}