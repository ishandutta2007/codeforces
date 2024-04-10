#include <bits/stdc++.h>
using namespace std;
#define sec second
#define fir first
#define pb push_back
#define mp_ make_pair
typedef long double ld;
typedef long long  ll;
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

///------------------------------------------------------------///
string t[200000],st[200000];
ll s,m,l,xl,xxl,xxxl;
///------------------------------------------------------------///

///------------------------------------------------------------///
int main()
{
    fast;
    cin>>s>>m>>l>>xl>>xxl>>xxxl;
    ll n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>st[i];
    for (int i=1;i<=n;i++)
        if (st[i]=="S")
        {
            t[i]="S";
            s--;
        } else
        if (st[i]=="M")
        {
            t[i]="M";
            m--;
        }else
        if (st[i]=="L")
        {
            t[i]="L";
            l--;
        } else
        if (st[i]=="XL")
        {
            t[i]="XL";
            xl--;
        }else
        if (st[i]=="XXL")
        {
            xxl--;
            t[i]="XXL";
        } else
        if (st[i]=="XXXL")
        {
            xxxl--;
            t[i]="XXXL";
        }
    for (int i=1;i<=n;i++)
        if (st[i]=="S,M" )
    {
        if (s!=0)
        {
            s--;
            t[i]="S";
        } else
        {
            t[i]="M";
            m--;
        }
    }
    for (int i=1;i<=n;i++)
        if (st[i]=="M,L" )
    {
        if (m!=0)
        {
            m--;
            t[i]="M";
        } else
        {
            l--;
            t[i]="L";
        }
    }
    for (int i=1;i<=n;i++)
        if (st[i]=="L,XL" )
    {
        if (l!=0)
        {
            l--;
            t[i]="L";
        } else
        {
            xl--;
            t[i]="XL";
        }
    }
    for (int i=1;i<=n;i++)
        if (st[i]=="XL,XXL" )
    {
        if (xl!=0)
        {
            xl--;
            t[i]="XL";
        }else
        {
            t[i]="XXL";
            xxl--;
        }
    }
    for (int i=1;i<=n;i++)
        if (st[i]=="XXL,XXXL" )
    {
        if (xxl!=0)
        {
            xxl--;
            t[i]="XXL";
            } else
            {
                t[i]="XXXL";
                xxxl--;
            }
    }
    if (s>=0 && l>=0 && m>=0 && xl>=0 && xxl>=0 && xxxl>=0)
    {
        cout<<"YES"<<'\n';
        for (int i=1;i<=n;i++)
            cout<<t[i]<<'\n';
        } else cout<<"NO";
}