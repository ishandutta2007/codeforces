#include<cstdio>
using namespace std;
typedef long long ll;
#define maxn 200005
ll n,a[maxn],vis[maxn],sum[maxn];
ll read(){
	ll sum=0;char ch=getchar();
	while (ch<'0'||ch>'9')ch=getchar();
	while (ch>='0'&&ch<='9'){sum=sum*10+ch-'0';ch=getchar();}
	return sum;
}
int main(){
	n=read();for (ll i=1;i<=n;i++)vis[a[i]=read()]++;
	for (ll i=1;i<=200000;i++)sum[i]=vis[i]+sum[i-1];
	ll ans=0;
	for (ll i=1;i<=200000;i++)
		if (vis[i]>0){
			ll res=0,t=200000/i;
			for (ll j=1;j<=t;j++)
				res+=(sum[j*i-1]-sum[(j!=1)?j*i-i-1:j*i-i])*(j-1)*i;
			res+=(sum[200000]-sum[t*i-1])*t*i;
			if (res>ans)ans=res;
		}
	printf("%I64d\n",ans);return 0;
}