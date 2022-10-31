#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
	int n,m,r,i,j,k,l,s,t,fx[110][110]={0},fy[110][110]={0},py;
	char next,pre,mat[110][110]={0};
	bool flag;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(mat[i][j]) continue;
			if(mat[i-1][j]!='A'&&mat[i][j-1]!='A'&&mat[i][j+1]!='A'&&mat[i+1][j]!='A') next='A';
			else if(mat[i-1][j]!='B'&&mat[i][j-1]!='B'&&mat[i][j+1]!='B'&&mat[i+1][j]!='B') next='B';
			else if(mat[i-1][j]!='C'&&mat[i][j-1]!='C'&&mat[i][j+1]!='C'&&mat[i+1][j]!='C') next='C';
			else if(mat[i-1][j]!='D'&&mat[i][j-1]!='D'&&mat[i][j+1]!='D'&&mat[i+1][j]!='D') next='D';
			else next='E';
			pre=mat[i][j-1];
			py=fy[i][j-1];
			l=j-py;
			flag=false;
			if(pre&&pre<next&&fx[i][j-1]==i&&py){
				flag=true;
				if(i+l>n) flag=false;
				for(k=0;k<=l;k++){
					if(mat[i+l][py+k]||mat[i+k][j]) flag=false;
					if(mat[i+l+1][py+k]==pre||mat[i+k][j+1]==pre) flag=false;
				}
				if(mat[i+l][py-1]==pre||mat[i-1][j]==pre) flag=false;
			}
			if(flag){
				for(k=0;k<=l;k++){
					mat[i+l][py+k]=pre;
					fx[i+l][py+k]=i;
					fy[i+l][py+k]=py;
					mat[i+k][j]=pre;
					fx[i+k][j]=i;
					fy[i+k][j]=py;
				}
			}
			else{
				mat[i][j]=next;
				fx[i][j]=i;
				fy[i][j]=j;
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			putchar(mat[i][j]);
		}
		putchar('\n');
	}
	return 0;
}