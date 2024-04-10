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
int a[300000],use[300000];
///-----------------------------------------------------------------------///
int  main()
{
    fast;
    int n,s;
    cin>>n>>s;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int k=0;
    ll ans=1e15;
    if (a[s]!=0)
    {
        a[s]=0;
        k=1;
    }
    int cntl=0;
    vector <int > vec;
    for (int i=1;i<=n;i++)
        if (a[i]==0 && i!=s ) {cntl++; }else
        if (i!=s)
        vec.pb(a[i]);
    sort(vec.begin(),vec.end());
    int r=0;
    if (vec.empty())
    {
        cout<<k+cntl;
        return(0);
    }
    for (int i=0;i<vec.size();i++)
    {
        if (use[vec[i]]==0)
        {
            r++;
            use[vec[i]]=1;
        }
        int tr=max(0,vec[i]-r-cntl);
        //cout<<tr<<'\n';
        int kilk=max(tr,(int)(vec.size())-i-1)+cntl;
        ans=min(ans,(ll)kilk);
    }
    cout<<ans+k;
}