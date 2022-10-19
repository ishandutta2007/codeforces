#include<bits/stdc++.h>
#define I inline
#define ll long long
#define db double
#define lb long db
#define N (500000+5)
#define M ((1<<14)+5)
#define K (700+5)
#define mod 64123
#define Mod (mod-1)
#define eps (1e-5)
#define ui unsigned int
#define ull unsigned ll
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((k+1)*(x)+(y))
#define R(n) (rnd()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;vector<int> S[N];
int n,d[N],fa[N],Si[N],Sn[N],x,y,z;
I void dfs1(int x,int La){d[x]=d[fa[x]=La]+1;Si[x]=1;for(int i:S[x]) i^La&&(dfs1(i,x),Si[Sn[x]]<Si[i]&&(Sn[x]=i),Si[x]+=Si[i]);}
I int Q1(int x){cout<<"d "<<x<<endl;int y;cin>>y;if(!y) {cout<<"! "<<x<<endl;exit(0);}return y;}
I int Q2(int x){cout<<"s "<<x<<endl;cin>>x;return x;}
int main(){
	int i,j;scanf("%d",&n);for(i=1;i<n;i++) scanf("%d%d",&x,&y),S[x].PB(y),S[y].PB(x);dfs1(1,0);z=Q1(1)+1;x=1;
	while(1){
		while(Sn[x]) x=Sn[x];int D=(d[x]+z-Q1(x))/2;while(d[x]^D)x=fa[x];if(d[x]==z) {cout<<"! "<<x<<endl;exit(0);}x=Q2(x);
	}
}