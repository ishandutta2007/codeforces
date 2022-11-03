#include<bits/stdc++.h>
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
#define time ddfkjgofidhj
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int md=1e9+7;
const int arr=2e5;

bool check(string st)
{
    for (int i=0;i<st.size();i++)
        if (st[i]!=st[st.size()-i-1])
        return(1);
    return(0);
}

int a[arr],b[arr];

signed main()
{

    int n;
    cin>>n;

    map<int,int> mp;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        int y;
        cin>>y;
        mp[a[i]]=y;
    }
    int m;
    cin>>m;
    for (int i=1;i<=m;i++)
    {

        cin>>b[i];

        int y;
        cin>>y;
        mp[b[i]]=max(mp[b[i]],y);
    }

    int ans=0;
    for (auto i:mp)
        ans+=i.sec;

    cout<<ans;

}