#include<cstdio>
using namespace std;
int T,n,k,x;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			if(x>=k*10)printf("YES\n");
			else{
				bool flag=0;
				while(x>=k)if(x%10==k){flag=1;break;}else x-=k;
				if(flag)printf("YES\n");
				else printf("NO\n");
			}
		}
	}
	return 0;
}