#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int N=400005;
struct ban
{
    int l,r,i;
};
bool operator<(const ban& a,const ban& b)
{
    return (a.r<b.r);
}

int n;
int ans[N];
ban a[N];
vector<int> b;
map<int,int> h;

int t[N*4];
void ubd(int tl,int tr,int x,int pos)
{
    if(tl==tr)
    {
        t[pos]=1;
        return;
    }
    int m=(tl+tr)/2;
    if(x<=m)
        ubd(tl,m,x,pos*2);
    else
        ubd(m+1,tr,x,pos*2+1);
    t[pos]=t[pos*2]+t[pos*2+1];
}
int qry(int tl,int tr,int l,int r,int pos)
{
    if(tl==l && tr==r)
        return t[pos];
    int m=(tl+tr)/2;
    if(r<=m)
        return qry(tl,m,l,r,pos*2);
    else if(l>m)
        return qry(m+1,tr,l,r,pos*2+1);
    else
        return qry(tl,m,l,m,pos*2)+qry(m+1,tr,m+1,r,pos*2+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;++i)
    {
        a[i].i=i;
        cin>>a[i].l>>a[i].r;
        b.push_back(a[i].l);
        b.push_back(a[i].r);
    }
    sort(b.begin(),b.end());
    for(int i=0;i<b.size();++i)
        h[b[i]]=i;
    sort(a,a+n);
    for(int i=0;i<n;++i)
    {
        int l=h[a[i].l];
        int r=h[a[i].r];
        ans[a[i].i]=qry(0,n*2,l,r,1);
        ubd(0,n*2,l,1);
    }
    for(int i=0;i<n;++i)
        cout<<ans[i]<<endl;
    return 0;
}