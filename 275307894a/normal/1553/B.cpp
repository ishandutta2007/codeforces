#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 1000
#define M 200000
#define W (1<<20)
#define mod 998244353
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
using namespace std;
int n,m,k,T;char s1[N+5],s2[N+5];
I int check(int l,int r){
	re int i;if(r*2-l<m||r-l+1>m) return 0;for(i=l;i<=r;i++) if(s1[i]^s2[i-l+1]) return 0;
	for(i=r-1;i>=r-(m-(r-l+1));i--) if(s1[i]^s2[r-i+r-l+1])return 0;return 1; 
}
I void solve(){
	re int i,j,h;scanf("%s",s1+1);scanf("%s",s2+1);n=strlen(s1+1);m=strlen(s2+1);
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++)if(check(i,j)){printf("YES\n");return;}
	}printf("NO\n");
}
int main(){
// 	freopen("1.in","r",stdin);
	re int i;scanf("%d",&T);while(T--)solve();
}