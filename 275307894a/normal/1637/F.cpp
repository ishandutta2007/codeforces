#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (200000+5)
#define M ((1<<16)+5)
#define K (1000+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
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
using namespace std;vector<int> S[N];
int n,A[N],x,y,Ro;ll Ans; 
I int dfs(int x,int La){
	priority_queue<int> Q;while(!Q.empty())Q.pop();for(int i:S[x]) i^La&&(Q.push(dfs(i,x)),0);if(S[x].size()==1) Q.push(A[x]);
	if(x^Ro){if(Q.top()<A[x]) Q.pop(),Q.push(A[x]);int Ns=Q.top();Q.pop();while(!Q.empty()) Ans+=Q.top(),Q.pop();return Ns;}
	Ans+=max(Q.top(),A[x]);Q.pop();Ans+=max(Q.top(),A[x]);Q.pop();while(!Q.empty()) Ans+=Q.top(),Q.pop();return 0;
}
int main(){
//	freopen("1.in","r",stdin);
	int i,j;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]);for(i=1;i<n;i++) scanf("%d%d",&x,&y),S[x].PB(y),S[y].PB(x);
	for(Ro=1,i=2;i<=n;i++) A[Ro]<A[i]&&(Ro=i);dfs(Ro,0);printf("%lld\n",Ans);
}