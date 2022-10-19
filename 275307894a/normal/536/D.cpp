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
using namespace std;const int N=2000+5,M=pow(6,10)+5,K=2e3+5,mod=998244353,Mod=mod-1;const db eps=1e-5;const int INF=1e9+7;
int Fl[N],n,m,T1,T2,A[N],x,y,z,H1,H2;vector<int> I1[N],I2[N];ll dp1[N][N],dp2[N][N],d1[N],d2[N],N1[N],N2[N],Q1[N][N],Q2[N][N],g1[N][N],g2[N][N],S1[N],S2[N];
struct Edge{int to;ll w;bool operator <(const Edge &B)const{return w>B.w;};};vector<Edge> S[N];priority_queue<Edge> Q;
int main(){
	int i,j,h;scanf("%d%d%d%d",&n,&m,&T1,&T2);for(i=1;i<=n;i++) scanf("%d",&A[i]);for(i=1;i<=m;i++) scanf("%d%d%d",&x,&y,&z),S[x].PB((Edge){y,z}),S[y].PB((Edge){x,z});
	Me(d1,0x3f);d1[T1]=0;Q.push((Edge){T1,0});while(!Q.empty()) {
		Edge x=Q.top();Q.pop();if(d1[x.to]^x.w) continue;for(Edge i:S[x.to]) d1[i.to]>x.w+i.w&&(Q.push((Edge){i.to,d1[i.to]=x.w+i.w}),0);
	}Me(d2,0x3f);d2[T2]=0;Q.push((Edge){T2,0});while(!Q.empty()) {
		Edge x=Q.top();Q.pop();if(d2[x.to]^x.w) continue;for(Edge i:S[x.to]) d2[i.to]>x.w+i.w&&(Q.push((Edge){i.to,d2[i.to]=x.w+i.w}),0);
	}for(i=1;i<=n;i++) N1[++H1]=d1[i],N2[++H2]=d2[i];sort(N1+1,N1+H1+1);H1=unique(N1+1,N1+H1+1)-N1-1;sort(N2+1,N2+H2+1);H2=unique(N2+1,N2+H2+1)-N2-1;
	for(i=1;i<=n;i++) I1[d1[i]=LB(N1+1,N1+H1+1,d1[i])-N1].PB(i),I2[d2[i]=LB(N2+1,N2+H2+1,d2[i])-N2].PB(i);
	for(i=0;i<=n;i++) {
		Me(Fl,0);for(j=1;j<=i;j++) for(int h:I1[j]) Fl[h]=1;
		for(j=1;j<=n;j++){ g1[i][j]=g1[i][j-1];Q1[i][j]=Q1[i][j-1];for(int h:I2[j]) !Fl[h]&&(Q1[i][j]+=A[h],g1[i][j]++);};
	}
	for(i=0;i<=n;i++){
		Me(Fl,0);for(j=1;j<=i;j++) for(int h:I2[j]) Fl[h]=1;
		for(j=1;j<=n;j++){ g2[j][i]=g2[j-1][i];Q2[j][i]=Q2[j-1][i];for(int h:I1[j]) !Fl[h]&&(Q2[j][i]+=A[h],g2[j][i]++);}
	}
	Me(dp1,0x3f);Me(dp2,-0x3f);for(i=0;i<=H2;i++) dp1[H1][i]=0;for(i=0;i<=H1;i++) dp2[i][H2]=0;Me(S1,0x3f);Me(S2,-0x3f);for(i=H1;~i;i--){
		for(j=H2;~j;j--){
			if(g1[i][j]^g1[i][j+1]) {for(h=j+1;h<=H2;h++) if(g1[i][h]^g1[i][j+1]) break;else dp2[i][h]>=-1e18&&(S1[i]=min(S1[i],dp2[i][h]-Q1[i][h]));}
			dp1[i][j]=min(dp1[i][j],S1[i]+Q1[i][j]); 
			//for(h=j+1;h<=H2;h++) g1[i][j]^g1[i][h]&&dp2[i][h]>=-1e18&&(dp1[i][j]=min(dp1[i][j],dp2[i][h]+Q1[i][j]-Q1[i][h]));
			if(g2[i][j]^g2[i+1][j]){for(h=i+1;h<=H1;h++) if(g2[i+1][j]^g2[h][j]) break;else dp1[h][j]<=1e18&&(S2[j]=max(S2[j],dp1[h][j]+Q2[h][j]));}
			//for(h=i+1;h<=H1;h++) g2[i][j]^g2[h][j]&&dp1[h][j]<=1e18&&(dp2[i][j]=max(dp2[i][j],dp1[h][j]+Q2[h][j]-Q2[i][j]));
			dp2[i][j]=max(dp2[i][j],S2[j]-Q2[i][j]);
		}
	}if(!dp2[0][0]) puts("Flowers");else if(dp2[0][0]>0) puts("Break a heart");else puts("Cry");
}