#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (500000+5)
#define M (10+5)
#define K (350)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
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
using namespace std;priority_queue<ll,vector<ll>,greater<ll> > Q;
int n,m,k,x,y,z,A[N];ll Ans,st[N],H;
int main(){
//	freopen("sale.in","r",stdin);freopen("sale.out","w",stdout);
	int i,j;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]),Ans+=A[i];sort(A+1,A+n+1);
	for(i=n;i;i=j-1){
		for(j=i;j;j--) if(A[i]^A[j]) break;j++;y=i-j+1;while(y&&x) y--,x--,st[++H]=A[i];
		while(!Q.empty()&&y&&Q.top()<A[i]) st[++H]=A[i],y--,y?(st[++H]=A[i],y--):(x++),Q.pop();
		while(!Q.empty()&&y>1&&Q.top()<A[i]*2)st[++H]=Q.top(),y--,st[++H]=2*A[i]-Q.top(),y--,Q.pop();
		while(H) Q.push(st[H--]);while(y) y--,x++; 
	}while(!Q.empty()) Ans-=Q.top(),Q.pop();printf("%lld\n",Ans);
}
/*
10
6 7 6 7 9 1 5 3 3 8 
31

10
6 1 3 4 1 3 6 1 7 7 
23
*/