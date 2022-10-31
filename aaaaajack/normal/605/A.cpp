#include<cstdio>
#include<algorithm>
#include<utility>
#define N 100100
using namespace std;
int pos[N];
int main(){
	int n,x,ans=0,tmp=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		pos[x]=i;
	}
	for(int i=1;i<=n;i++){
		if(i==1||pos[i]>pos[i-1]) tmp++;
		else tmp=1;
		if(tmp>ans) ans=tmp;
	}
	printf("%d\n",n-ans);
	return 0;
}