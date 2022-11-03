#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll  long long
#define ld  long double
///-------------------///


ll a,ans;
vector <ll > vec;

///-------------------///





///---program start---///
int main()
{
    ll n,b,d;
    cin>>n>>b>>d;
    for (int i=1;i<=n;i++)
    {
        cin>>a;
        if (a<=b ) vec.push_back(a);
    }

    ll tep=0;
    for (int i=0;i<vec.size();i++)
    {
        tep+=vec[i];
        if (tep>d)
        {
            ans++;
            tep=0;
        }
    }
    if (tep>d) ans++;
    cout<<ans;
}