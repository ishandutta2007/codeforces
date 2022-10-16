#include <bits/stdc++.h>
#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define ROF(i,a,b) for(register int i=(a);i>=(b);--i)
#define pi pair<int,ll>
#define mk(a,b) make_pair(a,b)
#define mygc(c) (c)=getchar()
#define mypc(c) putchar(c)
#define fi first
#define se second
#define ls(x) ch[x][0]
#define rs(x) ch[x][1]
#define xs(x) (ch[fa[x]][1]==x)
using namespace std;
typedef long long ll;
typedef double db;
typedef unsigned int ui;
typedef unsigned long long ul; 
const int maxn = 105;
const int maxm = 200005;
const int maxlog = 64;
const int inf = 2147483647;
typedef long long ll;
const double eps = 1e-9;
const long long INF = 9223372036854775807ll;
ll qpow(ll a,ll b,ll c){ll ans=1;while(b){if(b&1)ans=ans*a%c;a=a*a%c;b>>=1;}return ans;}
inline void rd(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
inline void rd(unsigned int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
inline void rd(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
inline void rd(unsigned long long *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
inline void rd(db *x){scanf("%lf",x);}
inline int rd(char c[]){scanf("%s",c);return strlen(c);}
inline void rd(int a[],int n){FOR(i,0,n)rd(&a[i]);}
inline void rd(ll a[],int n){FOR(i,0,n)rd(&a[i]);}
template <class T, class S> inline void rd(T *x, S *y){rd(x);rd(y);}
template <class T, class S, class U> inline void rd(T *x, S *y, U *z){rd(x);rd(y);rd(z);}
template <class T, class S, class U, class V> inline void rd(T *x, S *y, U *z, V *w){rd(x);rd(y);rd(z);rd(w);}
template <class T, class S, class U, class V, class H> inline void rd(T *x, S *y, U *z, V *w,H *h){rd(x);rd(y);rd(z);rd(w);rd(h);}
template <class T, class S, class U, class V, class H, class J> inline void rd(T *x, S *y, U *z, V *w,H *h,J *j){rd(x);rd(y);rd(z);rd(w);rd(h);rd(j);}
inline void wr(int x){if(x < 10) putchar('0' + x); else wr(x / 10), wr(x % 10);}
inline void wr(unsigned int x){if(x < 10) putchar('0' + x); else wr(x / 10), wr(x % 10);}
inline void wr(unsigned long long x){if(x < 10) putchar('0' + x); else wr(x / 10), wr(x % 10);}
inline void wr(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
inline void wr(unsigned int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
inline void wr(ll x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
inline void wr(unsigned long long x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
inline void wr(db x, char c){printf("%.15f",x);mypc(c);}
inline void wr(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}
inline void wr(const char x[], char c){int i;for(i=0;x[i]!='\0';i++)mypc(x[i]);mypc(c);}
template<class T> inline void wrn(T x){wr(x,'\n');}
template<class T, class S> inline void wrn(T x, S y){wr(x,' ');wr(y,'\n');}
template<class T, class S, class U> inline void wrn(T x, S y, U z){wr(x,' ');wr(y,' ');wr(z,'\n');}
template<class T, class S, class U, class H> inline void wrn(T x, S y, U z,H h){wr(x,' ');wr(y,' ');wr(z,' ');wr(h,'\n');}
template<class T, class S, class U, class H, class J> inline void wrn(T x, S y, U z, H h, J j){wr(x,' ');wr(y,' ');wr(z,' ');wr(h,' ');wr(j,'\n');}
template<class T, class S, class U, class H, class J,class K> inline void wrn(T x, S y, U z, H h, J j, K k){wr(x,' ');wr(y,' ');wr(z,' ');wr(h,' ');wr(j,' ');wr(k,'\n');}
template<class T> inline void wra(T x[], int n){int i;if(!n){mypc('\n');return;}FOR(i,0,n-1)wr(x[i],' ');wr(x[n-1],'\n');}
 
int a[maxn];
int main(){
	int t;
	rd(&t);
	while(t--){
		int n,k,cnt=1;
		rd(&n,&k);
		FOR(i,0,n){
			rd(&a[i]);
			if(i && a[i]!=a[i-1])cnt++;
		}
		int ans=0;
		if(k==1 && cnt>1)ans=-1;
		else if(cnt<=k)ans=1;
		else if(cnt>k){
			cnt-=k;
			ans++;
			ans+=(cnt+k-2)/(k-1);
		}
		wrn(ans);
	}
	
	
}