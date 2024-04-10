#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define re(i,a,b) for(int i=(a);i<(b);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define run(v) for(int k=head[v];k;k=e[k].ne)
#define ergomap(i,a) for(map<int,int>::iterator i=a.begin();i!=a.end();i++)
#define ergoset(i,a) for(set<int>::iterator i=a.begin();i!=a.end();i++)
#define ergo(i,a) for(int i=0;i<a.size();i++)
#define clr(a) memset(a,0,sizeof(a));
#define il inline
#define pb push_back 
#define w1 first
#define w2 second
#define addm(a,b,c) {a=a+b;if(a>=c)a-=c;}
typedef pair<int,int> pa;
typedef long long ll;typedef long double ld;typedef unsigned long long ull;
const int N=6e5+5,M=2e6+5,INF=1e9,mod=1e9+7;
const ll linf=1e18;
const double eps=1e-8,pi=acos(-1);
il int gmin(int &a,int b){if(a>b)a=b;}il ll gmin(ll &a,ll b){if(a>b)a=b;}il int gmax(int &a,int b){if(a<b)a=b;}il ll gmax(ll &a,ll b){if(a<b)a=b;}
il int max(int a,int b,int c){if(b>a)a=b;if(c>a)a=c;return a;}il int max(int a,int b){if(a>b)return a;return b;}il int min(int a,int b){if(a>b)return b;return a;}
il void read(ll&x){ll f=1,t=0;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){t=t*10+ch-'0';ch=getchar();}x=t*f;}il ll read(ll&x,ll&y){read(x);read(y);}
il void read(int&x){int f=1,t=0;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){t=t*10+ch-'0';ch=getchar();}x=t*f;}il int read(int&x,int&y){read(x);read(y);}
il void writ(int x){if(!x)return;writ(x/10);putchar(x%10+'0');}il void write(int x){if(!x)putchar('0');if(x<0){x=-x;putchar('-');}writ(x);putchar(' ');}il void writeln(int x){write(x);puts("");}
il void writ(ll x){if(!x)return;writ(x/10);putchar(x%10+'0');}il void write(ll x){if(!x)putchar('0');if(x<0){x=-x;putchar('-');}writ(x);putchar(' ');}il void writeln(ll x){write(x);puts("");}
il ll qpow(ll a,ll b,ll p){ll ret=1;for(;b;b>>=1,a=a*a%p)if(b&1)ret=ret*a%p;return ret;}
il ll qmul(ll a,ll b,ll p){ll ret=0;for(;b;b>>=1,a=(a<<1)%p)if(b&1)addm(ret,a,p);return ret;}
il void judge(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);}
il void gen(){freopen("data.in","w",stdout);}
int n,m,bin[30]={1},q,k;
int a[N];
map<int,int> mp;
priority_queue<pa,vector<pa>,greater<pa> >pq;
int main(){
	read(n,k);read(q);
	rep(i,1,n)read(a[i]);
	rep(i,1,q){
		int opt,x;read(opt,x);
		if(opt==2){
			if(mp[x])puts("YES");else puts("NO");
		}else{
			if(pq.size()<k||pq.top().w1<a[x])
				pq.push(pa(a[x],x)),mp[x]++;
			while(pq.size()>k)mp[pq.top().w2]--,pq.pop();
		}
	}
}