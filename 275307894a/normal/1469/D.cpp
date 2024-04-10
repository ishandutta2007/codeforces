#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 300000
#define M 200000
#define mod 998244353
#define eps (1e-7)
#define U unsigned int
#define IT set<ques>::iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
using namespace std;
int n,m,T,A[N+5],fl[N+5],now,x[N+5],y[N+5],cnt,pus;
I void insert(int u,int v){x[++cnt]=u;y[cnt]=v;}
int main(){
//	freopen("1.in","r",stdin);
	re int i,j;scanf("%d",&T);while(T--){
		scanf("%d",&n);for(i=1;i<=n;i++) A[i]=i,fl[i]=0;cnt=0;now=n;fl[n]=1;while(now>2)pus=ceil(sqrt(now)),fl[pus]=1,now=pus;
		for(i=1;i<=n;i++)!fl[i]&&(insert(i,i+1),0);now=n;while(A[now]>2){
			pus=ceil(sqrt(A[now])),insert(now,pus),insert(now,pus);now=pus;
		}
		printf("%d\n",cnt);for(i=1;i<=cnt;i++) printf("%d %d\n",x[i],y[i]); 
	}
}