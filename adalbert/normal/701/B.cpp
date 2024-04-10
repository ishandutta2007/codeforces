#include <bits/stdc++.h>
#include <map>
using namespace std;
long long n,m,x,y,z,w,ans,ka,kb;
string st,s1,s2;
map <long long ,long long > a,b;
char c;
int main()
{
    cin>>n>>m;
    ka=0;
    kb=0;
    for (int i=1;i<=m;i++)
    {
        cin>>x>>y;
        if (a[x]==0)
        {
            a[x]=1;
            ka++;
        }
        if (b[y]==0)
        {
            b[y]=1;
            kb++;
        }
        cout<<n*n-ka*n-kb*n+ka*kb<<' ';

    }
}