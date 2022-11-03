#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define time pdojegoritg
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef long double ld;
const int arr=4e5;
const int md=1e18+7;
///magic
/*
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/
///
int a[2000][2000];
set<pair<int,int> > setik;
int n,m,r,k;
int ans=0;

int get1(int u)
{
    return(min(r,min(u,n-max(u,r)+1)));
}
int get2(int u)
{
    return(min(r,min(u,m-max(u,r)+1)));
}

void add(int i, int j)
{
    if (i<1 || j<1 || i>n || j>m)
        return;
    if (setik.count({i,j}))
        return;
    setik.insert({i,j});
    ans+=get1(i)*get2(j);
    k--;
    //cout<<i<<' '<<j<<' '<<get1(i)*get2(j)<<'\n';
    if (k==0)
    {
        cout<<fixed<<setprecision(9)<<ld(ans)/ld((n-r+1)*(m-r+1));
        exit(0);
    }
}

bool check(int i, int j)
{
    if (i<1 || j<1 || i>n || j>m)
        return(0);
        return(1);
}

signed main()
{
    cin>>n>>m>>r>>k;
    int ans=0;

    set<pair<int,pair<int,int> > > setik,used;
    int i=n/2+n%2;
    int j=m/2+m%2;

    setik.insert({get1(i)*get2(j),{i,j}});

    while (k--)
    {
        pair<int,pair<int,int> > now=*setik.rbegin();
        setik.erase(now);
        used.insert(now);
        int i=now.sec.fir;
        int j=now.sec.sec;
        ans+=get1(i)*get2(j);

        i--;
        if (i>0)
            if (!used.count({get1(i)*get2(j),{i,j}}))
            setik.insert({get1(i)*get2(j),{i,j}});
        i++;
        j--;
        if (j>0)
        if (!used.count({get1(i)*get2(j),{i,j}}))
            setik.insert({get1(i)*get2(j),{i,j}});
        j++;

        i++;
        if (i<=n)
            if (!used.count({get1(i)*get2(j),{i,j}}))
            setik.insert({get1(i)*get2(j),{i,j}});
        i--;
        j++;
        if (j<=m)
        if (!used.count({get1(i)*get2(j),{i,j}}))
            setik.insert({get1(i)*get2(j),{i,j}});
        j--;
    }

    cout<<fixed<<setprecision(9)<<ld(ans)/ld((n-r+1)*(m-r+1));
}
/*
3 100 2 100
*/