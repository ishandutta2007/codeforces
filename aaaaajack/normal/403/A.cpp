#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int t,n,p,i,j;
	bool con[32][32];
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&p);
		memset(con,0,sizeof(con));
		for(i=1;i<=5;i++){
			for(j=i+1;j<=5;j++){
				con[i][j]=true;
			}
		}
		for(i=6;i<=n;i++){
			con[1][i]=con[2][i]=true;
		}
		for(i=1;i<=n;i++){
			if(!p) break;
			for(j=i+1;j<=n;j++){
				if(!p) break;
				if(!con[i][j]){
					con[i][j]=true;
					p--;
				}
			}
		}
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				if(con[i][j]) printf("%d %d\n",i,j);
			}
		}
	}
	return 0;
}