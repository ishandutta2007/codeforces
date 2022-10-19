#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (262144+5)
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
using namespace std;
int n,m=(1<<18),k,x,fa[N],cnt,Fl[N];ll ToT;
I int GF(int x){return x^fa[x]?fa[x]=GF(fa[x]):x;}
int main(){
//	freopen("1.in","r",stdin);
	int i,j,h;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&x),Fl[x]++,ToT-=x;Fl[0]++;for(i=0;i<m;i++) fa[i]=i;
	for(i=m-1;i;i--){
		for(j=i;j;j=(j-1)&i)Fl[j]&&Fl[i^j]&&GF(j)^GF(i^j)&&(fa[GF(j)]=GF(i^j),ToT+=1ll*i*(Fl[j]+Fl[i^j]-1),Fl[j]=Fl[i^j]=1);
		Fl[j]&&Fl[i^j]&&GF(j)^GF(i^j)&&(fa[GF(j)]=GF(i^j),ToT+=1ll*i*(Fl[j]+Fl[i^j]-1),Fl[j]=Fl[i^j]=1);
	}printf("%lld\n",ToT);
}