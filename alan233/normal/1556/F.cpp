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

const int mod=1e9+7;
int ksm(int a,int b){
    int res=1;
    while(b>0){
        if(b&1)res=1ll*res*a%mod;
        a=1ll*a*a%mod;
        b/=2;
    }
    return res;
}

int a[15],n;
int f[1<<14];

int main(){
    n=read();
    for(int i=0;i<n;i++)a[i]=read();
    int all=1<<n,ans=0;
    for(int S=1;S<all;S++){
        f[S]=1;
        for(int T=(S-1)&S;T;T=(T-1)&S){
            int go=S^T;
            int p=1,q=1;
            for(int i=0;i<n;i++)if(T>>i&1){
                for(int j=0;j<n;j++)if(go>>j&1){
                    p=1ll*p*a[i]%mod;
                    q=1ll*q*(a[i]+a[j])%mod;
                }
            }
            int cf=1ll*p*ksm(q,mod-2)%mod*f[T]%mod;
            f[S]=(f[S]+mod-cf)%mod;
        }
//        printf("f[%d]=%d\n",S,f[S]);
        int p=1,q=1;
        for(int i=0;i<n;i++)if(S>>i&1){
            for(int j=0;j<n;j++)if(!(S>>j&1)){
                p=1ll*p*a[i]%mod;
                q=1ll*q*(a[i]+a[j])%mod;
            }
        }
        int cf=1ll*p*ksm(q,mod-2)%mod;
        ans=(ans+1ll*cf*f[S]%mod*__builtin_popcount(S))%mod;
    }
    printf("%d\n",ans);
    return 0;
}

/*
14
1 2 3 4 5 6 7 8 9 10 11 12 13 14
*/