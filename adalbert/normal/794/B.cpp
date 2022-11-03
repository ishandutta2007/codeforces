#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#pragma GCC optimize ("O3")
#define time pdojegoritg
#define int ll
typedef long long ll;
typedef long double ld;
const int arr=500000;
map<int,int> mp;
ld h;
ld get(ld s)
{
    ld l=0, r=h;
    for (int i=1;i<=100;i++)
    {
        ld d=(l+r)/2.0;
        ld s1=d*(d/h)/2.0;
        //cout<<d<<' '<<s1<<' '<<s<<'\n';
        if (s1<s) l=d; else r=d;
    }
    return(l);
}
signed main()
{
    int n;
    ld now=1.0;
    cin>>n>>h;
    vector<ld> vec;
    ld s=(h/2.0)/ld(n);
    for (int i=1;i<n;i++)
    {
        vec.pb(get(ld(i)*s));
    }
    sort(vec.begin(),vec.end());
    //reverse(vec.begin(),vec.end());
    for (int i=0;i<vec.size();i++)
        cout<<fixed<<setprecision(9)<<vec[i]<<' ';

}