#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a,long long b)
{
    if(!b) return a;
    else return gcd(b,a%b);
}

int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        long long n;
        scanf("%I64d",&n);
        vector<long long> v(n);
        for(int i=0;i<n;i++) scanf("%I64d",&v[i]);
        sort(v.begin(),v.end(),greater<long long>());
        long long x,a;
        scanf("%I64d%I64d",&x,&a);
        long long y,b;
        scanf("%I64d%I64d",&y,&b);
        long long k;
        scanf("%I64d",&k);
        long long l=0,r=n+1;
        long long lcm=a*b/gcd(a,b);
        while(l<r-1)
        {
            long long m=(l+r)/2;
            int idx=0;
            long long cc=m/lcm;
            long long aa=m/a-cc;
            long long bb=m/b-cc;
            long long res=0;
            for(int i=0;i<cc;i++) res+=((x+y)*v[idx++])/100;
            if(x>=y)
            {
                for(int i=0;i<aa;i++) res+=((x*v[idx++])/100);
                for(int i=0;i<bb;i++) res+=((y*v[idx++])/100);
            }
            else
            {
                for(int i=0;i<bb;i++) res+=((y*v[idx++])/100);
                for(int i=0;i<aa;i++) res+=((x*v[idx++])/100);
            }
            if(res>=k) r=m;
            else l=m;
        }
        if(r<=n) printf("%I64d\n",r);
        else printf("-1\n");
    }
    return 0;
}