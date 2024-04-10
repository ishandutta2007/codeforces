#include<bits/stdc++.h>
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((m)*(x-1)+(y))
#define R(n) (rnd()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using ll=long long;using db=double;using lb=long db;using ui=unsigned;using ull=unsigned ll;
using namespace std;const int N=2e5+5,M=N*4+5,K=1e5+5,mod=1e9+7,Mod=mod-1;const db eps=1e-5;mt19937 rnd(time(0));
int n,m,k,x,y,z;vector<int> S[N];db ans;
void dfs(int x,int La,int w){ans+=n*1.0/w;for(int i:S[x]) i^La&&(dfs(i,x,w+1),0);}
int main(){
	int i,j;scanf("%d",&n);for(i=1;i<n;i++) scanf("%d%d",&x,&y),S[x].PB(y),S[y].PB(x);dfs(1,0,1);printf("%.8lf\n",ans/n);
}