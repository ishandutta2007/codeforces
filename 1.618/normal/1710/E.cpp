#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 500005;
int n, m, sx, sy, a[N], b[N], sa[N], sb[N];

void init(int mid) {
  sa[0] = m, sb[0] = n;
  for (int i = 1; i <= n; i++) {
    sa[i] = sa[i - 1];
    while (sa[i] && a[i] + b[sa[i]] > mid) sa[i]--;
  }
  for (int i = 1; i <= m; i++) {
    sb[i] = sb[i - 1];
    while (sb[i] && b[i] + a[sb[i]] > mid) sb[i]--;
  }
}

/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=555555,mod=998244353;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0;bool f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
inline int qmo(int x){return x+((x>>31)&mod);}
int n,m,a[maxn],b[maxn],x,y,c[maxn],r[maxn];
ll c1[maxn],c2[maxn];
bool check(int w){
	if(a[x]+b[y]<w) return false;
	ll s1=0,s2=0;
	int j=m;
//	printf("w=%d\n",w);
	FOR(i,1,n){
		while(j && a[i]+b[j]>=w) j--;
		r[i]=m-j;
	}
	j=n;
	FOR(i,1,m){
		while(j && a[j]+b[i]>=w) j--;
		c[i]=n-j;
	}
	FOR(i,0,n) c1[i]=c2[i]=0;
	FOR(i,1,m) c1[c[i]]++,c2[c[i]]+=c[i];
	FOR(i,1,n) c1[i]+=c1[i-1],c2[i]+=c2[i-1];
	ll s=0;
	FOR(i,1,n){
		s-=r[i];
		s1=max(s1,s+i*c1[i]-c2[i]);
	}
	r[x]--;c[y]--;
	FOR(i,0,n) c1[i]=c2[i]=0;
	FOR(i,1,m) c1[c[i]]++,c2[c[i]]+=c[i];
	FOR(i,1,n) c1[i]+=c1[i-1],c2[i]+=c2[i-1];
	s=0;
	FOR(i,1,n){
		s-=r[i];
		s2=max(s2,s+i*c1[i]-c2[i]-(i>=x && i-1>=c[y]));
	}
	FOR(i,1,n){
		if(i==x) continue;
		s-=r[i];
		int ii=i-(i>=x);
		s2=max(s2,s+ii*c1[ii]-c2[ii]);
	}
//	printf("%lld and %lld\n",s1,s2);
	return s1==s2;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	n=read();m=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,m) b[i]=read();
	int aa=a[1],bb=b[1];
	sort(a+1,a+n+1);sort(b+1,b+m+1);
	x=lower_bound(a+1,a+n+1,aa)-a;
	y=lower_bound(b+1,b+m+1,bb)-b;
//	printf("x=%d,y=%d\n",x,y);
	int l=2,r=2e8;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
}
*/

bool check(int mid) {
  init(mid);
  ll sum = 0, mx = 0;
  int x = 0, y = 0;
  for (int i = 1, j = 0; i <= n; i++) {
    sum += sa[i] + j - m;
    while (j < m && i + sb[j + 1] - n >= 0) sum += i + sb[++j] - n;
    if (sum >= mx) mx = sum, x = i, y = j;
  }
  return x >= sx || y >= sy;
}

#ifdef sdlkfjalkdjfs
#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5,INF=1e9,B=2;
long long n,m,stx,sty;
long long a[N],b[N];
long long prea[N],preb[N];

bool check(long long x){
	long long cur=m;
	for(long long i=1;i<=n;i++){
		while(cur && a[i]+b[cur]>x) cur--;
		prea[i]=cur;
	}
	cur=n;
	for(long long i=1;i<=m;i++){
		while(cur && b[i]+a[cur]>x) cur--;
		preb[i]=cur;
	}
	
	long long spx,spy;
	for(long long i=n;i>=1;i--) if(a[i]==stx) spx=i;
	for(long long i=m;i>=1;i--) if(b[i]==sty) spy=i;
	
	cur=0;
	long long tot=0;
	for(long long i=1;i<=m;i++) tot+=n-preb[i];
	long long mx1=tot*B,mx2=tot*B-1;
	for(long long i=1;i<=n;i++){
		tot+=(min(cur,prea[i])-(m-max(cur,prea[i])));
		while(cur<=m){
			long long nw=min(i,preb[cur+1])-(n-max(i,preb[cur+1]));
			if(nw<0) break;
			tot+=nw,cur++;
		}
		long long w=0;
		if(i<spx && cur<spy) w=-1;
		
		mx1=max(mx1,tot*B);
		mx2=max(mx2,tot*B+w);
	}
	return (mx1==mx2);
}

long long mna=INF,mxa,mnb=INF,mxb;

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) scanf("%lld",&a[i]),mna=min(mna,a[i]),mxa=max(mxa,a[i]);
	for(long long i=1;i<=m;i++) scanf("%lld",&b[i]),mnb=min(mnb,b[i]),mxb=max(mxb,b[i]);
	stx=a[1],sty=b[1];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	
	long long l=mna+mnb,r=min(stx+sty,mxa+mxb),ans=r;
	while(l<=r){
		long long mid=(l+r)>>1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld",ans);
}
#endif

void solvebs(int L, int R) {
  int res = R;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (check(mid))
      res = mid, R = mid - 1;
    else
      L = mid + 1;
  }
  printf("%d\n", res);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
  sx = a[1], sort(a + 1, a + n + 1), sx = lower_bound(a + 1, a + n + 1, sx) - a;
  sy = b[1], sort(b + 1, b + m + 1), sy = lower_bound(b + 1, b + m + 1, sy) - b;
  solvebs(a[1] + b[1], a[sx] + b[sy]);
  return 0;
}