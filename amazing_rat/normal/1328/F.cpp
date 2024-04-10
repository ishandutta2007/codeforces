#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=(1e18);
const int maxn=(2e5)+10;
int n,k,N,a[maxn],b[maxn];
map<int,int> dy,cnt;
ll ans,tmp,t1,t2,t3,tmp1,tmp2;
struct BIT {
	ll tr[maxn],sum;
	void add(int x,ll delta) {
		for (;x<=N;x+=x&(-x)) tr[x]+=delta;
		sum+=delta;
	}
	ll query(int x) {
		ll res=0;
		for (;x;x-=x&(-x)) res+=tr[x];
		return res;
	}
	ll Query(int x) {
		if (x==1) return sum;
		return sum-query(x-1);
	}
} T1,T2;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(k);
	for (int i=1;i<=n;i++) read(a[i]),cnt[a[i]]++;
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) b[i]=a[i];
	N=unique(b+1,b+n+1)-b-1;
	for (int i=1;i<=N;i++) dy[b[i]]=i;
	for (int i=1;i<=N;i++)
		if (cnt[b[i]]>=k) { printf("0\n"); return 0; }
	int x,y;
	for (int i=1;i<=n;i++) {
		x=dy[a[i]];
		T1.add(x,a[i]);
		T2.add(x,1);
	}
	ans=INF;
	for (int i=1;i<=n;i++)
		if (i==1||a[i]!=a[i-1]) {
			x=dy[a[i]];
			t1=t2=tmp1=tmp2=tmp=0;
			t3=cnt[a[i]];
			if (x>2) {
				t1=T2.query(x-2);
				tmp1=t1*b[x-1]-T1.query(x-2);
				t1+=cnt[b[x-1]];
			} else if (x==2) {
				t1=cnt[b[1]];
			}
			if (x<N-1) {
				t2=T2.Query(x+2);
				tmp2=T1.Query(x+2)-t2*b[x+1];
				t2+=cnt[b[x+1]];
			} else if (x==N-1) {
				t2=cnt[b[N]];
			}
			if (t1+t2+t3<k) continue;
			t3=k-t3;
			if (!t1) {
				tmp=tmp2+t2*(b[x+1]-b[x]-1)+t3;
				ans=min(ans,tmp);
			} else if (!t2) {
				tmp=tmp1+t1*(b[x]-b[x-1]-1)+t3;
				ans=min(ans,tmp);
			} else {
				tmp=tmp1+tmp2;
				if (b[x+1]-b[x]>b[x]-b[x-1]) {
					tmp+=t1*(b[x]-b[x-1]-1)+min(t1,t3);
					if (t3-min(t3,t1)>0) tmp+=t2*(b[x+1]-b[x]-1)+t3-min(t3,t1);
				} else {
					tmp+=t2*(b[x+1]-b[x]-1)+min(t2,t3);
					if (t3-min(t3,t2)>0) tmp+=t1*(b[x]-b[x-1]-1)+t3-min(t3,t2);
				}
				ans=min(ans,tmp);
			}
			//if (a[i]==123) printf("%d %lld %lld %lld %lld %lld %lld\n",a[i],t1,t2,t3,tmp,tmp1,tmp2);
			if (t1>=t3&&x>1) tmp=tmp1+t1*(b[x]-b[x-1]-1)+t3,ans=min(ans,tmp);
			if (t2>=t3&&x<N) tmp=tmp2+t2*(b[x+1]-b[x]-1)+t3,ans=min(ans,tmp);
		}
	printf("%lld\n",ans);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/