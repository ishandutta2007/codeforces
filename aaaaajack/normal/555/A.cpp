#include<cstdio>
using namespace std;
int main(){
	int n,m,k,x,y,ans=0,i,j;
	scanf("%d%d",&n,&k);
	for(i=0;i<k;i++){
		scanf("%d",&m);
		bool con=true;
		y=0;
		for(j=0;j<m;j++,y=x){
			scanf("%d",&x);
			if(!con||x-1!=y){
				con=false;
				if(j) ans+=2;
				else ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}