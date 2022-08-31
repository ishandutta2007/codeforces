#include<stdio.h>
#include<algorithm>
using namespace std;
int w[200001],i,n;
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&w[i]);
	stable_sort(w,w+n);
	for(i=0;i<n-1;i++) if(w[i+1]>w[i]&&w[i+1]<w[i]*2) break;
	if(i==n-1)printf("NO\n");
	else printf("YES\n");
}