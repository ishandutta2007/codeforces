#include<bits/stdc++.h>
using namespace std;
void mul(long long mat[4][4],long long v[4],long long t,int n){
	long long tm[4][4];
	long long tv[4];
	while(t){
		if(t&1){
			for(int i=0;i<4;i++) tv[i]=(mat[i][0]*v[0]%n+mat[i][1]*v[1]%n+mat[i][2]*v[2]%n+mat[i][3]*v[3]%n)%n;
			for(int i=0;i<4;i++) v[i]=tv[i];
		}
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				tm[i][j]=(mat[i][0]*mat[0][j]%n+mat[i][1]*mat[1][j]%n+mat[i][2]*mat[2][j]%n+mat[i][3]*mat[3][j]%n)%n;
			}
		}
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				mat[i][j]=tm[i][j];
			}
		}
		t>>=1;
	}
}
int main(){
	int n;
	long long sx,sy,dx,dy;
	long long t;
	scanf("%d%lld%lld%lld%lld%lld",&n,&sx,&sy,&dx,&dy,&t);
	sx--,sy--;
	long long d=(dy-dx)%n;
	if(d<0) d+=n;
	long long mat[4][4]={{0,1,0,0},{n-1,4%n,(d+1)%n,((d+3+sy-sx)%n+n)%n},{0,0,1,1},{0,0,0,1}};
	long long v[4]={sx,(sx+dx+sx+sy+2)%n,0,1};
	if(v[1]<0) v[1]+=n;
	mul(mat,v,t,n);
	long long x=v[0],y=(x+(sy-sx)+d*(t%n))%n;
	if(y<0) y+=n;
	printf("%lld %lld\n",x+1,y+1);
	return 0;
}