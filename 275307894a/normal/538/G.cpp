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
#define M 2000000
#define mod 1000000007
#define Mod 998244352
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
using namespace std;
int n,m,Fl,T1[M+5],T2[M+5];ll T[N+5],X[N+5],Y[N+5],un,wn,L,R;
struct Ques{ll id,A,B,S;}S[N+5];I bool cmp(Ques x,Ques y){return x.id<y.id;}
I void print(){
	for(RI i=1;i<=m;i++){
		if(T1[i])putchar(T2[i]?'R':'D');
		else putchar(T2[i]?'U':'L'); 
	}
}
I void work(ll *X,int *Ts){
	L=-m;R=m;RI i,j;for(i=1;i<=n;i++) S[i]=(Ques){(T[i]-1)%m+1,(T[i]-1)/m,X[i]};sort(S+1,S+n+1,cmp);S[0]=(Ques){0,0,0};S[n+1]=(Ques){m,-1,0};
	for(i=1;i<=n+1;i++){
		if(S[i].A==S[i-1].A){if(S[i-1].id-S[i].id-S[i-1].B+S[i].B>0||S[i].id-S[i-1].id-S[i-1].B+S[i].B<0) {puts("NO");exit(0);}continue;}
		if(S[i].A>S[i-1].A) L=max(L,ceil((lb)(S[i-1].id-S[i].id-S[i-1].B+S[i].B)/(S[i].A-S[i-1].A))),R=min(R,floor((lb)(S[i].id-S[i-1].id-S[i-1].B+S[i].B)/(S[i].A-S[i-1].A)));
		else L=max(L,ceil((lb)(S[i].id-S[i-1].id-S[i-1].B+S[i].B)/(S[i].A-S[i-1].A))),R=min(R,floor((lb)(S[i-1].id-S[i].id-S[i-1].B+S[i].B)/(S[i].A-S[i-1].A)));
	}/*printf("%lld %lld\n",L,R);*/if(R<L){puts("NO");exit(0);}
	Fl=0;for(i=0;i<=n+1;i++) S[i].S=-S[i].A*L+S[i].B;for(i=1;i<=n+1;i++) if((S[i].S-S[i-1].S+S[i].id-S[i-1].id)&1){Fl=1;break;}
	if(Fl){if(L==R) {puts("NO");exit(0);}for(i=0;i<=n+1;i++) S[i].S=-S[i].A*(L+1)+S[i].B;}
	for(i=1;i<=n+1;i++){
		for(j=1;j<=(S[i].S-S[i-1].S+S[i].id-S[i-1].id)/2;j++) Ts[S[i-1].id+j]=1;
	}
}
int main(){
	//freopen("D.in","r",stdin);freopen("D.out","w",stdout);
	RI i;scanf("%d%d",&n,&m);for(i=1;i<=n;i++)scanf("%lld%lld%lld",&T[i],&un,&wn),X[i]=un-wn,Y[i]=un+wn;work(X,T1);work(Y,T2);print();
}