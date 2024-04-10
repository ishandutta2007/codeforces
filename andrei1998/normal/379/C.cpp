#include <iostream>
#include <algorithm>

using namespace std;

struct elem
{
    int inf;
    int poz;
}v[300005];

bool operator<(const elem &a,const elem &b)
{
    if(a.inf<b.inf)
        return 1;
    return 0;
}

int m[300005];

int main()
{
    int n,i;
    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>v[i].inf;
        v[i].poz=i;
    }
    sort(v,v+n);

    int curent=1;
    for(i=0;i<n;i++)
    {
        m[v[i].poz]=max(curent,v[i].inf);
        curent=max(curent,v[i].inf)+1;
    }

    for(i=0;i<n;i++)
        cout<<m[i]<<' ';
    cout<<'\n';
    return 0;
}