#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=100005;

int n,k;

int a[N];

int kk;
void rec(int l,int r,int ll)
{
    if(l==r-1)
    {
        a[l]=ll;
        return;
    }
    if(kk+2>k)
    {
        for(int i=l,j=ll;i<r;++i,++j)
            a[i]=j;
        return;
    }
    kk+=2;
    int m=(l+r)/2;
    rec(l,m,ll+(r-m));
    rec(m,r,ll);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("search.in","r",stdin);
    //freopen("search.out","w",stdout);
    cin>>n>>k;
    kk=1;
    rec(0,n,1);
    if(kk!=k)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    for(int i=0;i<n;++i)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}