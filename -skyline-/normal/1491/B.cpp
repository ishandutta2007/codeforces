#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int t,n,u,v,a[105];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&u,&v);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		int x=0;
		for(int i=2;i<=n;++i)x=max(x,abs(a[i]-a[i-1]));
		if(x>1)printf("0\n");
		else if(x==1)printf("%d\n",min(u,v));
		else printf("%d\n",min(u,v)+v);
	}
    return 0;
}