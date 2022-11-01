#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<long long> v(n+1);
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&v[i]);
        sum+=v[i];
    }
    int q;
    scanf("%d",&q);
    map<pair<int,int>,int> m;
    vector<int> cnt(n+1,0);
    long long t=0;
    while(q--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(m.find({a,b})!=m.end())
        {
            int e=m[{a,b}];
            m.erase({a,b});
            if(cnt[e]<=v[e]) t--;
            cnt[e]--;
        }
        if(c!=0)
        {
            m[{a,b}]=c;
            if(cnt[c]<v[c]) t++;
            cnt[c]++;
        }
        printf("%I64d\n",sum-t);
    }
    return 0;
}