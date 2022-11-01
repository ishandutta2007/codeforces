#include <bits/stdc++.h>

using namespace std;

const int N=100005;
vector<int> v[N];
int d[N];
long long c[N][3];
int n;

long long solve(int src,vector<int> p)
{
    long long cnt=0;
    int a=0;
    int now=src;
    int idx=0;
    while(1)
    {
        cnt+=c[now][p[(idx++)%3]];
        if(v[now][0]!=a)
        {
            a=now;
            now=v[now][0];
        }
        else if(v[now].size()>1)
        {
            a=now;
            now=v[now][1];
        }
        else break;
    }
    return cnt;
}

vector<int> paint(int src,vector<int> p)
{
    vector<int> res(n+1,0);
    int a=0;
    int now=src;
    int idx=0;
    while(1)
    {
        res[now]=p[(idx++)%3];
        if(v[now][0]!=a)
        {
            a=now;
            now=v[now][0];
        }
        else if(v[now].size()>1)
        {
            a=now;
            now=v[now][1];
        }
        else break;
    }
    return res;
}

int main()
{
    scanf("%d",&n);
    for(int o=0;o<3;o++) for(int i=1;i<=n;i++) scanf("%I64d",&c[i][o]);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        d[a]++;
        d[b]++;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(d[i]>2)
        {
            printf("-1\n");
            return 0;
        }
    }
    int src=0;
    for(int i=1;i<=n;i++) if(d[i]==1) src=i;
    vector<int> res(3);
    long long best=1000000000000000000;
    vector<int> p={0,1,2};
    do
    {
        long long t=solve(src,p);
        if(t<best)
        {
            best=t;
            res=p;
        }
    } while(next_permutation(p.begin(),p.end()));
    vector<int> t=paint(src,res);
    printf("%I64d\n",best);
    for(int i=1;i<=n;i++) printf("%d%c",t[i]+1," \n"[i==n]);
    return 0;
}