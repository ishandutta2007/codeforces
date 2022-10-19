#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 200000
#define M 30
#define mod 1000000007
#define eps (1e-7)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
using namespace std;
int T,n,m,tot,A[N+5],B[N+5],C[N+5];
I void solve(){
	re int i;tot=0;scanf("%d",&n);Me(C,0);Me(B,0);for(i=1;i<=n;i++) scanf("%d",&A[i]),B[A[i]]++,C[A[i]]+=(i&1);
	for(i=1;i<=1e5;i++){
		if(C[i]!=((tot+B[i])/2+(tot+B[i])%2-tot/2-tot%2)){printf("NO\n");return ;}tot+=B[i];
	}printf("YES\n");
}
int main(){
	scanf("%d",&T);while(T--) solve();
}