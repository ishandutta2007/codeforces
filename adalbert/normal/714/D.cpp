#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fir first
#define sec second
#define mp make_pair
#define _y1 dgkpothjoih
///--------------------------------------------------------------------------------------------------------------///
ll n,_x1[20],_x2[20],_y1[20],_y2[20];
///--------------------------------------------------------------------------------------------------------------///
ll bpowy(ll l, ll r)
{
    while (r-l>1)
    {
        ll s=(l+r)/2;
        cout<<"? "<<1<<' '<<1<<' '<<n<<' '<<s<<'\n';
        cout.flush();
        ll k1;
        cin>>k1;
        if (k1==2)
        {
            r=s;
        } else
        if (k1==0)
        {
            l=s;
        } else
        {
            if (s+1>n) return(0);
            cout<<"? "<<1<<' '<<s+1<<' '<<n<<' '<<n<<'\n';
            cout.flush();
            ll k2;
            cin>>k2;
            if (k1==1 && k2==1) return(s); else
            if (k1>k2) r=s; else l=s;
        }

    }
    ll s=l;
    cout<<"? "<<1<<' '<<1<<' '<<n<<' '<<s<<'\n';
    cout.flush();
    ll k1;
    cin>>k1;
     if (s+1>n) return(0);
    cout<<"? "<<1<<' '<<s+1<<' '<<n<<' '<<n<<'\n';
    cout.flush();
    ll k2;
    cin>>k2;
    if (k1==1 && k2==1) return(l);
    s=r;
    cout<<"? "<<1<<' '<<1<<' '<<n<<' '<<s<<'\n';
    cout.flush();
    k1;
    cin>>k1;
     if (s+1>n) return(0);
    cout<<"? "<<1<<' '<<s+1<<' '<<n<<' '<<n<<'\n';
    cout.flush();
    k2;
    cin>>k2;
    if (k1==1 && k2==1) return(r); else return(0);
}
ll bpowx(ll l, ll r)
{
    while (r-l>1)
    {
        ll s=(l+r)/2;
        cout<<"? "<<1<<' '<<1<<' '<<s<<' '<<n<<'\n';
        cout.flush();
        ll k1;
        cin>>k1;
        if (k1==2)
        {
            r=s;
        } else
        if (k1==0)
        {
            l=s;
        }
        {
            if (s+1>n) return(0);
            cout<<"? "<<s+1<<' '<<1<<' '<<n<<' '<<n<<'\n';
            cout.flush();
            ll k2;
            cin>>k2;
            if (k1==1 && k2==1) return(s); else
            if (k1>k2) r=s; else l=s;
        }

    }
    ll s=l;
    cout<<"? "<<1<<' '<<1<<' '<<s<<' '<<n<<'\n';
    cout.flush();
    ll k1;
    cin>>k1;
     if (s+1>n) return(0);
    cout<<"? "<<s+1<<' '<<1<<' '<<n<<' '<<n<<'\n';
    cout.flush();
    ll k2;
    cin>>k2;
    if (k1==1 && k2==1) return(l); else return(r);
}
void findd (ll x1, ll y1, ll x2, ll y2,ll nom)
{
    ll l=x1;
    ll r=x2;
    while (r-l>1)
    {
        ll s=(l+r)/2;
        ll k1;
        cout<<"? "<<s<<' '<<y1<<' '<<x2<<' '<<y2<<'\n';
        cout.flush();
        cin>>k1;
        if (k1==1) l=s; else r=s;
    }
    ll s=r;
    ll k1;
    cout<<"? "<<s<<' '<<y1<<' '<<x2<<' '<<y2<<'\n';
    cout.flush();
    cin>>k1;
    ll xx1;
    if (k1==1) xx1=r; else xx1=l;
    l=x1;
    r=x2;
    while (r-l>1)
    {
        ll s=(l+r)/2;
        ll k1;
        cout<<"? "<<x1<<' '<<y1<<' '<<s<<' '<<y2<<'\n';
        cout.flush();
        cin>>k1;
        if (k1==1) r=s; else l=s;
    }
    s=l;
    k1;
    cout<<"? "<<x1<<' '<<y1<<' '<<s<<' '<<y2<<'\n';
    cout.flush();
    cin>>k1;
    ll xx2;
    if (k1==1) xx2=l; else xx2=r;





    l=y1;
    r=y2;
    while (r-l>1)
    {
        ll s=(l+r)/2;
        ll k1;
        cout<<"? "<<x1<<' '<<s<<' '<<x2<<' '<<y2<<'\n';
        cout.flush();
        cin>>k1;
        if (k1==1) l=s; else r=s;
    }
    s=r;
    k1;
    cout<<"? "<<x1<<' '<<s<<' '<<x2<<' '<<y2<<'\n';
    cout.flush();
    cin>>k1;
    ll yy1;
    if (k1==1) yy1=r; else yy1=l;
    l=y1;
    r=y2;
    while (r-l>1)
    {
        ll s=(l+r)/2;
        ll k1;
        cout<<"? "<<x1<<' '<<y1<<' '<<x2<<' '<<s<<'\n';
        cout.flush();
        cin>>k1;
        if (k1==1) r=s; else l=s;
    }
    s=l;
    k1;
    cout<<"? "<<x1<<' '<<y1<<' '<<x2<<' '<<s<<'\n';
    cout.flush();
    cin>>k1;
    ll yy2;
    if (k1==1) yy2=l; else yy2=r;
    _x1[nom]=xx1;
    _x2[nom]=xx2;
    _y1[nom]=yy1;
    _y2[nom]=yy2;
}
int main()
{
    cin>>n;
    ll y=bpowy(1,n);
    ll x;
    if (y==0) x=bpowx(1,n);
    if (y!=0)
    {
        findd(1,1,n,y,1);
        findd(1,y+1,n,n,2);
    } else
    {
        findd(1,1,x,n,1);
        findd(x+1,1,n,n,2);
    }
    cout<<'!'<<' '<<_x1[1]<<' '<<_y1[1]<<' '<<_x2[1]<<' '<<_y2[1]<<' '<<_x1[2]<<' '<<_y1[2]<<' '<<_x2[2]<<' '<<_y2[2]<<'\n';
    cout.flush();
}