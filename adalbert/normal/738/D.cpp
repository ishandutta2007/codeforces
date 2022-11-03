#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);

///-----------------------------------------------------------------------///
int  main()
{
    int n,a,b,k;
    cin>>n>>a>>b>>k;
    vector <int > vec;
    string st;
    cin>>st;
    int k0=0;
    for (int i=0;i<st.size();i++)
    if (st[i]=='0')
    {
        k0++;
        if (k0==b)
        {
            k0=0;
            vec.pb(i);
        }
    }else
    {
        k0=0;
    }
    cout<<vec.size()-a+1<<'\n';
    for (int i=0;i<vec.size()-a+1;i++)
        cout<<vec[i]+1<<' ';

}