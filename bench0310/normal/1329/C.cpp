#include <bits/stdc++.h>

using namespace std;

const int N=(1<<21)+5;
vector<int> a(N,0);
vector<int> pos(N,0);
vector<pair<int,int>> v;

void f(int x)
{
    int l=2*x;
    int r=2*x+1;
    if(a[l]==0&&a[r]==0) v.push_back({x,0});
    else if(a[l]>a[r])
    {
        v.push_back({x,a[l]});
        f(l);
    }
    else
    {
        v.push_back({x,a[r]});
        f(r);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int h,g;
        scanf("%d%d",&h,&g);
        vector<int> val;
        for(int i=1;i<(1<<h);i++)
        {
            scanf("%d",&a[i]);
            pos[a[i]]=i;
            val.push_back(a[i]);
        }
        sort(val.begin(),val.end(),greater<int>());
        vector<int> res;
        for(int x:val)
        {
            f(pos[x]);
            bool ok=1;
            for(auto [id,b]:v) if(id<(1<<g)&&b==0) ok=0;
            if(ok==1)
            {
                res.push_back(pos[x]);
                for(auto [id,b]:v)
                {
                    a[id]=b;
                    pos[b]=id;
                }
            }
            v.clear();
        }
        long long sum=0;
        for(int i=1;i<(1<<g);i++) sum+=a[i];
        printf("%I64d\n",sum);
        for(int x:res) printf("%d ",x);
        printf("\n");
        for(int i=1;i<(1<<(h+1));i++) a[i]=pos[i]=0;
    }
    return 0;
}