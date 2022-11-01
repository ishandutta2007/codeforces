#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long u,v;
    scanf("%I64d%I64d",&u,&v);
    if(!(u<=v&&((v-u)%2)==0))
    {
        printf("-1\n");
        return 0;
    }
    long long a=u;
    v=(v-u)/2;
    long long b=0,c=0;
    int idx=0;
    while(v)
    {
        if(v&1)
        {
            b+=(1ll<<idx);
            if((a&(1ll<<idx))==0) a+=(1ll<<idx);
            else c+=(1ll<<idx);
        }
        idx++;
        v/=2;
    }
    vector<long long> res;
    for(long long x:{a,b,c}) if(x!=0) res.push_back(x);
    printf("%d\n",(int)res.size());
    for(long long x:res) printf("%I64d ",x);
    printf("\n");
    return 0;
}