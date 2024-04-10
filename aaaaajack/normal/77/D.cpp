#include<bits/stdc++.h>
#define N 1010
#define Q 1000000007
using namespace std;
char a[N][N];
int ish[N][N];
long long c1[N],c2[N];
char hoz[3][3][5]={{"O..","...","..O"},{"O..",".O.","..O"},{"OOO","...","OOO"}};
char ver[3][3][5]={{"..O","...","O.."},{"..O",".O.","O.."},{"O.O","O.O","O.O"}};
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n*4;i++){
		scanf("%s",a[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int s=0;s<3;s++){
				bool th=true,tv=true;
				for(int k=0;k<3;k++){
					for(int l=0;l<3;l++){
						if(hoz[s][k][l]!=a[i*4+k+1][j*4+l+1]) th=false;
						if(ver[s][k][l]!=a[i*4+k+1][j*4+l+1]) tv=false;
					}
				}
				if(th || tv){
					ish[i][j]=th?1:-1;
					break;
				}
			}
		}
	}
	for(int j=0;j<m;j++){
		c1[j]=1-(n&1);
		for(int i=0;i<n;i++){
			if(ish[i][j]==1) c1[j]=0;
		}
	}
	for(int j=1;j<m;j++){
		long long p2=1,p1=1;
		for(int i=0;i<n;i++){
			long long nxt=0;
			if(ish[i][j]>=0 && ish[i][j-1]>=0) nxt+=p1;
			if(i && ish[i][j]<=0 && ish[i][j-1]<=0 && ish[i-1][j]<=0 && ish[i-1][j-1]<=0) nxt+=p2;
			p2=p1;
			p1=nxt%Q;
		}
		c2[j]=(p1+Q-c1[j]*c1[j-1])%Q;
	}
	long long p1=1,p2=1;
	for(int j=0;j<m;j++){
		long long nxt=(p1*c1[j]+p2*c2[j])%Q;
		p2=p1;
		p1=nxt;
	}
	printf("%lld\n",p1);
	return 0;
}