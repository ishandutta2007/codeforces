#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define SZ(x) (int(x.size()))
const int inf=1e9;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}

const int N=100005;
ll a[N],sum[N],n,q;
ll f[N][18],g[N][18],lg[N];
ll rmqf(ll (*f)[18],int l,int r){
    int len=lg[r-l+1];
    return min(f[l][len],f[r-(1<<len)+1][len]);
}
ll rmqg(ll (*g)[18],int l,int r){
    int len=lg[r-l+1];
    return max(g[l][len],g[r-(1<<len)+1][len]);
}
int main(){
    n=read(),q=read();
    lg[1]=0;for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)a[i]-=read(),sum[i]=sum[i-1]+a[i],f[i][0]=sum[i],g[i][0]=sum[i];
    for(int j=1;j<18;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);
            g[i][j]=max(g[i][j-1],g[i+(1<<j-1)][j-1]);
        }
    }
    while(q--){
        int l=read(),r=read();
        int go=l;
        if(sum[r]-sum[l-1]){puts("-1");continue;}
        ll t=rmqg(g,l,r);
        if(t-sum[l-1]>0)puts("-1");
        else printf("%lld\n",-(rmqf(f,l,r)-sum[l-1]));
    }
    return 0;
}