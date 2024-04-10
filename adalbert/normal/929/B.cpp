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
const int arr=1e6;

vector<pair<int,int> > pos[5],vec;
string st[1000];

signed main()
{
    int n,k;
    cin>>n>>k;

    for (int i=1;i<=n;i++)
        cin>>st[i];

    for (int i=1;i<=n;i++)
        for (int j=0;j<st[i].size();j++)
            if (st[i][j]=='.')
            {
                int now=0;
                if (j-1>=0 && st[i][j-1]=='S')
                    now++;
                if (j+1<st[i].size() && st[i][j+1]=='S')
                    now++;
                pos[now].pb({i,j});
            }

    for (int i=0;i<=2;i++)
        for (auto j:pos[i])
        vec.pb(j);

    for (int i=0;i<k;i++)
        st[vec[i].fir][vec[i].sec]='x';

    int ans=0;

    for (int i=1;i<=n;i++)
        for (int j=0;j<st[i].size();j++)
            if (st[i][j]=='S')
            {
                if (j-1>=0 && (st[i][j-1]=='S' || st[i][j-1]=='P' || st[i][j-1]=='x'))
                    ans++;
                if (j+1<st[i].size() && (st[i][j+1]=='S' || st[i][j+1]=='P' || st[i][j+1]=='x'))
                    ans++;
            }

    cout<<ans<<'\n';
    for (int i=1;i<=n;i++)
        cout<<st[i]<<'\n';
}
/*
*/