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
#define N ((1<<19)+5)
#define M ((1<<19)+5)
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
int n,m,k,Fl,rk[N],Ns;char A[N];
struct Ques{int x,y,id;}S[N];I bool cmp(Ques x,Ques y){return x.x^y.x?x.x<y.x:x.y<y.y;}
int main(){
//	freopen("1.in","r",stdin);
	int i,j,h;scanf("%d",&n);m=(1<<n);scanf("%s",A);for(i=0;i<m;i++) rk[i]=A[i]-'a'+1;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++) S[j]=(Ques){rk[j],rk[j^(1<<i)],j};sort(S,S+m,cmp);
		for(rk[S[0].id]=1,j=1;j<m;j++) rk[S[j].id]=rk[S[j-1].id]+(S[j].x^S[j-1].x||S[j].y^S[j-1].y);
	}
	for(i=0;i<m;i++) if(rk[i]==1){Ns=i;break;}
	for(i=0;i<m;i++) Pc(A[i^Ns]);
}