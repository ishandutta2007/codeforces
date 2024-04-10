#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define Q 998244353
#define N 1001000
using namespace std;
int dp[22][N];
int sx[2]={1,999},sy[2]={1,999};
int mx[2]={-1,1},my[2]={-1,1};
int cx[2],cy[2],ov[2][2];
int rx[1000],ry[1000];
bool in[1000][1000];
int main(){
	int kx,ky,x,y,z=100,dx=-1,dy=-1;
	scanf("%d%d",&kx,&ky);
	for(int i=1;i<=666;i++){
		scanf("%d%d",&rx[i],&ry[i]);
		in[rx[i]][ry[i]]=true;
	}

	while(z>0 && (kx!=500||ky!=500)){	
		int px=kx,py=ky;
		if(kx<500) kx++;
		else if(kx>500) kx--;
		if(ky<500) ky++;
		else if(ky>500) ky--;
		if(in[kx][ky]) kx=px;
		printf("%d %d\n",kx,ky);
		fflush(stdout);
		scanf("%d%d%d",&z,&x,&y);
		if(z>0){
			in[rx[z]][ry[z]]=false;
			rx[z]=x,ry[z]=y;
			in[x][y]=true;
		}
	}
	if(z>0){
		for(int i=1;i<=666;i++){
			int tx,ty;
			if(rx[i]<kx) tx=0;
			else tx=1;
			if(ry[i]<ky) ty=0;
			else ty=1;
			cx[tx]++,cy[ty]++,ov[tx][ty]++;
 		}
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				if(cx[i]+cy[j]-ov[i][j]>499){
					dx=i,dy=j;
				}
			}
		}
		assert(dx>=0&&dy>=0);
		do{
			kx+=mx[dx],ky+=my[dy];
			assert(kx>=1&&kx<=999&&ky>=1&&ky<=999);
			if(in[kx][ky]) kx-=mx[dx];
			printf("%d %d\n",kx,ky);
			fflush(stdout);
			scanf("%d%d%d",&z,&x,&y);
			if(z>0){
				in[rx[z]][ry[z]]=false;
				rx[z]=x,ry[z]=y;
				in[x][y]=true;
			}
		}while(z>0);
		assert(z<0);
	}
	return 0;
}