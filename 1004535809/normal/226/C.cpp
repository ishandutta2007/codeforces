#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
int mod;ll l,r,k;
struct mat{
	int a[3][3];
	mat(){memset(a,0,sizeof(a));}
	mat operator *(const mat &rhs){
		mat ret;
		for(int i=1;i<=2;i++) for(int j=1;j<=2;j++) for(int k=1;k<=2;k++)
			ret.a[i][j]=(ret.a[i][j]+1ll*a[i][k]*rhs.a[k][j]%mod)%mod;
		return ret;
	}
};
int fib(ll n){
	mat x,y,z;x.a[1][1]=x.a[1][2]=1;y.a[1][1]=y.a[2][2]=1;z.a[1][2]=z.a[2][1]=z.a[2][2]=1;
	n--;for(;n;n>>=1,z=z*z) if(n&1) y=y*z;x=x*y;return x.a[1][1];
}
int main(){
	scanf("%d%lld%lld%lld",&mod,&l,&r,&k);
	ll mx=0;for(ll i=1;i*i<=r;i++){
		if((r/i)-((l-1)/i)>=k) chkmax(mx,i);
		if((r/(r/i))-((l-1)/(r/i))>=k) chkmax(mx,r/i); 
	} printf("%d\n",fib(mx));
	return 0;
}