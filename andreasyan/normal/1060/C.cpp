#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=2002;

int n,m;
long long a[N],b[N];
long long t;

long long pb[N];

long long minu[N];

bool stg(int s)
{
    for(int r=1;r<=n;++r)
    {
        long long suma=0;
        for(int l=r;l>=1;--l)
        {
            suma+=a[l];
            int x=(r-l+1);
            int y;
            y=s/x;
            if(s%x>0)
                ++y;
            if(y<=m && suma*minu[y]<=t)
                return true;
        }
    }
    return false;
}

int byn()
{
    int l=0,r=n*m;
    while((r-l)>3)
    {
        int mid=(l+r)/2;
        if(stg(mid))
            l=mid;
        else
            r=mid;
    }
    for(int mid=r;mid>=l;--mid)
        if(stg(mid))
            return mid;
}

int main()
{
    //freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=m;++i)
    {
        cin>>b[i];
        pb[i]=pb[i-1]+b[i];
    }
    cin>>t;
    for(int i=1;i<=m;++i)
    {
        minu[i]=N*N;
        for(int r=i;r<=m;++r)
        {
            int l=r-i+1;
            minu[i]=min(minu[i],pb[r]-pb[l-1]);
        }
    }
    cout<<byn()<<endl;
    return 0;
}