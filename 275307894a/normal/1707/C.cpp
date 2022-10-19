#include<bits/stdc++.h>
#include<iostream>
#define I inline
#define ll long long
#define db double
#define lb long db
#define N (100000+5)
#define M ((1<<16)+5)
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
using namespace std;vector<int> S[N];
int n,m,x,y,F[N][20],Bg[N],Bh,En[N],d[N],fa[N],Ct,Fl[N],X[N],Y[N],H;
I int GF(int x){return fa[x]^x?fa[x]=GF(fa[x]):x;}
I void Make(int x,int La){F[x][0]=La;for(int i=1;F[x][i-1];i++) F[x][i]=F[F[x][i-1]][i-1];d[x]=d[La]+1;Bg[x]=++Bh;for(int i:S[x]) i^La&&(Make(i,x),0),En[x]=Bh;}
I int kth(int x,int y){for(int i=19;~i;i--) y>>i&1&&(x=F[x][i]);return x;}
int main(){
	//freopen("1.in","r",stdin);
	int i,j;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) fa[i]=i;for(i=1;i<=m;i++) scanf("%d%d",&x,&y),GF(x)^GF(y)?(S[x].PB(y),S[y].PB(x),fa[GF(x)]=GF(y)):(X[++H]=x,Y[H]=y);
	Make(1,0);for(i=1;i<=H;i++) {
		d[X[i]]>d[Y[i]]&&(swap(X[i],Y[i]),0);if(Bg[Y[i]]>=Bg[X[i]]&&En[Y[i]]<=En[X[i]]) {int Ls=kth(Y[i],d[Y[i]]-d[X[i]]-1);Fl[1]++;Fl[Bg[Ls]]--;Fl[Bg[Y[i]]]++;Fl[En[Y[i]]+1]--;Fl[En[Ls]+1]++;}
		else {Fl[Bg[X[i]]]++;Fl[En[X[i]]+1]--;Fl[Bg[Y[i]]]++;Fl[En[Y[i]]+1]--;}
	}for(i=1;i<=n;i++) Fl[i]+=Fl[i-1];for(i=1;i<=n;i++) printf("%d",Fl[Bg[i]]==H);
}