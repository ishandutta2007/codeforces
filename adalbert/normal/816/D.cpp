#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define time pdojegoritg
#define pb push_back
#define int ll
typedef long long ll;
typedef long double ld;
const int arr=300000+10;
const int md=1e9+7;

int fact[arr];

int pow(int u, int step)
{
    if (step==1) return(u);
    if (step%2==0)
    {
        int now=pow(u,step/2);
        return(now*now%md);
    }
    if (step%2==1)
    {
        return(u*pow(u,step-1)%md);
    }
}

int dil(int a, int b)
{
    b=pow(b,md-2);
    return(a*b%md);
}

int get(int n, int m)
{
    if (m<0) return(0);
    int ans=fact[n];
    ans=dil(ans,fact[m]);
    ans=dil(ans,fact[n-m]);
    return(ans);
}

int pluss(int a, int b)
{
    return(((a+b+md)%md+md)%md);
}

int get(int pos, int n, int a)
{
    if (n%4==0)
    {
        if (pos%2==1)
        {
            return(get((n-2)/2,(pos-1)/2));
        } else 
        if (pos%2==0)
        {
            return(-get((n-2)/2,(pos-1)/2));
        }
    }
    
    if (n%4==1)
    {
        if (pos%2==1)
        {
            return(get((n-1)/2,(pos-1)/2));
        } else 
        if (pos%2==0)
        {
            return(0);
        }
    }
    
    if (n%4==2)
    {
        if (pos%2==1)
        {
            return(get((n-2)/2,(pos-1)/2));
        } else 
        if (pos%2==0)
        {
            return(get((n-2)/2,(pos-1)/2));
        }
    }
    
    if (n%4==3)
    {
        if (pos%2==1)
        {
            return(pluss(get((n-3)/2,pos/2),-(get((n-3)/2,pos/2-1))));
        } else 
        if (pos%2==0)
        {
            return(pluss(get((n-3)/2,(pos-1)/2),get((n-3)/2,(pos-1)/2)));
        }
    }
}

signed main()
{
    int n;
    cin>>n;
    
    fact[0]=1;
    for (int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i%md;
    
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        ans=pluss(ans,get(i,n,a)*a%md);
    }        
    cout<<ans;
}