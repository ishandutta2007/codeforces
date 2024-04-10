#include<cstdio>
#include<cstring>
using namespace std;
char s[3][120];
int d[3][120];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,k;
		scanf("%d%d",&n,&k);
		memset(d,0,sizeof(d));
		for(int i=0;i<3;i++){
			scanf("%s",s[i]);
			if(s[i][0]=='s') d[i][0]=1;
		}
		for(int i=0;i<n*2;i++){
			for(int j=0;j<3;j++){
				for(int k=0;k<n;k++){
					if(k<n-2&&s[j][k+1]=='.'&&s[j][k+2]=='.'){
						if(d[j][k]&4) d[j][k+2]|=1;
					}
					if(k==n-2&&s[j][n-1]=='.'&&(d[j][k]&4)){
						d[j][k+1]|=1;
					}
					if(k<n-1&&s[j][k+1]=='.'){
						if(d[j][k]&1) d[j][k+1]|=2;
					}
					if(d[j][k]&2){
						if(j>0&&s[j-1][k]=='.') d[j-1][k]|=4;
						if(j<2&&s[j+1][k]=='.') d[j+1][k]|=4;
						d[j][k]|=4;
					}
				}
			}
		}
		if(d[0][n-1]||d[1][n-1]||d[2][n-1]) puts("YES");
		else puts("NO");
	}
	return 0;
}