#include <bits/stdc++.h>
using namespace std;
#define sec second
#define fir first
#define pb push_back
#define mp_ make_pair
typedef long double ld;
typedef int ll;
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
bool check=0;
///------------------------------------------------------------///
ll a;
///------------------------------------------------------------///
void rec(ll b, vector <ll> vec)
{
    vec.pb(b);
    if (a==b)
    {
        cout<<"YES"<<'\n';
        check=1;
        reverse(vec.begin(),vec.end());
        cout<<vec.size();
        cout<<'\n';
        for (int i=0;i<vec.size();i++)
            cout<<vec[i]<<' ';
    }
    if (b<a) return;
    if (!check)
    {
        if (b%10==1) rec(b/10,vec);
        if (b%2==0)
        rec(b/2,vec);
    }

}
///------------------------------------------------------------///
int main()
{
    ll b;
    fast;
    cin>>a>>b;
    vector <ll> vec;
    rec(b,vec);
    if (!check)
    cout<<"NO";
}