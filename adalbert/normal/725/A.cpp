#include <bits/stdc++.h>
using namespace std;
///----------------------defines-----------------------///
#define push_back pb
#define make_pair mp
typedef long long ll;
typedef long double ld;
///--------------------end_of _define------------------///

int main()
{
    ll n;
    ll ans=0;
    cin>>n;
    string st;
    cin>>st;
    bool check=1;
    for (int i=0;i<st.size();i++)
        if (st[i]=='<' && check) ans++; else check=0;
    check=1;
    for (int i=st.size()-1;i>=0;i--)

        if (st[i]=='>' && check) ans++; else check=0;
    cout<<ans;
}