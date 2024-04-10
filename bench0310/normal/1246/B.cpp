#include <bits/stdc++.h>

using namespace std;

const long long N=100000;
vector<int> sieve(N+1,0);

void ini()
{
    for(int i=0;i<=N;i++) sieve[i]=i;
    for(int o=2;o*o<=N;o++)
    {
        if(sieve[o]!=o) continue;
        for(int i=o*o;i<=N;i+=o)
        {
            if(sieve[i]==i) sieve[i]=o;
        }
    }
}

int odd(int a)
{
    if(a==1) return 1;
    int res=1;
    int now=sieve[a];
    int cnt=0;
    while(a!=1)
    {
        if(sieve[a]==now) cnt++;
        else
        {
            if(cnt&1) res*=now;
            now=sieve[a];
            cnt=1;
        }
        a/=sieve[a];
    }
    if(cnt&1) res*=now;
    return res;
}

int main()
{
	long long n,k;
	scanf("%I64d%I64d",&n,&k);
	vector<long long> m(N+1,0);
	for(int i=0;i<n;i++)
    {
        long long t;
        scanf("%I64d",&t);
        m[t]++;
    }
    if(k==2)
    {
        ini();
        vector<long long> d(N+1,0);
        for(int i=1;i<=N;i++) d[odd(i)]+=m[i];
        long long res=0;
        for(int i=1;i<=N;i++) res+=(d[i]*(d[i]-1)/2);
        printf("%I64d\n",res);
    }
    else
    {
        vector<long long> v;
        for(long long x=1;;x++)
        {
            long long b=1;
            for(int i=0;i<k;i++)
            {
                b*=x;
                if(b>N*N) break;
            }
            if(b>N*N) break;
            v.push_back(b);
        }
        long long res=0;
        for(long long a:v)
        {
            for(long long i=1;i*i<=a;i++)
            {
                if((a%i)!=0) continue;
                if(a/i>N) continue;
                if(i*i<a) res+=m[i]*m[a/i];
                else res+=(m[i]*(m[i]-1)/2);
            }
        }
        printf("%I64d\n",res);
    }
	return 0;
}