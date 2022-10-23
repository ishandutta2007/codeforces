#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <fstream>
using namespace std;
const int maxn=int(1e5)+10;
struct st
{
    int v,nb;
};
long long a[maxn],c[maxn],t[maxn],d[maxn],n,m;
st c2[maxn];

bool qt(st t1,st t2)
{
    return (t1.v<t2.v);
}
int main()
{
    //freopen("m.inp","r",stdin);
    //freopen("m.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++)
    {
        cin>>c[i];
        c2[i].v=c[i];
        c2[i].nb=i;
    }
    for (int i=1;i<=m;i++) cin>>t[i]>>d[i];
    sort(c2+1,c2+n+1,qt);
    long long ch=1,vl;
    for (int i=1;i<=m;i++)
    if (a[t[i]]>=d[i])
    {
        cout<<c[t[i]]*d[i]<<endl;
        a[t[i]]-=d[i];
    }
    else if (ch<=n)
    {
        vl=a[t[i]]*c[t[i]];
        d[i]=d[i]-a[t[i]];
        a[t[i]]=0;
        while (d[i]>0 && ch<=n)
        {
            while (ch<=n && a[c2[ch].nb]==0) ch++;
            if (ch>n) break;
            if (a[c2[ch].nb]>=d[i])
            {
                vl=vl+d[i]*c[c2[ch].nb];
                a[c2[ch].nb]-=d[i];
                d[i]=0;
                break;
            }
            else
            {
                vl=vl+a[c2[ch].nb]*c[c2[ch].nb];
                d[i]-=a[c2[ch].nb];
                a[c2[ch].nb]=0;
            }
        }
        if (d[i]==0) cout<<vl<<endl; else cout<<0<<endl;
    }
    else cout<<0<<endl;
    //for (int i=1;i<=n;i++) cout<<a[i]<<endl;
    return 0;
}