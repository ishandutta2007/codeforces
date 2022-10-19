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
#define N (200000+5)
#define M (N*200)+5
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
int T,n,F1[27][27],F2[27][27],F3[27][27][27],L[N+5];char S[N+5][4];
I void Solve(){
	#define OK {puts("YES");return;}
	RI i,j;scanf("%d",&n);for(i=1;i<=n;i++)for(scanf("%s",S[i]),L[i]=strlen(S[i]),j=0;j<L[i];j++) S[i][j]-='a';
	for(i=1;i<=n;i++) if(L[i]==1) OK;
	for(i=1;i<=n;i++) if(L[i]==2&&S[i][0]==S[i][1]) OK;
	for(i=1;i<=n;i++) if(L[i]==3&&S[i][0]==S[i][2]) OK;
	Me(F1,0);Me(F2,0);Me(F3,0);
	for(i=1;i<=n;i++){
		if(L[i]==3) {
			if(F1[S[i][2]][S[i][1]]) OK;
			if(F3[S[i][2]][S[i][1]][S[i][0]]) OK;
			F2[S[i][0]][S[i][1]]++;F3[S[i][0]][S[i][1]][S[i][2]]++;
		}else{
			if(F2[S[i][1]][S[i][0]]) OK;
			if(F1[S[i][1]][S[i][0]]) OK;
			F1[S[i][0]][S[i][1]]++;
		}
	}puts("NO");
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}