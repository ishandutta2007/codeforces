#include<bits/stdc++.h>
using namespace std;
#define int long long

inline int mult(int x,int y)
{
    if(x>2e18/y) return 2e18;
    return x*y;
}

int mypow(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1) ans=mult(ans,a);
        a=mult(a,a);
        b>>=1;
    }
    return ans;
}

int x[60];
void solve()
{
    int l=1,r=1e18;
    scanf("%lld%lld",&l,&r);
    int ans=0;
    if(l==1)l++,ans++;
    for(int p=2;p<60;++p)
    {
        if(!x[p]) continue;
        int s=ceil(pow(l,1./p));
        while(mypow(s,p)<l) s++;
        while(mypow(s-1,p)>=l) s--;
        int e=floor(pow(r,1./p));
        while(mypow(e,p)>r) e--;
        while(mypow(e+1,p)<=r) e++;
        ans+=(e-s+1)*x[p];
    }
    printf("%lld\n",ans);
}


signed main()
{
    for(int p=2;p<60;++p)
    {
        x[p]=1;
        int cnt=0;
        int z=p;
        for(int i=2;i<=p;++i) if(z%i==0)
        {
            cnt++;
            if(z%(i*i)==0) x[p]=0;
            z/=i;
        }
        if(x[p]&&cnt%2==0)x[p]=-1;
    }
    int q=1e5;
    scanf("%lld",&q);
    for(int i=0;i<q;++i) solve();    
    return 0;
}