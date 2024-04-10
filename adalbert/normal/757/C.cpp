#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define int ll
#define y1 humiuyn
#define fir first
#define sec second
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
int fact[1000005];
vector <pair <int,int> > vec[1000005];
const int md=1e9+7;
///-----------------------------------------------------------------------///
signed main()
{
    int n,m;
    cin>>n>>m;
    fact[0]=1;
    for (int i=1;i<=1e6;i++)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=md;
    }
    for (int i=1;i<=n;i++)
    {
        int cnt;
        cin>>cnt;
        map <int , int > coun;
        for (int j=1;j<=cnt;j++)
        {
            int a;
            cin>>a;
            coun[a]++;
        }
        for (auto j:coun)
        {
            vec[j.fir].pb({i,j.sec});
        }
    }
    map <vector <pair< int,int> >, int> mp;
    for (int i=1;i<=m;i++)
    {
        //cout<<vec[m].size()<<'\n';
        mp[vec[i]]++;
    }

    int ans=1;
    for (auto i:mp)
    {
        //cout<<i.sec<<'\n';
        ans*=fact[i.sec];
        ans%=md;
    }
    cout<<ans;
}