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
#define N 1000000
#define M 500
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-7)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int n,m,k,Fl[N+5],pr[N+5],ph,phi[N+5],F[N+5];ll Ans;
struct Ques{int w,id;bool operator <(const Ques &B)const{return w>B.w;};}tmp;priority_queue<Ques>Q;
int main(){
//////////	freopen("1.in","r",stdin);
	RI i,j;scanf("%d%d",&n,&k);for(i=2;i<=n;i++){
		!Fl[i]&&(phi[i]=i-1,pr[++ph]=i);for(j=1;j<=ph&&i*pr[j]<=n;j++){
			Fl[i*pr[j]]=1;if(i%pr[j]==0){phi[i*pr[j]]=phi[i]*pr[j];break;}phi[i*pr[j]]=phi[i]*(pr[j]-1);
		}
	}for(i=3;i<=n;i++) !Fl[i]&&(Q.push((Ques){phi[i],i}),0);if(n>=4)Q.push((Ques){3,2});
	for(i=2;i<=n;i++){
		if(i==4) continue;for(j=i*2;j<=n;j+=i) F[j]++;
	} 
	while(k--){
		tmp=Q.top();Q.pop();Ans+=tmp.w;for(j=2*tmp.id;j<=n;j+=tmp.id) F[j]--,!F[j]&&j^4&&(Q.push((Ques){phi[j],j}),0);
	}printf("%lld\n",Ans+1);
}