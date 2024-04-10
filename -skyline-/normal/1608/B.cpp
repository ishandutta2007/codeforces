#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n,x,y,a[200005],b[200005];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&x,&y);
		if(x==0&&y==0){
			for(int i=1;i<n;++i)printf("%d ",i);
			printf("%d\n",n);
			continue;
		}
		if(x+y>n-2||abs(x-y)>1){
			printf("-1\n");
			continue;
		}
		if(x>=y){
			int l=x+1,r=n-y;
			for(int i=1;i<=n-x-y;++i)a[i]=x+i;
			int t=n-x-y;
			for(int i=1;i<=x;++i){
				a[++t]=--l;
				if(y)a[++t]=++r,--y;
			}
		}
		else{
			int l=x+1,r=n-y;
			for(int i=1;i<=n-x-y;++i)a[i]=r+1-i;
			int t=n-x-y;
			for(int i=1;i<=y;++i){
				a[++t]=++r;
				if(x)a[++t]=--l,--x;
			}
		}
		for(int i=1;i<n;++i)printf("%d ",a[i]);
		printf("%d\n",a[n]);
	}
    return 0;
}