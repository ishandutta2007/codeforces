#include<bits/stdc++.h>
#define I inline
#define ll long long
#define db double
#define lb long db
#define N (20000+5)
#define M ((N<<1)+5)
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
using namespace std;struct Node{Node *L=NULL,*R=NULL;int id;}S[N],Fr[N],En[N];
int n,m,k,x,y,z,Rt,L[N],R[N],st[N],A[N],H,W[N],dp[N],g[N];
I db slope1(int x,int y){return (g[y]-g[x])*1.0/(y-x);}
I void push(Node *x,int y){(*x).L=En[y].L;(*x).R=&En[y];(*En[y].L).R=x;En[y].L=x;}
I void pop_front(int x){Fr[x].R=(*Fr[x].R).R;(*Fr[x].R).L=&Fr[x];}
I void pop_back(int x){En[x].L=(*En[x].L).L;(*En[x].L).R=&En[x];}
I void dfs1(int x){S[x-1].id=x-1;Fr[x].R=&En[x];En[x].L=&Fr[x];
	if(L[x]){dfs1(L[x]);Fr[x]=Fr[L[x]];(*Fr[x].R).L=&Fr[x];En[x]=En[L[x]];(*En[x].L).R=&En[x];while(En[x].L!=Fr[x].R&&slope1((*(*En[x].L).L).id,(*En[x].L).id)>slope1((*En[x].L).id,x-1)) pop_back(x);}
	push(&S[x-1],x);
	while(En[x].L!=Fr[x].R&&slope1((*Fr[x].R).id,(*(*Fr[x].R).R).id)<A[x]) pop_front(x);W[x]=g[(*Fr[x].R).id]-1ll*A[x]*(*Fr[x].R).id;//cerr<<(*Fr[x].R).id<<' '<<(*(*Fr[x].R).R).id<<(*((*(*Fr[x].R).R).R==NULL?&Fr[x]:(*(*Fr[x].R).R).R)).id<<' '<<x<<' '<<W[x]<<'\n';
	if(R[x]){dfs1(R[x]);Node *Is=NULL;if(En[x].L==Fr[x].R) Is=Fr[R[x]].R,pop_front(R[x]),push(Is,x);
		int Pl=0;while((*En[R[x]].L).id){
			int Fl=0;while(En[x].L!=Fr[x].R&&slope1((*(*En[x].L).L).id,(*En[x].L).id)>slope1((*En[x].L).id,(*Fr[R[x]].R).id)) /*cerr<<"pop "<<(*(*En[x].L).L).id<<' '<<(*En[x].L).id<<' '<<(*Fr[R[x]].R).id<<'\n',*/pop_back(x),Fl++;
			if(!Fl&&Pl) break;Is=Fr[R[x]].R;pop_front(R[x]);push(Is,x);Pl=1;
		}(*En[x].L).R=Fr[R[x]].R;(*Fr[R[x]].R).L=En[x].L;En[x]=En[R[x]];(*En[x].L).R=&En[x];
	}
}
I db slope2(int x,int y){return (W[x]-W[y])*1.0/(A[x]-A[y]+eps);}
I void dfs2(int x){if(!x) return;
	int LH=H,LI,l,r,mid,Lp;dfs2(L[x]);l=0;r=H;while(l+1<r) mid=l+r>>1,(slope2(st[mid],st[mid+1])>slope2(st[mid+1],x)?l:r)=mid;H=r;Lp=st[LI=++H];st[H]=x;
	l=0;r=H;while(l+1<r) mid=l+r>>1,(slope2(st[mid],st[mid+1])>-x?l:r)=mid;/*cerr<<x<<' '<<st[r]<<'\n';*/dp[x]=W[st[r]]+1ll*x*A[st[r]];dfs2(R[x]);st[LI]=Lp;H=LH;
}
int main(){
//	freopen("1.in","r",stdin);
	int i,j;scanf("%d%d",&n,&k);A[0]=1e9;for(i=1;i<=n;i++){scanf("%d",&A[i]);while(A[st[H]]<A[i]) H--;L[i]=R[st[H]];R[st[H]]=i;st[++H]=i;}
	Me(dp,0x3f);dp[0]=0;Rt=R[0];Me(st,0);H=0;while(k--){Me(W,0x3f);Mc(g,dp);Me(dp,0x3f);dfs1(Rt);dfs2(Rt);/*for(i=1;i<=n;i++) printf("%lld ",dp[i]);Pc('\n');*/}printf("%lld\n",dp[n]);
}