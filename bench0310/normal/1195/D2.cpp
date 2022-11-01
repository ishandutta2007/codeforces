#include <bits/stdc++.h>

using namespace std;

const long long mod=998244353;
long long res=0;

void modify(long long &a)
{
    if(a>=mod) a%=mod;
}

void solve(long long a,long long one,long long two,long long num,bool pos) //a,len_a,len_b,pos
{
    long long now=0;
    long long b=1;
    if(pos==1)
    {
        b*=10;
        two--;
    }
    while(a)
    {
        long long d=(a%10);
        a/=10;
        now+=d*b;
        modify(now);
        b*=10;
        modify(b);
        if(two>0)
        {
            b*=10;
            modify(b);
            two--;
        }
    }
    now*=num;
    modify(now);
    res+=now;
    modify(res);
}

long long length(long long a)
{
    long long t=0;
    while(a)
    {
        t++;
        a/=10;
    }
    return t;
}

int main()
{
	long long n;
	scanf("%I64d",&n);
	vector<long long> v(11,0);
	long long a[n];
	for(int i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
        v[length(a[i])]++;
    }
    for(int o=0;o<n;o++)
    {
        long long now=a[o];
        long long len=length(now);
        for(int i=1;i<=10;i++)
        {
            for(int j=0;j<2;j++)
            {
                solve(now,len,i,v[i],j);
            }
        }
    }
    printf("%I64d\n",res);
	return 0;
}