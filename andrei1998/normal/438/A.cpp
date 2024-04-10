#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct elem
{
    int val;
    int cine;

    elem()
    {
        val=cine=0;
    }

    elem(int a,int b)
    {
        val=a;
        cine=b;
    }

}v[1005];

bool operator<(const elem &a,const elem &b)
{
    return (a.val>b.val);
}

int grad[1005];
int val[1005];
set<int> graf[1005];

int main()
{
    int n,m;
    cin>>n>>m;

    int i;
    for(i=1;i<=n;i++)
    {
        cin>>val[i];
        v[i]=elem(val[i],i);
    }
    sort(v+1,v+n+1);

    int a,b;
    while(m--)
    {
        cin>>a>>b;
        grad[a]++;
        grad[b]++;

        graf[a].insert(b);
        graf[b].insert(a);
    }

    long long int s=0;
    for(i=1;i<=n;i++)
        s+=(1ll*val[i]*grad[i]);

    long long int sol=0;
    set<int>::iterator it;

    for(i=1;i<=n;i++)
    {
        sol+=(1ll*(val[v[i].cine]*grad[v[i].cine]));

        for(it=graf[v[i].cine].begin();it!=graf[v[i].cine].end();it++)
        {
            grad[*it]--;
            graf[*it].erase(v[i].cine);
        }
    }

    cout<<(s-sol)<<'\n';

    return 0;
}