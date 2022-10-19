#include<bits/stdc++.h>
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((k+1)*(x)+(y))
#define R(n) (rnd()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
#undef continue
using ll=long long;using db=double;using lb=long db;using ui=unsigned;using ull=unsigned ll;
using namespace std;const int N=1e5+5,M=1<<18|5,K=200+5,mod=998244353,Mod=mod-1;const db eps=1e-5;
int n,A[N];ll T1,T2;
int main(){
	//freopen("1.in","r",stdin);
	int i,j;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]);sort(A+1,A+n+1);
	T2=n;for(i=1;i<=n;i++) T1+=1ll*(A[i]-A[i-1])*(n-i+1+1ll*2*(i-1)*(n-i+1));int d=__gcd(T1,T2);printf("%lld %lld\n",T1/d,T2/d);
}