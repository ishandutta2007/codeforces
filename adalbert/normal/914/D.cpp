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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=6e5+100;
int md=1e9+7;

int bs=400;

int a[arr];
int v[4*arr];
int cnt;

int nsd(int a, int b)
{
    while (a!=0 && b!=0)
        if (a>b)
        a%=b; else
        b%=a;
    return(a+b);
}

void change(int i, int tl, int tr, int x, int y)
{
    if (tl==tr)
    {
        v[i]=y;
        return;
    }

    int d=(tl+tr)/2;
    if(x<=d)
        change(i*2,tl,d,x,y); else
        change(i*2+1,d+1,tr,x,y);
    v[i]=nsd(v[i*2],v[i*2+1]);
}

void get(int i, int tl, int tr, int l, int r, int x)
{
    if (cnt>1)
        return;
    if (tl>r || tr<l)
        return;
    if (tl==tr)
    {
        if (v[i]%x!=0)
            cnt++;
        return;
    }
    if (v[i]%x==0)
        return;

    int d=(tl+tr)/2;
    get(i*2,tl,d,l,r,x);
    if (cnt>1)
        return;
    get(i*2+1,d+1,tr,l,r,x);
}

signed main()
{
    fast;
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        change(1,1,n,i,a[i]);
    }

    int q;
    cin>>q;
    while (q--)
    {
        int type;
        cin>>type;
        if (type==1)
        {
            int l,r,x;
            cin>>l>>r>>x;
            cnt=0;
            get(1,1,n,l,r,x);
            if (cnt>1)
                cout<<"NO"<<'\n'; else
                cout<<"YES"<<'\n';
        } else
        {
            int i,y;
            cin>>i>>y;
            change(1,1,n,i,y);
        }
    }


}