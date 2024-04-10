#include <bits/stdc++.h>
#define pb push_back
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ull
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

signed main()
{
    string st;
    cin>>st;

    string ans="";

    int cnt=0;
    for (auto i:st)
        if (i=='1')
        cnt++; else
        ans+=i;

    for (auto i:ans)
    {
        if (i=='2')
        {
            while (cnt!=0)
            {
                cout<<1;
                cnt--;
            }
        }
        cout<<i;
    }
    while (cnt!=0)
    {
        cout<<1;
        cnt--;
    }
}
/*
*/