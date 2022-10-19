#include<bits/stdc++.h>
#define I inline
#define ll long long
#define db double
#define lb long db
#define N (500000+5)
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
using namespace std;
int n,C1,C2;char S[N];
int F1[500]={0,1,2,3,1,3,2,4,5,2,3,1,3,2,1,4,2,4,1,2,3,1,3,2,4,5,2,3,1,3,2,1,4,3,4,1,2,3,1,3,2,4,5,9,3,1,3,2,1,4,3,4,1,2,3,1,3,2,4,5,9,3,1,3,2,1,4,3,4,1,2,3,1,3,2,4,5,9,3,1,3,2,1,4,3,4,1,2,3,1,3,2,4,5,9,3,1,3,2,1,4,3,4,1,2,3,1,3,2,4,5,9,3,1,3,2,1,4,3,4,1,2,3,1,3,2,4,5,9,3,1,3,2,1,4,3,4,1,2,3,1,3,2,4,5,9,3,};
int F2[500]={0,1,0,1,0,3,2,0,2,3,0,1,0,1,0,5,7,0,1,0,1,0,3,2,4,5,3,0,1,0,1,0,5,7,8,1,0,1,0,3,2,4,5,3,0,1,0,1,0,5,7,8,1,0,1,0,3,2,4,5,3,0,1,0,1,0,5,7,8,1,0,1,0,3,2,4,5,3,0,1,0,1,0,5,7,8,1,0,1,0,3,2,4,5,3,0,1,0,1,0,5,7,8,1,0,1,0,3,2,4,5,3,0,1,0,1,0,5,7,8,1,0,1,0,3,2,4,5,3,0,1,0,1,0,5,7,8,1,0,1,0,3,2,4,5,3,0,};
int F3[500]={0,1,0,1,0,3,2,0,2,3,0,1,0,1,0,5,7,0,1,0,1,0,3,2,4,5,3,0,1,0,1,0,5,7,8,1,0,1,0,3,2,4,5,3,0,1,0,1,0,5,7,8,1,0,1,0,3,2,4,5,3,0,1,0,1,0,5,7,8,1,0,1,0,3,2,4,5,3,0,1,0,1,0,5,7,8,1,0,1,0,3,2,4,5,3,0,1,0,1,0,5,7,8,1,0,1,0,3,2,4,5,3,0,1,0,1,0,5,7,8,1,0,1,0,3,2,4,5,3,0,1,0,1,0,5,7,8,1,0,1,0,3,2,4,5,3,0,};
I int calc1(int x){if(x<130) return F1[x];else return F1[(x-130)%17+130];}
I int calc2(int x){if(x<130) return F2[x];else return F2[(x-130)%17+130];}
I int calc3(int x){if(x<130) return F3[x];else return F3[(x-130)%17+130];}
I void Solve(){
	int i,j;scanf("%d",&n);scanf("%s",S+1);C1=C2=0;for(i=1;i<=n;i++) C1+=(S[i]=='R'),C2+=(S[i]=='B');if(C1^C2) {puts(C1<C2?"Bob":"Alice");return;}
	int Ts=0;for(i=1;i<=n;i=j+1) {for(j=i+1;j<=n;j++) if(S[j]==S[j-1]) break;j--;if(S[i]==S[j]) Ts^=(S[i]=='R'?calc2((j-i+1)/2):calc3((j-i+1)/2));else Ts^=calc1((j-i+1)/2);}puts(Ts?"Alice":"Bob");
}
int main(){
	//freopen("1.in","r",stdin);
	int T;scanf("%d",&T);while(T--) Solve();
}