#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <memory.h>
#include <string.h>
#include <complex>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int ans=0;
vector<pair<int,int> > vec;

void solve(int l, int r)
{
    vector<int> vec1;
    vec1.pb(vec[l].fir);
    vector<int> vec2;
    vec2.pb(vec[l].fir);

    for (int i=l+1;i<r;i++)
        if (vec[i].sec==1)
        vec1.pb(vec[i].fir); else
        vec2.pb(vec[i].fir);

    vec1.pb(vec[r].fir);
    vec2.pb(vec[r].fir);

    int ln=vec[r].fir-vec[l].fir;

    if (vec1.size()==2 && vec2.size()==2)
    {
        ans+=ln;
        return;
    }

    int mx1=0,mx2=0;

    for (int i=1;i<vec1.size();i++)
        mx1=max(mx1,vec1[i]-vec1[i-1]);
    for (int i=1;i<vec2.size();i++)
        mx2=max(mx2,vec2[i]-vec2[i-1]);

    ans+=min(2*ln,3*ln-mx1-mx2);
}

signed main()
{
    int n;
    cin>>n;

    for (int i=1;i<=n;i++)
    {
        int x;
        char c;
        cin>>x>>c;
        if (c=='B')
            vec.pb({x,1}); else
        if (c=='R')
            vec.pb({x,2}); else
            vec.pb({x,3});
    }

    sort(vec.begin(),vec.end());

    int first=-1,last=-1;

    for (int i=0;i<vec.size();i++)
    {
        if (vec[i].sec==3)
        {
            if (first==-1)
                first=i;
            last=i;
        }
    }

    if (last==-1)
    {
        int last1=-1e18,last2=-1e18;
        for (int i=0;i<vec.size();i++)
        {
            if (vec[i].sec==1)
            {
                if (last1!=-1e18)
                    ans+=vec[i].fir-last1;
                last1=vec[i].fir;
            } else
            {
                if (last2!=-1e18)
                    ans+=vec[i].fir-last2;
                last2=vec[i].fir;
            }
        }

        cout<<ans;
        return(0);
    }

    int last1=-1e18,last2=-1e18;

    for (int i=0;i<=first;i++)
    {
        if (vec[i].sec==1 || vec[i].sec==3)
        {
            if (last1!=-1e18)
                ans+=vec[i].fir-last1;
            last1=vec[i].fir;
        }
        if (vec[i].sec==2 || vec[i].sec==3)
        {
            if (last2!=-1e18)
                ans+=vec[i].fir-last2;
            last2=vec[i].fir;
        }
    }

    last1=1e18,last2=1e18;

    for (int i=vec.size()-1;i>=last;i--)
    {
        if (vec[i].sec==1 || vec[i].sec==3)
        {
            if (last1!=1e18)
                ans+=-(vec[i].fir-last1);
            last1=vec[i].fir;
        }
        if (vec[i].sec==2 || vec[i].sec==3)
        {
            if (last2!=1e18)
                ans+=-(vec[i].fir-last2);
            last2=vec[i].fir;
        }
    }

    for (int i=first+1;i<=last;i++)
    {
        if (vec[i].sec==3)
        {
            solve(first,i);
            first=i;
        }
    }

    cout<<ans;
}
/*
15
-9518 R
-6858 P
-6726 B
-6486 R
-4496 P
-4191 P
-772 B
-258 R
-194 P
1035 R
2297 P
4816 B
5779 R
9342 B
9713 B

25088
*/