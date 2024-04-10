#include<cstdio>
#include<cstring>
#define N 60
using namespace std;
bool cant[N*2][N*2];
char s[N][N],t[N][N];
int main(){
	int n,i,j,k,l;
	bool wrong=false;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",s[i]);
	}
	memset(t,'.',sizeof(t));
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(s[i][j]=='o'){
				t[i][j]='o';
				for(k=0;k<n;k++){
					for(l=0;l<n;l++){
						if(s[k][l]=='.'){
							cant[n+k-i][n+l-j]=true;
						}
					}
				}
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(s[i][j]=='o'){
				for(k=-n+1;k<=n-1;k++){
					for(l=-n+1;l<=n-1;l++){
						if(!cant[k+n][l+n]&&i+k>=0&&i+k<n&&j+l>=0&&j+l<n&&t[i+k][j+l]=='.'){
							t[i+k][j+l]='x';
						}
					}
				}
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(s[i][j]!=t[i][j]) wrong=true;
		}
	}
	if(wrong) puts("NO");
	else{
		puts("YES");
		for(i=1;i<=2*n-1;i++){
			for(j=1;j<=2*n-1;j++){
				if(i==n&&j==n) printf("o");
				else if(cant[i][j]) printf(".");
				else printf("x");
			}
			putchar('\n');
		}
	}
	return 0;
}