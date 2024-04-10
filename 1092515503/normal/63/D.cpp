#include<bits/stdc++.h>
using namespace std;
int g[101][101],n,a,b,c,d,num[51];
void next(int &x,int &y){
	if(y<=a){
		if(x==1){y++;return;}
		if(x&1){
			if(y!=a){y++;return;}
			else {x--;return;}
		}else{
			if(y!=1){y--;return;}
			else {x--;return;}
		}
	}else{
		if(x&1){
			if(y!=a+c){y++;return;}
			else {x++;return;}
		}else{
			if(y!=a+1){y--;return;}
			else {x++;return;}
		}
	}
}
int main(){
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&n);
	for(int i=1;i<=n;i++)scanf("%d",&num[i]);
	int x,y;
	if(b&1)x=b,y=1;
	else x=b,y=a;
	for(int i=1;i<=n;i++)for(int j=1;j<=num[i];j++)g[x][y]=i,next(x,y);
	puts("YES");
	for(int i=1;i<=max(b,d);i++){
		for(int j=1;j<=a+c;j++){
			if(!g[i][j])putchar('.');
			else putchar(g[i][j]+'a'-1);
		}
		putchar('\n');
	}
	return 0;
}