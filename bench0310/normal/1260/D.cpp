#include <bits/stdc++.h>

using namespace std;

const int N=200005;
struct trap
{
    int l,r,d;
};
int m,n,k,t;
vector<int> danger[N];
vector<int> sw[N];
vector<trap> traps;

bool solve(int lim)
{
    int group=0;
    vector<bool> disarmed(k,0);
    int cnt=0;
    while(group<=n)
    {
        int far=group;
        for(int id:danger[group+1])
        {
            if(disarmed[id]==0&&traps[id].d>lim) far=max(far,traps[id].r);
        }
        for(int i=group+1;i<=far;i++)
        {
            for(int id:sw[i]) disarmed[id]=1;
            for(int id:danger[i]) if(disarmed[id]==0&&traps[id].d>lim) far=max(far,traps[id].r);
        }
        cnt+=2*(far-group);
        group++;
        cnt++;
    }
    return (cnt<=t);
}

int main()
{
    scanf("%d%d%d%d",&m,&n,&k,&t);
    vector<int> v(m);
    for(int i=0;i<m;i++) scanf("%d",&v[i]);
    sort(v.begin(),v.end(),greater<int>());
    traps.resize(k);
    for(int i=0;i<k;i++)
    {
        int l,r,d;
        scanf("%d%d%d",&l,&r,&d);
        danger[l].push_back(i);
        sw[r].push_back(i);
        trap temp;
        tie(temp.l,temp.r,temp.d)=make_tuple(l,r,d);
        traps[i]=temp;
    }
    int l=0,r=m+1;
    while(l<r-1)
    {
        int mid=(l+r)/2;
        if(solve(v[mid-1])) l=mid;
        else r=mid;
    }
    printf("%d\n",l);
    return 0;
}