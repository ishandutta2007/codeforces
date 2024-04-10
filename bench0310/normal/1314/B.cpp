#include <bits/stdc++.h>

using namespace std;

array<int,4> solve(array<int,4> a,array<int,4> b)
{
    array<int,4> r;
    for(int j=0;j<4;j++) r[j]=-1;
    for(int o=0;o<4;o++) //state a
    {
        for(int i=0;i<4;i++) //state b
        {
            if(a[o]==-1||b[i]==-1) continue;
            bool wa=((o&2)>0);
            bool la=((o&1)>0);
            bool wb=((i&2)>0);
            bool lb=((i&1)>0);
            for(int da=0;da<2;da++) //0-win 1-lose
            {
                for(int db=0;db<2;db++) // 0-win 1-lose
                {
                    bool ta=(la||(wa&&da==1)); //third match of a
                    bool tb=(lb||(wb&&db==1)); //third match of b
                    bool wr=((wa&&da==0)||(wb&&db==0));
                    bool lr=(ta||tb);
                    int mask=(2*(int)(wr))+(int)(lr);
                    int now=a[o]+b[i]+(int)(ta)+(int)(tb)+(int)(wr)+(int)(lr);
                    r[mask]=max(r[mask],now);
                }
            }
        }
    }
    return r;
}

array<int,4> init(int a,int b)
{
    array<int,4> r;
    for(int j=0;j<4;j++) r[j]=-1;
    for(int o=0;o<2;o++) //pos of a
    {
        for(int i=0;i<2;i++) //pos of b
        {
            bool wr=((a==2||(a==1&&o==0))||(b==2||(b==1&&i==0)));
            bool lr=((a==2||(a==1&&o==1))||(b==2||(b==1&&i==1)));
            int mask=(2*(int)(wr))+(int)(lr);
            int cnt=((int)(a>0))+((int)(b>0));
            r[mask]=max(r[mask],cnt+(int)(wr)+(int)(lr));
        }
    }
    return r;
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> x((1<<n),0);
    for(int i=0;i<k;i++)
    {
        int t;
        scanf("%d",&t);
        t--;
        x[t]=1;
    }
    vector<array<int,4>> v;
    for(int o=0;o<(1<<n);o+=4)
    {
        v.push_back(init(x[o]+x[o+1],x[o+2]+x[o+3]));
    }
    while(v.size()>1)
    {
        vector<array<int,4>> t=v;
        v.clear();
        for(int i=0;i<(int)t.size();i+=2)
        {
            v.push_back(solve(t[i],t[i+1]));
        }
    }
    int res=0;
    for(int i=0;i<4;i++)
    {
        if(v[0][i]==-1) continue;
        bool w=((i&2)>0);
        bool l=((i&1)>0);
        int cnt=(w||l);
        res=max(res,v[0][i]+2*cnt);
    }
    printf("%d\n",res);
    return 0;
}