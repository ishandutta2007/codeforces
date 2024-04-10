#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgjs
#define right rtyjtokh
#define x erg
#define y eth
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;

int ask(int x, int y)
{
    cout<<0<<' '<<x<<' '<<y<<'\n';
    fflush(stdout);
    int ans;
    cin>>ans;
    return(ans);
}

set<int> points;

void solve(int l, int r)
{
    if (r-l<=1)
        return;
    int d=(l+r)/2;
    int pl=ask(d,d);

    if (d-pl<=l && d+pl>=r)
        return;

    if (d-pl<=l)
    {
        if (ask(d+pl,d+pl)==0)
        {
            points.insert(d+pl);
            solve(l,d+pl);
            solve(d+pl,r);
        } else
        return;
    } else
    if (d+pl>=r)
    {
        if (ask(d-pl,d-pl)==0)
        {
            points.insert(d-pl);
            solve(l,d-pl);
            solve(d-pl,r);
        } else
        return;
    } else
    {
        if (ask(d+pl,d+pl)==0)
        {
            points.insert(d+pl);
            solve(l,d+pl);
            solve(d+pl,r);
        } else
        {
            points.insert(d-pl);
            solve(l,d-pl);
            solve(d-pl,r);
        }
    }

}

signed main()
{
    srand(time(0));
    int l=-1e8+ask(-1e8,-1e8);
    int r=1e8-ask(1e8,1e8);

    points.insert(l);
    points.insert(r);

    int z=rand()%int(1e8);

    while (points.count(z))
    {
        z=rand()%int(1e8);
    }

    solve(l,r);


    vector<int> vec1,vec2;
    for (auto i:points)
    {
        if (ask(i,z)==0)
        {
            vec1.pb(i);
        }

        if (ask(z,i)==0)
        {
            vec2.pb(i);
        }
    }

    cout<<1<<' '<<vec1.size()<<' '<<vec2.size()<<'\n';

    for (auto i:vec1)
        cout<<i<<' ';
    cout<<'\n';
    for (auto i:vec2)
        cout<<i<<' ';
    fflush(stdout);
}
/*
*/