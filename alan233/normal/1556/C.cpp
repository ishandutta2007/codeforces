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

void ckmax(ll &x,ll y){
    if(x<y)x=y;
}

const int N=1005;
ll a[N],n;
ll ans;
int main(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int l=1;l<=n;l+=2){
        ll least=1;ll qwq=0;
        for(int r=l+1;r<=n;r+=2){
            if(r!=l+1){
                qwq-=a[r-2];
                ckmax(least,-qwq);
                qwq+=a[r-1];
            }
            ll L=qwq+least,R=min(a[l]+qwq,a[r]);
            L=max(L,1ll);
            if(L<=R)ans+=1ll*(R-L+1);
//            printf("l=%d,r=%d,L=%d,R=%d\n",l,r,L,R);
        }
    }
    printf("%lld\n",ans);
    return 0;
}

/*
[1,4]
[5,5]
[6,7]
[8,10]
[11,11]
*/