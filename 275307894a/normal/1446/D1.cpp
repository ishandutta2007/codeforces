#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (200000+5)
#define M (100+5)
#define K (20+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;vector<int> S[N];
int n,m,k,x,y,z,Q[N],Ans,A[N],Fs[N<<1],Ps;
int main(){
//	freopen("1.in","r",stdin); 
	int i,j;scanf("%d",&n);k=1;for(i=1;i<=n;i++) scanf("%d",&A[i]),S[A[i]].PB(i),Fs[A[i]]++;for(i=1;i<=n;i++)Fs[Ps]<Fs[i]&&(Ps=i);
	for(i=1;i<=n;i++){if(i==Ps) continue; 
		if(S[i].size()>=k){
			Me(Q,0);for(int j:S[Ps]) Q[j]=1;for(int j:S[i]) Q[j]=-1;for(j=1;j<=n;j++) Q[j]+=Q[j-1];
			Me(Fs,0x3f);Fs[n]=0;for(j=1;j<=n;j++) Ans=max(Ans,j-Fs[Q[j]+n]),Fs[Q[j]+n]=min(Fs[Q[j]+n],j);
		}
	}printf("%d\n",Ans);
}