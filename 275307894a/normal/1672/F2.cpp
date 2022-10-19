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
int T,n,A[N],B[N],In[N],x,Fs[N],Id;queue<int> Q;
I void Solve(){
	int i;scanf("%d",&n);for(i=1;i<=n;i++) In[i]=Fs[i]=0,S[i].clear();for(i=1;i<=n;i++)scanf("%d",&A[i]);for(i=1;i<=n;i++) scanf("%d",&B[i]),Fs[A[i]]++;
	Id=0;for(i=1;i<=n;i++) Fs[i]>Fs[Id]&&(Id=i);for(i=1;i<=n;i++) B[i]^Id&&(S[A[i]].PB(B[i]),In[B[i]]++);for(i=1;i<=n;i++) !In[i]&&(Q.push(i),0);
	while(!Q.empty()) {x=Q.front();Q.pop();for(int i:S[x]) In[i]--,!In[i]&&(Q.push(i),0);}for(i=1;i<=n;i++) if(In[i]){puts("WA");return ;}puts("AC");
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}