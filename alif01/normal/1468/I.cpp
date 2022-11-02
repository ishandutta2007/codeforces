#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

ll exgcd(ll a,ll b,ll &x,ll &y) {
    if (!b) {
    	x=1;y=0;
    	return a;
    }
	ll d=exgcd(b,a%b,x,y),t=x;
	x=y;
	y=t-(a/b)*y;
	return d;
}

int n;
ll dx1,dy1,dx2,dy2;
int main() {
	scanf("%d",&n);
	scanf("%lld%lld%lld%lld",&dx1,&dy1,&dx2,&dy2);
	ll det=dx1*dy2-dy1*dx2;
	det=abs(det);
	if (n!=det) {
		puts("NO");
		return 0;
	}
	ll px=0,py=0,qx=0,qy=0;
	int dim=0;
	rep(i,0,2) {
		ll x,y;
		if (i==0) x=dx1,y=dy1;
		else x=dx2,y=dy2;
		if (dim==0) {
			px=x; py=y;
			dim=1;
		} else if (dim==1) {
			if (x*py==y*px) {
				px=gcd(px,x); py=gcd(py,y);
			} else {
				ll a=0,b=0,d=0;
				d=exgcd(y,py,a,b);
				ll rx=x*a+px*b,ry=d;
				ll fx=(x*(py/d)-px*(y/d));
				if (fx<0) fx=-fx;
				rx%=fx; if (rx<0) rx+=fx;
				px=fx; py=0; qx=rx; qy=ry;
				dim=2;
			}
		} else if (dim==2) {
			ll a=0,b=0,d=0;
			d=exgcd(y,qy,a,b);
			ll rx=x*a+qx*b,ry=d;
			rx%=px;
			px=gcd(gcd((x-y/ry*rx)%px,(qx-qy/ry*rx)%px),px);
			if (px<0) px=-px;
			qx=rx%px; qy=ry;
			if (qx<0) qx+=px;
		}
	}
	qy=abs(qy); px=abs(px);
	//printf("%lld %lld %lld %lld\n",px,py,qx,qy);
	assert(px*qy==n&&px>0&&qy>0);
	puts("YES");
	rep(j,0,px) rep(i,0,qy) printf("%d %d\n",j,i);
	//printf("%lld %lld %lld %lld\n",px,py,qx,qy);
}