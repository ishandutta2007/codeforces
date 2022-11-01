//by dxm
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)

int n,k;
map<int,int>mp;
int main(){
	int n;scanf("%d%d",&n,&k);
	rep1(i,k+1){
		int pos,ca;
		printf("?");rep1(j,k+1)if(j!=i)printf(" %d",j);printf("\n");fflush(stdout);
		scanf("%d%d",&pos,&ca);mp[ca]++;
	}
	printf("! %d\n",mp.rbegin()->second);fflush(stdout);
	return 0;
}