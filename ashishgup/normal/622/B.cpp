#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
    IOS;
    int hh, mm;
    char ch;
    cin>>hh>>ch>>mm;
    int k;
    cin>>k;
    while(k--)
    {
        mm++;
        if(mm==60)
        {
            mm=0;
            hh++;
            if(hh==24)
            {
                hh=0;
            }
        }
    }
    cout.fill('0');
    cout.width(2);
    cout<<hh<<":";
    cout.fill('0');
    cout.width(2);
    cout<<mm;
    return 0;
}