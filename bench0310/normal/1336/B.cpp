#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        vector<int> n(3,0);
        for(int i=0;i<3;i++) scanf("%d",&n[i]);
        vector<set<int>> s(3);
        for(int o=0;o<3;o++)
        {
            while(n[o]--)
            {
                int a;
                scanf("%d",&a);
                s[o].insert(a);
            }
        }
        auto cl=[](int x,set<int> &y)->array<ll,3>
        {
            array<ll,3> res={-1,-1,-1};
            auto it=y.lower_bound(x);
            if(it!=y.end())
            {
                res[1]=*it;
                it++;
                if(it!=y.end()) res[2]=*it;
                it--;
            }
            if(it!=y.begin())
            {
                it--;
                res[0]=*it;
            }
            return res;
        };
        auto sq=[](ll x)->ll
        {
            return x*x;
        };
        ll res=(1ll<<62);
        for(int o=0;o<3;o++)
        {
            for(int x:s[o])
            {
                vector<bool> v(3,1);
                v[o]=0;
                int idx=0;
                if(v[idx]==0) idx++;
                array<ll,3> one=cl(x,s[idx]);
                idx++;
                if(v[idx]==0) idx++;
                array<ll,3> two=cl(x,s[idx]);
                for(int y:one) for(int z:two) if(y!=-1&&z!=-1) res=min(res,sq(x-y)+sq(x-z)+sq(y-z));
            }
        }
        printf("%I64d\n",res);
    }
    return 0;
}