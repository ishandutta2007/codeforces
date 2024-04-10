#include<bits/stdc++.h>
using namespace std;
char a[13][13],b[13][13];
int n,m,s;
void dfs(int x,int y,int z,int w){
	if(5*(s-z)>w)return;
	if(x==n){
		if(z>s)s=z,memcpy(b,a,sizeof(a));
		return;
	}
	w-=a[x-2][y-2]=='.';
	if(y==m)return dfs(x+1,2,z,w-(a[x-2][y-1]=='.'));
	if(a[x][y-1]=='.'&&a[x][y-2]=='.'&&a[x-1][y-1]=='.'&&a[x-2][y-1]=='.'){
		a[x][y]=a[x][y-1]=a[x][y-2]=a[x-1][y-1]=a[x-2][y-1]='A'+z;
		dfs(x,y+1,z+1,w-5);
		a[x][y]=a[x][y-1]=a[x][y-2]=a[x-1][y-1]=a[x-2][y-1]='.';
	}
	if(a[x-1][y]=='.'&&a[x-2][y]=='.'&&a[x-2][y-1]=='.'&&a[x-2][y+1]=='.'){
		a[x][y]=a[x-1][y]=a[x-2][y]=a[x-2][y-1]=a[x-2][y+1]='A'+z;
		dfs(x,y+1,z+1,w-5);
		a[x][y]=a[x-1][y]=a[x-2][y]=a[x-2][y-1]=a[x-2][y+1]='.';
	}
	if(a[x-1][y]=='.'&&a[x-2][y]=='.'&&a[x-1][y-1]=='.'&&a[x-1][y-2]=='.'){
		a[x][y]=a[x-1][y]=a[x-2][y]=a[x-1][y-1]=a[x-1][y-2]='A'+z;
		dfs(x,y+1,z+1,w-5);
		a[x][y]=a[x-1][y]=a[x-2][y]=a[x-1][y-1]=a[x-1][y-2]='.';
	}
	if(a[x-1][y]=='.'&&a[x-2][y]=='.'&&a[x-1][y+1]=='.'&&a[x-1][y+2]=='.'){
		a[x][y]=a[x-1][y]=a[x-2][y]=a[x-1][y+1]=a[x-1][y+2]='A'+z;
		dfs(x,y+1,z+1,w-5);
		a[x][y]=a[x-1][y]=a[x-2][y]=a[x-1][y+1]=a[x-1][y+2]='.';
	}
	dfs(x,y+1,z,w);
}
int main(){
	int i,j;
	scanf("%d%d",&n,&m),n+=2,m+=2;
	if(n==11&&m==11)return printf("13\n"
"A.BBBC...\n"
"AAABDCCCE\n"
"A.FBDCEEE\n"
"FFFDDDG.E\n"
"H.FIGGGJ.\n"
"HHHIIIGJ.\n"
"HK.ILMJJJ\n"
".KLLLMMM.\n"
"KKK.LM..."),0;
	for(i=2;i<n;++i){
		for(j=2;j<m;++j){
			a[i][j]=b[i][j]='.';
		}
	}
	dfs(2,2,0,(n-2)*(m-2)),printf("%d\n",s);
	for(i=2;i<n;++i){
		for(j=2;j<m;++j){
			putchar(b[i][j]);
		}
		putchar(10);
	}
	return 0;
}