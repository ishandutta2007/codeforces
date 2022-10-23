#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10,inf=2e9;
int n,m,len1,len2,v,l[N],e[N];

int ans(int x1,int y1,int x2,int y2)
{
    if (x1==x2) return abs(y1-y2);
    if (y1>y2) swap(y1,y2);
    int t1=abs(x1-x2),t2=(t1-1)/v+1;
    int kq1=inf;
    int tmp=lower_bound(l+1,l+len1+1,y1)-l;
    if (tmp!=len1+1 && l[tmp]<=y2) kq1=y2-y1+t1;
    else
    {
        if (tmp>1) kq1=y2-y1+t1+(y1-l[tmp-1])*2;
        if (tmp!=len1+1) kq1=min(kq1,y2-y1+t1+(l[tmp]-y2)*2);
    }
    int kq2=inf;
    tmp=lower_bound(e+1,e+len2+1,y1)-e;
    if (tmp!=len2+1 && e[tmp]<=y2) kq2=y2-y1+t2;
    else
    {
        if (tmp>1) kq2=y2-y1+t2+(y1-e[tmp-1])*2;
        if (tmp!=len2+1) kq2=min(kq2,y2-y1+t2+(e[tmp]-y2)*2);
    }
    return min(kq1,kq2);
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>len1>>len2>>v;
    for (int i=1;i<=len1;i++) cin>>l[i];
    for (int i=1;i<=len2;i++) cin>>e[i];
    int q;
    cin>>q;
    for (int i=1,x1,y1,x2,y2;i<=q;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        cout<<ans(x1,y1,x2,y2)<<"\n";
    }
    return 0;
}