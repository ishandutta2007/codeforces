#include <bits/stdc++.h>
using namespace std;
const int N=102;

int n,m;
int a[N],b[N];
int bsum;

bool stg(int c[])
{
    for(int i=1;i<=m;++i)
        if(c[i]!=b[i])
            return false;
    return true;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=m;++i)
    {
        cin>>b[i];
        bsum+=b[i];
    }
    for(int l=1;(l+bsum-1)<=n;++l)
    {
        int c[N]={};
        int r=(l+bsum-1);
        for(int i=l;i<=r;++i)
            c[a[i]]++;
        if(stg(c))
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}