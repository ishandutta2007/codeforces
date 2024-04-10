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
    vector <int> vec;
    int n;
    cin>>n;
    int tep=1;
    while (n>=tep)
    {
        vec.pb(tep);
        n-=tep;
        tep++;
    }
    vec[vec.size()-1]+=n;
    cout<<vec.size()<<'\n';
    for (int i=0;i<vec.size();i++)
        cout<<vec[i]<<' ';
}