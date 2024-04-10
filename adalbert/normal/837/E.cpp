#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ld  long double
typedef long long ll;

#define int ll
///-------------------///
multiset<int> setik;

int nsd(int a, int b)
{
    while (a!=0 && b!=0)
    {
        if (a>b) a%=b; else
            b%=a;
    }
    return(a+b);
}

int get(int a, int k, int c)
{
    if (c==0) return(0);
    if (c==1) return(1);
    if (k==a) return(c);
    int imx=0;
    int mx=-1;
    for (auto i:setik)
    {
      //  cout<<i<<'\n';
        if (c/i*i>mx)
        {
            mx=c/i*i;
            imx=i;
        }
    }

    setik.erase(setik.find(imx));

    return(get(a,k*imx,c/imx)+c-c/imx*imx);
}

vector<int> parse(int u)
{
    vector<int> res;
    for (int i=2;i*i<=u;i++)
    {
        while (u%i==0)
        {
            u/=i;
            res.pb(i);
        }
    }
    if (u!=1)
        res.pb(u);
    return(res);
}

///---program start---///
signed main()
{
    int a,b;
    cin>>a>>b;
    vector<int> veca=parse(a);
    vector<int> vecb=parse(b);
    for (auto i:veca)
        setik.insert(i);
    for (auto i:vecb)
        if (setik.count(i))
        setik.erase(setik.find(i));
    cout<<get(a,nsd(a,b),b/nsd(a,b));
}