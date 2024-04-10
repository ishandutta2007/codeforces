#include<bits/stdc++.h>
using namespace std;
char s[100][100],d[200];
int main(){
	int n,m,pm[4]={0,1,2,3},mx[4]={1,0,-1,0},my[4]={0,1,0,-1},ans=0,sx,sy;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);
		for(int j=0;j<m;j++){
			if(s[i][j]=='S'){
				sx=i,sy=j;
			}
		}
	}
	scanf("%s",d);
	do{
		int tx=sx,ty=sy;
		for(int i=0;d[i];i++){
			tx+=mx[pm[d[i]-'0']];
			ty+=my[pm[d[i]-'0']];
			if(tx<0||tx>=n||ty<0||ty>=m||s[tx][ty]=='#') break;
			else if(s[tx][ty]=='E'){
				ans++;
				break;
			}
		}
	}while(next_permutation(pm,pm+4));
	printf("%d\n",ans);
	return 0;
}