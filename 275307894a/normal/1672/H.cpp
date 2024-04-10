#include<bits/stdc++.h>
#define I inline
#define ll long long
#define db double
#define lb long db
#define N (200000+5)
#define M ((N*50)+5)
#define K (1500+5)
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-5)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((k+1)*(x)+(y))
#define R(n) (1ll*rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;
int n,m,x,y,Q1[N],Q2[N];char A[N];
int main(){
/////////	freopen("1.in","r",stdin);
	int i,j;scanf("%d%d",&n,&m);scanf("%s",A+1);for(i=2;i<=n;i++) Q1[i]=Q1[i-1],Q2[i]=Q2[i-1],A[i]==A[i-1]&&(Q1[i]=Q1[i-1]+(A[i]=='0'),Q2[i]=Q2[i-1]+(A[i]=='1'));
	while(m--) scanf("%d%d",&x,&y),printf("%d\n",max(Q1[y]-Q1[x],Q2[y]-Q2[x])+1);
}