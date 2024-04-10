#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#define fi   first
#define se   second
using namespace std;
int T,n,a[105],u[20],d[20];
int main(){
	for(int i=1;i<=9;++i)u[i]=i-1;
	u[0]=9;
	for(int i=0;i<9;++i)d[i]=i+1;
	d[9]=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		for(int i=1;i<=n;++i){
			int k;
			scanf("%d",&k);
			for(int j=1;j<=k;++j){
				char c;
				scanf(" %c",&c);
				if(c=='U')a[i]=u[a[i]];
				else a[i]=d[a[i]];
			}
		}
		for(int i=1;i<n;++i)printf("%d ",a[i]);
		printf("%d\n",a[n]);
	}
    return 0;
}