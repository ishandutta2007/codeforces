#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define left dogjreg
#define int ll
#define right dgfdogjreg
typedef long long ll;
typedef double ld;
const int arr=2e5;

ld v[4*arr],pushp[4*arr],pushm[4*arr];

void remake(int i, int tl, int tr, ld x, ld y)
{
    v[i]=v[i]*x+y*ld(tr-tl+1);
    pushm[i]*=x;
    pushp[i]=pushp[i]*x+y;
}

void make_pushp(int i, int tl, int tr)
{

    if (tl==tr)
        return;
    int d=(tl+tr)/2;

    remake(i*2,tl,d,pushm[i],pushp[i]);
    remake(i*2+1,d+1,tr,pushm[i],pushp[i]);
    pushm[i]=1;
    pushp[i]=0;
}

ld get(int i, int tl, int tr, int l, int r)
{

    if (tl>r || tr<l)
        return(0);
    if (tl>=l && tr<=r)
        return(v[i]);

    make_pushp(i,tl,tr);

    int d=(tl+tr)/2;
    return(get(i*2,tl,d,l,r)+get(i*2+1,d+1,tr,l,r));
}

void pluss(int i, int tl, int tr, int l, int r, ld x, ld y)
{

    if (tl>=l && tr<=r)
    {
        remake(i,tl,tr,x,y);
        return;
    }
    if (tl>r || tr<l)
        return;

    make_pushp(i,tl,tr);

    int d=(tl+tr)/2;

    pluss(i*2,tl,d,l,r,x,y);
    pluss(i*2+1,d+1,tr,l,r,x,y);

    v[i]=v[i*2]+v[i*2+1];
}



signed main()
{
    int n,m;

    for (int i=1;i<4*arr;i++)
    {
        pushm[i]=1;
    }

    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        pluss(1,1,n,i,i,1,a);
    }

    while (m--)
    {
        int t;
        cin>>t;
        if (t==1)
        {
            int l1,r1,l2,r2;
            cin>>l1>>r1>>l2>>r2;

            ld x1=get(1,1,n,l1,r1);
            x1/=ld(r1-l1+1);
            ld x2=get(1,1,n,l2,r2);
            x2/=ld(r2-l2+1);
            pluss(1,1,n,l1,r1,ld(r1-l1)/ld(r1-l1+1),x2/ld(r1-l1+1));
            pluss(1,1,n,l2,r2,ld(r2-l2)/ld(r2-l2+1),x1/ld(r2-l2+1));
        } else
        {
            int l,r;
            cin>>l>>r;
            cout<<fixed<<setprecision(8)<<get(1,1,n,l,r)<<'\n';
        }
    }
}
/*
10 10
1 2 3 4 5 6 7 8 9 10
1 1 5 6 10

*/