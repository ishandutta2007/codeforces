#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,m;
    scanf("%I64d%I64d",&n,&m);
    vector<long long> l(m);
    long long sum=0;
    for(int i=0;i<m;i++)
    {
        scanf("%I64d",&l[i]);
        sum+=l[i];
    }
    bool ok=(sum>=n);
    vector<int> res(m,1);
    for(int i=0;i<m;i++)
    {
        res[i]=i+1;
        if(res[i]+l[i]-1>n) ok=0;
    }
    long long now=n;
    for(int i=m-1;i>=0;i--)
    {
        if(res[i]+l[i]-1<now) res[i]=now-l[i]+1;
        now=res[i]-1;
    }
    if(ok) for(int i=0;i<m;i++) printf("%d%c",res[i]," \n"[i==n-1]);
    else printf("-1\n");
    return 0;
}