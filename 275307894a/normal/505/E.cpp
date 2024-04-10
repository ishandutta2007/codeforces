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
#define N 100000
#define K 1000
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (m*x+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
using namespace std;
int n,m,k,p;ll l,r,mid,A[N+5],H[N+5];
struct Ques{ll H,A,B;bool operator <(const Ques &x)const{return B/A>x.B/x.A;}}now;priority_queue<Ques> Q;
I int check(ll mid){
	RI i,j;while(!Q.empty()) Q.pop();for(i=1;i<=n;i++) mid<H[i]+A[i]*m&&(Q.push((Ques){H[i],A[i],mid}),0);for(i=1;i<=m;i++){
		for(j=1;j<=k;j++){
			if(Q.empty()) break;now=Q.top();/*printf("%lld %lld %lld %lld\n",mid,now.B,now.A,now.H);*/Q.pop();if(now.B/now.A<i)return 0;now.B+=p;if(now.B<now.H+m*now.A) Q.push(now);
		}
	}return Q.empty();
}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d%d%d%d",&n,&m,&k,&p);for(i=1;i<=n;i++) scanf("%d%d",&H[i],&A[i]);
	l=0;r=1ll*(m+1)*1e9;while(l+1<r) mid=l+r>>1,(check(mid)?r:l)=mid;printf("%lld\n",r);
}