#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define RI re int
#define ll long long
#define db double
#define lb long db
#define N 200000
#define M N*N+5
#define mod 1000000007
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
using namespace std;
int n,m,k,x,y,Fl,Ro[N+5],B[N+5],Len,Ns;char S[N+5];
struct yyy{int to,z;};struct ljb{int head,h[N+5];yyy f[N+5];I void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}}s;
namespace Tree{
	int cnt,F[N*40+5],L[N*40+5],R[N*40+5];I void Ins(int x,int &now,int l=1,int r=n){!now&&(now=++cnt);F[now]++;if(l==r) return;int m=l+r>>1;x<=m?Ins(x,L[now],l,m):Ins(x,R[now],m+1,r);}
	I int ME(int x,int y,int l=1,int r=n){if(!x||!y) return x|y;F[++cnt]=F[x]+F[y];if(l==r) return cnt;int m=l+r>>1,Ns=cnt;L[Ns]=ME(L[x],L[y],l,m);R[Ns]=ME(R[x],R[y],m+1,r);return Ns;}
	I int Find(int x,int y,int now,int l=1,int r=n){/*cerr<<x<<' '<<y<<'\n';*/if(x<=l&&r<=y) return F[now];int m=l+r>>1;return (x<=m&&Find(x,y,L[now],l,m))||(y>m&&Find(x,y,R[now],m+1,r));}
}
I void DFS(int x){yyy tmp;for(RI i=s.h[x];i;i=tmp.z) tmp=s.f[i],DFS(tmp.to),Ro[x]=Tree::ME(Ro[x],Ro[tmp.to]);}
namespace SAM{
	int cnt=1,La=1,p,q,Lk[N+5],Le[N+5],son[N+5][26];I void Ins(int c){
		Le[++cnt]=Le[p=La]+1;La=cnt;while(p&&!son[p][c]) son[p][c]=La,p=Lk[p];if(!p) {Lk[La]=1;return;}q=son[p][c];
		if(Le[q]==Le[p]+1){Lk[La]=q;return;}Le[++cnt]=Le[p]+1;Mc(son[cnt],son[q]);Lk[cnt]=Lk[q];Lk[q]=Lk[La]=cnt;while(p&&son[p][c]==q) son[p][c]=cnt,p=Lk[p]; 
	}I void BD(){for(RI i=2;i<=cnt;i++)s.add(Lk[i],i);DFS(1);}
}
int main(){
//	freopen("1.in","r",stdin);
	RI i,j,h;scanf("%s",S+1);n=strlen(S+1);for(i=1;i<=n;i++) SAM::Ins(S[i]-'a'),Tree::Ins(i,Ro[SAM::La]);SAM::BD();scanf("%d",&m);while(m--){
		scanf("%d%d%s",&x,&y,S+1);Len=k=strlen(S+1);for(B[0]=i=1;i<=k;i++) if(!SAM::son[B[i-1]][S[i]-'a']){Len=i-1;break;}else B[i]=SAM::son[B[i-1]][S[i]-'a'];
		Fl=0;for(i=Len;~i&&!Fl;i--) for(j=max(S[i+1]-'a'+1,0);j<26;j++) if(SAM::son[B[i]][j]&&Tree::Find(x+i,y,Ro[SAM::son[B[i]][j]])){for(h=1;h<=i;h++) Pc(S[h]);Pc(j+'a');Pc('\n');Fl=1;break;}if(!Fl) puts("-1");
	}
}