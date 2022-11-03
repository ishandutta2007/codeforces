#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgjs
#define right rtyjtokh
#define y eth
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
const int md=1e9+7;
const int base=3;
const int arr=2e5+100;

int push[4*arr];

void make_push(int u)
{
    if (push[u]!=0)
    {
        push[u*2]=push[u];
        push[u*2+1]=push[u];
        push[u]=0;
    }
}

void change(int i, int tl, int tr, int l, int r, int x)
{

    if (tl>=l && tr<=r)
    {
        push[i]=x;
        return;
    }

    if (tl>r || tr<l)
        return;

    int d=(tl+tr)/2;

    make_push(i);

    change(i*2,tl,d,l,r,x);
    change(i*2+1,d+1,tr,l,r,x);
}

int get(int i, int tl, int tr, int x)
{
    if (tl==tr)
        return(push[i]);
    int d=(tl+tr)/2;

    make_push(i);

    if (x<=d)
        return(get(i*2,tl,d,x)); else
        return(get(i*2+1,d+1,tr,x));
}

int a[arr],start[arr],last[arr],b[arr];

signed main()
{
    int n,q;
    cin>>n>>q;

    for (int i=1;i<=n;i++)
        cin>>a[i];

    for (int i=1;i<=n;i++)
        if (a[i]!=0)
    {
        if (start[a[i]]==0)
            start[a[i]]=i;
        last[a[i]]=i;
    }

    for (int i=1;i<=q;i++)
        if (start[i]!=0)
    {
        change(1,1,n,start[i],last[i],i);
    }


    bool ch=0;
    for (int i=1;i<=n;i++)
    {
        b[i]=get(1,1,n,i);
        if (b[i]==q)
            ch=1;
    }





    if (!ch)
    {
        for (int i=1;i<=n && !ch;i++)
            if (a[i]==0)
            {
                b[i]=q;
                ch=1;
            }
    }

    if (!ch)
    {
        cout<<"NO";
        return(0);
    }

    for (int i=1;i<=n;i++)
        if (a[i]!=0 && a[i]!=b[i])
    {
        cout<<"NO";
        return(0);
    }

    bool was=0;

    for (int i=1;i<=n;i++)
    {
        if (b[i]==0)
        {
            if (was)
                b[i]=b[i-1]; else
                {
                    int pl=i+1;
                    while (b[pl]==0)
                        pl++;
                    for (int j=i;j<pl;j++)
                        b[j]=b[pl];
                }
        }
        was=1;
    }

    cout<<"YES\n";

    for (int i=1;i<=n;i++)
        cout<<b[i]<<' ';

}