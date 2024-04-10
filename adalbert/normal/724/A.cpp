#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
///-----------------------------------------------------------------------///
string st1,st2;
///-----------------------------------------------------------------------///
int main()
{
    ll a[100]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin>>st1>>st2;
    ll k1,k2;
    if (st1=="monday") k1=1; else
        if (st1=="tuesday") k1=2; else
        if (st1=="wednesday") k1=3; else
        if (st1=="thursday") k1=4; else
        if (st1=="friday") k1=5; else
        if (st1=="saturday") k1=6; else
        if (st1=="sunday") k1=7;
        if (st2=="monday") k2=1; else
        if (st2=="tuesday") k2=2; else
        if (st2=="wednesday") k2=3; else
        if (st2=="thursday") k2=4; else
        if (st2=="friday") k2=5; else
        if (st2=="saturday") k2=6; else
        if (st2=="sunday") k2=7;
    k1--;
    k2--;
    for (int f=0;f<=6;f++)
    {
        ll i=f;
        for (int j=0;j<=11;j++)
        {
            ll tep=(f+a[j])%7;
            if (tep==k2 && f==k1)
            {
                cout<<"YES";
                return(0);
            }
            f=tep;
        }
    }
    cout<<"NO";
}