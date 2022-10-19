#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=(1e9);
int n,tot,x[1010],y[1010];
ll ans,cnt;
struct node {
	ll x,y,a,b;
	void init() {
		if (y<0) x=-x,y=-y;
		if (b<0) a=-a,b=-b;
	}
	friend bool operator < (node t1,node t2) {
		if (t1.x==INF||t2.x==INF) {
			if (t1.x!=t2.x) return t1.x==INF;
			return t1.a<t2.a;
		}
		if (t1.x*t2.y==t1.y*t2.x) {
			return t1.a*t2.b<t1.b*t2.a;
		}
		return t1.x*t2.y<t1.y*t2.x;
	}
	friend bool operator == (node t1,node t2) {
		if (t1.x==INF||t2.x==INF) return t1.x==t2.x;
		return t1.x*t2.y==t1.y*t2.x;
	}
	friend bool operator & (node t1,node t2) {
		if (t1.x==INF||t2.x==INF) return t1.x==t2.x&&t1.a==t2.a;
		return t1.x*t2.y==t1.y*t2.x&&t1.a*t2.b==t1.b*t2.a;
	}
} d[1000010];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++)
		read(x[i]),read(y[i]);
	for (int i=1;i<=n;i++) {
		for (int j=i+1;j<=n;j++) {
			tot++;
			if (x[i]==x[j]) d[tot].x=INF,d[tot].a=x[i];
			else {
				d[tot].x=y[j]-y[i],d[tot].y=x[j]-x[i];
				d[tot].a=y[i]*x[j]-y[j]*x[i];
				d[tot].b=x[j]-x[i];
			} d[tot].init();
		}
	}
	sort(d+1,d+tot+1); ll sum=tot;
	//for (int i=1;i<=tot;i++)
		//printf("%lld %lld %lld %lld\n",d[i].x,d[i].y,d[i].a,d[i].b);
	for (int i=1;i<=tot;i++) {
		if (i>1&&d[i]==d[i-1]) {
			if (i>1&&d[i]&d[i-1]) sum--; else cnt++;
		} else ans+=cnt*(cnt-1)/2,cnt=1;
		//printf("%lld\n",cnt);
	}
	ans+=cnt*(cnt-1)/2;
	//printf("%lld\n",sum*(sum-1)/2);
	printf("%lld\n",sum*(sum-1)/2-ans);
	return 0;
}