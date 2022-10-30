#include<cstdio>
#define N 110
int val[N][N];
using namespace std;
int main(){
	int n,m,i,j,cnt=0;
	char s[N];
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%s",s);
		for(j=0;j<m;j++){
			if(s[j]=='B') val[i][j]=1;
			else val[i][j]=-1;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			val[i][j]-=val[i][j+1]+val[i+1][j]-val[i+1][j+1];
			if(val[i][j]) cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}