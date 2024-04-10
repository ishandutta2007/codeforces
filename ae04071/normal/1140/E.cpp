#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const lli MOD=998244353;
int n,k,arr[200000];

lli power(lli a,lli p) {
    lli res=1;
    while(p) {
        if(p&1) res=res*a%MOD;
        a=a*a%MOD;
        p>>=1;
    }
    return res;
}
lli f(int i) {
    lli res=1;
    for(;i<n;) {
        if(arr[i]!=-1) {
            if(i+2<n && arr[i+2]==arr[i]) return 0;
            i+=2;
        } else {
            lli s;
            if(i-2<0) {
                s=k;

                int j=i+2;
                for(;j<n && arr[j]==-1;j+=2) s=(s*k%MOD-s+MOD)%MOD;
                if(j>=n) res=res*s%MOD;
                else {
                    int c=(j-i)/2;
                    s = (s - power(k-1,c-1) + MOD)%MOD;
                    res=res*s%MOD;
                }
                i=j;
            } else {
                s=k-1;

                int j=i+2;
                for(;j<n && arr[j]==-1;j+=2) s=(s*k%MOD-s+MOD)%MOD;
                if(j>=n) res=res*s%MOD;
                else {
                    lli ts=0;
                    int c=(j-i)/2;
                    for(int t=0;t<(j-i)/2;t++) {
                        if(i-2>=0 && arr[i-2]==arr[j] && t==c-1) break;
                        if(t%2==0) ts = (ts + power(k-1,c-t-1))%MOD;
                        else ts = (ts - power(k-1,c-t-1)+MOD)%MOD;
                    }
                    s= (s- ts + MOD)%MOD;
                    res=res*s%MOD;
                }
                i=j;
            }
        }
    }
    return res;
}
int main() {
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",arr+i);

    if(k==1) {
        if(n>2) {
            puts("0");
        }else puts("1");
        return 0;
    }

    lli ans=1;
    ans=ans*f(0)%MOD;
    ans=ans*f(1)%MOD;
    printf("%lld\n",ans);

    return 0;
}