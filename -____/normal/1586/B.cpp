#include<bits/stdc++.h>
using namespace std;
const int N = 222222;
int n,m,a[N];
int main(){
	int T,i,x,y,z;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i++)
			scanf("%d%d%d",&x,&y,&z),a[y]=1;
		for(i=1;i<=n;i++){
			if(!a[i])
				x=i;
			else
				a[i]=0;
		}
		for(i=1;i<=n;i++)
			if(i!=x)
				printf("%d %d\n",x,i);
	}
	return 0;
}