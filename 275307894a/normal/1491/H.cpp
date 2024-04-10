#include <vector>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define l(x) x<<1
#define r(x) x<<1|1
#define re register
#define ll long long
#define db double
#define N 500000
#define M 2000
#define eps (1e-5)
#define mod (1<<31)
#define U unsigned int
using namespace std;
int n,m,A[N+5],B[N+5],L[N+5],R[N+5],k,F[N+5],G[N+5],x,y,z,op,nx,ny;
I int GetA(int x){return max(A[x]-G[x/k],0);}
I int GetB(int x){return max(B[x]-G[x/k],0);}
I void Make(int x){for(re int i=L[x];i<=R[x];i++) B[i]=(A[i]<L[x]?A[i]:B[A[i]]);}
I void swap(int &x,int &y){x^=y^=x^=y;}
int main(){
//	freopen("1.in","r",stdin);
	re int i,j;scanf("%d%d",&n,&m);n--;k=sqrt(n);for(i=1;i<=n;i++) scanf("%d",&A[i]),A[i]--;
	for(i=0;i<=n/k;i++)L[i]=max(i*k,1),R[i]=min(i*k+k-1,n);
	for(i=0;i<=n/k;i++){
		Make(i);for(j=L[i];j<=R[i];j++)A[j]>=L[i]&&(F[i]=1);
	}
	while(m--){
		scanf("%d%d%d",&op,&x,&y);x--;y--;if(op==1){
			scanf("%d",&z);nx=x/k;ny=y/k;if(nx==ny){for(i=x;i<=y;i++) A[i]=max(A[i]-z,0);Make(nx);continue;}
			for(i=x;i<=R[nx];i++) A[i]=max(A[i]-z,0);Make(nx);
			for(i=L[ny];i<=y;i++) A[i]=max(A[i]-z,0);Make(ny);
			for(i=nx+1;i<ny;i++){
				if(!F[i]) {G[i]+=z;G[i]=min(G[i],2*n);continue;}F[i]=0;
				for(j=L[i];j<=R[i];j++) A[j]=max(A[j]-z,0),A[j]>=L[i]&&(F[i]=1);Make(i);
			} 
		}
		else{
			while(x^y)
			x>y&&(swap(x,y),0),nx=x/k,ny=y/k,nx^ny?(y=GetB(y)):(GetB(x)^GetB(y)?(x=GetB(x),y=GetB(y)):(y=GetA(y)));
			printf("%d\n",x+1);
		}
	}
}