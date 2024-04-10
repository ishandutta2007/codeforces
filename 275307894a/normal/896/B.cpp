#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (2000+5)
#define M (N-5)
#define K (1500+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (1ll*rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;
int n,m,k,H1,H2,x,A[N];
int main(){
	int i;cin>>n>>m>>k;H2=n+1;A[n+1]=1e9;while(m--){
		cin>>x;if(x<=k/2){for(i=H1;~i;i--) if(x>=A[i]) {A[i+1]=x;i==H1&&(H1++);cout<<i+1<<endl;break;}}
		else {for(i=H2;i<=n+1;i++) if(x<=A[i]){A[i-1]=x;i==H2&&(H2--);cout<<i-1<<endl;break;}}
		if(H1+1==H2) break;
	}
}