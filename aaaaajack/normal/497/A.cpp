#include<cstdio>
#define N 1030
using namespace std;
char s[N][N];
bool gt[N];
int main(){
	int m,n,i,j,cnt=0;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++) scanf("%s",s[i]);
	for(j=0;j<n;j++){
		for(i=1;i<m;i++){
			if(!gt[i]) break;
		}
		if(i==m) break;
		for(i=1;i<m;i++){
			if(!gt[i]&&s[i][j]<s[i-1][j]) break;
		}
		if(i<m){
			cnt++;
		}
		else{
			for(i=1;i<m;i++){
				if(s[i][j]>s[i-1][j]) gt[i]=true;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}