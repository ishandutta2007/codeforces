#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
const int N=200000;
pii ln[N];
vector<int> tr[2*N];
pii a[N];

int add(vector<int> &v, int num)
{
    if(v.size()==1) return (v[0]<num);
    if(v[0]>=num) return 0;
    int l=0,r=(int)v.size()-1;
    while(l+1<r)
    {
        int m=(l+r)/2;
        if(v[m]>=num)
            r=m-1;
        else
            l=m;
    }
    if(v[r]>=num)
        return l+1;
    return r+1;
}

int rsq(int l, int r, int n, int k)
{
    int res=0;
    for(l+=n,r+=n; l<=r; l=(l+1)>>1,r=(r-1)>>1)
    {
        if(l&1)
            res+=add(tr[l],k);
        if(!(r&1))
            res+=add(tr[r],k);
    }
    return res;
}

int main()
{
//    ifstream cin("input.txt");
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>ln[i].ff>>ln[i].ss,a[i]={ln[i].ff,ln[i].ss};
    sort(a,a+n);
    for(int i=0; i<n; i++)
        tr[i+n].resize(1,a[i].ss);
    for(int i=n-1; i>0; i--)
        merge(tr[i*2].begin(),tr[i*2].end(),tr[i*2+1].begin(),tr[i*2+1].end(),back_inserter(tr[i])),
        sort(tr[i].begin(),tr[i].end());

    for(int i=0; i<n; i++)
    {
        int ql,qr;
        int l,r;
        l=0,r=n-1;
        while(l<r)
        {
            int m=(l+r)/2;
            if(a[m].ff>=ln[i].ff)
                r=m;
            else
                l=m+1;
        }
        ql=l;
        l=0,r=n-1;
        while(l+1<r)
        {
            int m=(l+r)/2;
            if(a[m].ff>=ln[i].ss)
                r=m-1;
            else
                l=m;
        }
        if(a[r].ff>=ln[i].ss)
            qr=l;
        else
            qr=r;
        cout<<rsq(ql,qr,n,ln[i].ss)<<"\n";
    }
    return 0;
}