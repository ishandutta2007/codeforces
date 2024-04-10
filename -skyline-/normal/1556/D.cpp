#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,k,a[10005],f[10005],g[10005],A,O;
int main(){
	scanf("%d%d",&n,&k);
	
	for(int i=2;i<=n;++i){
		printf("and 1 %d\n",i);
		fflush(stdout);
		scanf("%d",f+i);
		
		printf("or 1 %d\n",i);
		fflush(stdout);
		scanf("%d",g+i);
	}
	
		printf("and 2 3\n");
		fflush(stdout);
		scanf("%d",&A);
		
		printf("or 2 3\n");
		fflush(stdout);
		scanf("%d",&O);
	for(int i=0;i<30;++i){
		int x=g[2],y=g[3];
		x=(x>>i)&1;
		y=(y>>i)&1;
		bool ok=1;
		if(((f[2]>>i)&1)&&((f[3]>>i)&1))ok=0;
		if((x&y)==((A>>i)&1)&&(x|y)==((O>>i)&1)&&ok){
			for(int j=2;j<=n;++j)a[j]+=(((g[j]>>i)&1)<<i);
		}
		else{
			for(int j=2;j<=n;++j)a[j]+=(((f[j]>>i)&1)<<i);
			a[1]+=(1<<i);
		}
	}
	sort(a+1,a+n+1);
	printf("finish %d\n",a[k]);
		fflush(stdout);
    return 0;
}