// LUOGU_RID: 90445859
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
using namespace std;const int N=50+5,M=2e3+5,K=2e3+5,mod=998244353,Mod=mod-1;const db eps=1e-5;const int INF=1e9+7;mt19937 rnd(time(0));
int n,m,k,x,y,z,A[N][N],B[N][N],Ah,Bh,C1,C2,X1[N*N*N],Y1[N*N*N],H1,X2[N*N*N],Y2[N*N*N],H2;char S1[N][N],S2[N][N];
void SP1(int x,int y){X1[++H1]=x;Y1[H1]=y;C1-=2;swap(A[x][y+1],A[x+1][y]);}
void SP2(int x,int y){X2[++H2]=x;Y2[H2]=y;C2-=2;swap(B[x][y+1],B[x+1][y]);}
void Solve1(){
	int i,j;for(i=1;i<=n;i++) for(j=1;j<=m;j++)C1+=(S1[i][j]=='L'),C2+=(S2[i][j]=='L');
	while(C1){
		for(i=1;i<n;i++){
			for(j=1;j<m;j++) if(A[i][j]==A[i][j+1]&&A[i+1][j]==A[i+1][j+1]) SP1(i,j); 
		}int Fl=0;
		for(i=n;i>=2&&!Fl;i--){
			for(j=1;j<m;j++) if(A[i][j]==A[i][j+1]&&A[i-1][j]==A[i-2][j]&&A[i-1][j+1]==A[i-2][j+1]){SP1(i-2,j);SP1(i-1,j);C1+=4;Fl=1;break;} 
		}
	}
	while(C2){
		for(i=1;i<n;i++){
			for(j=1;j<m;j++) if(B[i][j]==B[i][j+1]&&B[i+1][j]==B[i+1][j+1]) SP2(i,j); 
		}int Fl=0;
		for(i=n;i>=2&&!Fl;i--){
			for(j=1;j<m;j++) if(B[i][j]==B[i][j+1]&&B[i-1][j]==B[i-2][j]&&B[i-1][j+1]==B[i-2][j+1]){SP2(i-2,j);SP2(i-1,j);C2+=4;Fl=1;break;} 
		}
	}
}
void Solve2(){
	int i,j;for(i=1;i<=n;i++) for(j=1;j<=m;j++)C1+=(S1[i][j]=='U'),C2+=(S2[i][j]=='U');
	while(C1){
		for(i=1;i<n;i++){
			for(j=1;j<m;j++) if(A[i][j]==A[i+1][j]&&A[i][j+1]==A[i+1][j+1]) SP1(i,j); 
		}int Fl=0;
		for(i=1;i<n;i++){
			for(j=m;j>=3;j--) if(A[i][j]==A[i+1][j]&&A[i][j-1]==A[i][j-2]&&A[i+1][j-1]==A[i+1][j-2]){SP1(i,j-2);SP1(i,j-1);C1+=4;Fl=1;break;} 
		}
	}
	while(C2){
		for(i=1;i<n;i++){
			for(j=1;j<m;j++) if(B[i][j]==B[i+1][j]&&B[i][j+1]==B[i+1][j+1]) SP2(i,j); 
		}int Fl=0;
		for(i=1;i<n;i++){
			for(j=m;j>=3;j--) if(B[i][j]==B[i+1][j]&&B[i][j-1]==B[i][j-2]&&B[i+1][j-1]==B[i+1][j-2]){SP2(i,j-2);SP2(i,j-1);C2+=4;Fl=1;break;} 
		}
	}
}
int main(){
	int i,j;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) scanf("%s",S1[i]+1);for(i=1;i<=n;i++) scanf("%s",S2[i]+1);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) if(S1[i][j]=='U'&&S1[i+1][j]=='D') A[i][j]=A[i+1][j]=++Ah;else if(S1[i][j]=='L'&&S1[i][j+1]=='R') A[i][j]=A[i][j+1]=++Ah;
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) if(S2[i][j]=='U'&&S2[i+1][j]=='D') B[i][j]=B[i+1][j]=++Bh;else if(S2[i][j]=='L'&&S2[i][j+1]=='R') B[i][j]=B[i][j+1]=++Bh;
	if(m%2==0)Solve2();else Solve1(); printf("%d\n",H1+H2);for(i=1;i<=H1;i++) printf("%d %d\n",X1[i],Y1[i]);for(i=H2;i;i--) printf("%d %d\n",X2[i],Y2[i]);
}