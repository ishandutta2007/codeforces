#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,tot,s,x,y,z,sx,sy,q1[539][539],q2[539][539],q3[539][539],q4[539][539],l,r,mid,q[259][539][539],now1,now2,now3,now4;
char _s;
int main(){
//	freopen("1.in","r",stdin);
	register int i,j,k;
	scanf("%d%d%d",&n,&m,&s);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			_s=getchar();
			while(_s<'A'||_s>'Z') _s=getchar();
			if(_s=='R') q1[i][j]++;
			if(_s=='G') q2[i][j]++;
			if(_s=='Y') q3[i][j]++;
			if(_s=='B') q4[i][j]++;
			q1[i][j]+=q1[i-1][j]+q1[i][j-1]-q1[i-1][j-1];
			q2[i][j]+=q2[i-1][j]+q2[i][j-1]-q2[i-1][j-1];
			q3[i][j]+=q3[i-1][j]+q3[i][j-1]-q3[i-1][j-1];
			q4[i][j]+=q4[i-1][j]+q4[i][j-1]-q4[i-1][j-1];
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			for(k=1;k<=min(n-i+1,m-j+1)/2;k++){
			    now1=q1[i+k-1][j+k-1]-q1[i+k-1][j-1]-q1[i-1][j+k-1]+q1[i-1][j-1];
				now2=q2[i+k-1][j+2*k-1]-q2[i+k-1][j+k-1]-q2[i-1][j+2*k-1]+q2[i-1][j+k-1];
				now3=q3[i+2*k-1][j+k-1]-q3[i+2*k-1][j-1]-q3[i+k-1][j+k-1]+q3[i+k-1][j-1];
				now4=q4[i+2*k-1][j+2*k-1]-q4[i+2*k-1][j+k-1]-q4[i+k-1][j+2*k-1]+q4[i+k-1][j+k-1];
				if(now1==k*k&&now2==k*k&&now3==k*k&&now4==k*k){q[k][i][j]++;break;}
			}
		}
	}
	for(i=1;i<=min(n,m)/2;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=m;k++){
				q[i][j][k]+=q[i][j-1][k]+q[i][j][k-1]-q[i][j-1][k-1];
			}
		}
	}
	while(s--){
		scanf("%d%d%d%d",&x,&y,&sx,&sy);
		l=0;r=min(sx-x+1,sy-y+1)/2+1;
		while(l+1<r){
			mid=(l+r)>>1;
			//printf("%d %d %d %d\n",l,r,mid,q[mid][sx-2*mid+1][sy-2*mid+1]-q[mid][x-1][sy-2*mid+1]-q[mid][sx-2*mid+1][y-1]+q[mid][x-1][y-1]);
			if(q[mid][sx-2*mid+1][sy-2*mid+1]-q[mid][x-1][sy-2*mid+1]-q[mid][sx-2*mid+1][y-1]+q[mid][x-1][y-1]) l=mid;
			else r=mid;
		}
		printf("%d\n",4*l*l);
	}
}