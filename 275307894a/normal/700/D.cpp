#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (100000+5)
#define M (100+5)
#define K (1000+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
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
int l,r,n,m,k,cnt,x,y,z,A[N],L[N],R[N],F[N],G[N],Ans[N],H1,H2,T1,T2;
struct Ques{int l,r,id;}S[N];I bool C1(Ques x,Ques y){return x.l/k==y.l/k?((x.l/k)&1?x.r<y.r:x.r>y.r):x.l<y.l;}
I void LED(int x){R[L[x]]=R[x];L[R[x]]=L[x];L[x]=R[x]=0;}I void DDA(int x){R[x]=n+2;L[x]=L[n+2];R[L[x]]=L[R[x]]=x;}
I void ADD(int x){G[F[x]]--;!G[F[x]]&&(LED(F[x]),0);F[x]++;!G[F[x]]&&(DDA(F[x]),0);G[F[x]]++;}I void DEL(int x){G[F[x]]--;!G[F[x]]&&(LED(F[x]),0);F[x]--;!G[F[x]]&&(DDA(F[x]),0);G[F[x]]++;}
struct Node{int x,w;}Q1[K],Q2[K],P1,P2;I bool C2(Node x,Node y){return x.x<y.x;}I int CK(){return (Q1[H1].x<Q2[H2].x||H2>T2)&&H1<=T1;}
int main(){
//	freopen("1.in","r",stdin);freopen("1.out","w",stdout); 
	int i;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]);scanf("%d",&m);k=max(n/sqrt(m),1);for(i=1;i<=m;i++) scanf("%d%d",&S[i].l,&S[i].r),S[i].id=i;
	sort(S+1,S+m+1,C1);R[n+1]=0;L[0]=n+1;R[0]=n+2;L[n+2]=0;G[0]=n+1;l=1;r=0;for(i=1;i<=m;i++){
		while(l>S[i].l) ADD(A[--l]);while(r<S[i].r) ADD(A[++r]);while(r>S[i].r) DEL(A[r--]);while(l<S[i].l) DEL(A[l++]);
		H1=H2=1;T1=T2=0;x=R[n+1];while(x^(n+2)) x&&(Q1[++T1]=((Node){x,G[x]}),0),x=R[x];sort(Q1+1,Q1+T1+1,C2);while(H1<=T1||H2<=T2){
			if(H1==T1&&H2>T2&&Q1[H1].w==1) break;if(H1>T1&&H2==T2&&Q2[H2].w==1) break;
			if(CK()){P1=Q1[H1];
				if(P1.w==1) H1++,CK()?(Ans[S[i].id]+=Q1[H1].x+P1.x,Q2[++T2]=(Node){Q1[H1].x+P1.x,1},Q1[H1].w--,!Q1[H1].w&&(H1++)):(Ans[S[i].id]+=Q2[H2].x+P1.x,Q2[++T2]=(Node){Q2[H2].x+P1.x,1},Q2[H2].w--,!Q2[H2].w&&(H2++));
				else Ans[S[i].id]+=(P1.w/2*2)*P1.x,Q2[++T2]=(Node){P1.x*2,P1.w/2},Q1[H1].w&=1,!Q1[H1].w&&(H1++);
			} else{P1=Q2[H2];
				if(P1.w==1) H2++,CK()?(Ans[S[i].id]+=Q1[H1].x+P1.x,Q2[++T2]=(Node){Q1[H1].x+P1.x,1},Q1[H1].w--,!Q1[H1].w&&(H1++)):(Ans[S[i].id]+=Q2[H2].x+P1.x,Q2[++T2]=(Node){Q2[H2].x+P1.x,1},Q2[H2].w--,!Q2[H2].w&&(H2++));
				else Ans[S[i].id]+=(P1.w/2*2)*P1.x,Q2[++T2]=(Node){P1.x*2,P1.w/2},Q2[H2].w&=1,!Q2[H2].w&&(H2++);
			}
		}
	}for(i=1;i<=m;i++) printf("%d\n",Ans[i]);
}