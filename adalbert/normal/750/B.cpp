#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define int ll
#define y1 humiuyn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);

///-----------------------------------------------------------------------///
signed main()
{
    ll n;
    int tx=0;
    int ty=0;
    cin>>n;
    while (n--)
    {
        int x;
        cin>>x;
        string st;
        cin>>st;
        if (st!="South" && tx==0)
        {
            cout<<"NO";
            return(0);
        }
        if (st!="North" && tx==20000)
        {
            cout<<"NO";
            return(0);
        }
        if (st=="North") tx-=x; else
        if (st=="South") tx+=x;

        if (tx<0 || tx>20000)
        {
            cout<<"NO";
            return(0);
        }
    }

    if (tx!=0 || ty!=0) cout<<"NO"; else cout<<"YES";
}