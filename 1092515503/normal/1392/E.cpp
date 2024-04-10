#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
bool tp[50][50];
ll a[50][50],q;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)for(int j=0;j<n;j++){
		if(j&1)continue;
		if(i+j)a[i][j]=1ll<<(i+j-1);
	}
	for(int i=0;i<n;i++){for(int j=0;j<n;j++)printf("%I64d ",a[i][j]);puts(""),fflush(stdout);}
	scanf("%d",&m);
	while(m--){
		scanf("%I64d",&q);
		int x=0,y=0;
		printf("%d %d\n",x+1,y+1);fflush(stdout);
		for(int i=0;i<=2*n-3;i++){
			if(x+1<n&&(a[x+1][y]==(q&(1ll<<i))))x++;else y++;
			printf("%d %d\n",x+1,y+1);fflush(stdout);
		}
	}
	return 0;
}