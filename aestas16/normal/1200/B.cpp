// luogu-judger-enable-o2
#include <cstdio>
 
#define max(a,b) ((a)>(b)?(a):(b))
#define N 100
#define ll long long
 
template<class T>void fr(T &a) {
    T s=0,w=1;a=0;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    a=w*s;
}
template<class T>T in() {T a;fr(a);return a;}
 
ll h[N+10],n,m,k,cnt;
 
ll abs(ll a) {return a<0?-a:a;}
 
int main() {
	int t=in<int>();
	while(t--) {
		fr(n),fr(m),fr(k);cnt=m;
		bool flag=false;
		for(int i=1;i<=n;i++) fr(h[i]);
		for(int i=1;i<n;i++) {
			if(h[i]>h[i+1]-k) {
				ll e=h[i+1]-k;
				if(e<0)cnt+=h[i];
				else cnt+=h[i]-e;
			} else {
				if(cnt<((h[i+1]-k)-h[i])) {
					puts("NO"),flag=true;
					break;
				} else cnt-=((h[i+1]-k)-h[i]);
			}
		}
		if(!flag)puts("YES");
	}
	return 0;
}