#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define time ddfkjgofidhj
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=5e5+100;
const int md=1e9+7;
const int base=1039;

int a[arr];

signed main()
{
    int n,k;
    cin>>n>>k;

    map<int,int> mp;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }

    vector<pair<int,int> > vec;

    for (auto i:mp)
        vec.pb(i);

    reverse(vec.begin(),vec.end());
    int ans=vec[0].sec;

    for (int i=1;i<vec.size();i++)
        if (vec[i].fir+k<vec[i-1].fir)
        ans+=vec[i].sec;

    cout<<ans;
}
/*
*/