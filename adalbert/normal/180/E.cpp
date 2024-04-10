#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int maxint=numeric_limits<int>::max();
const ll maxll=numeric_limits<ll>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-6;

///---program start---///

int n,m,k;
vi vh[arr];

main()
{
    fast;
    cin>>n>>m>>k;
    for (int i=0;i<n;i++)
    {
        int dop;
        cin>>dop;
        vh[dop].pb(i);
    }
    int ans=0;
    for (int vh_=1;vh_<=m;vh_++)
    {
        vi vec=vh[vh_];
        if (vec.empty()) continue;
        int l=0,r=0;
        while (r!=vec.size())
        {
            //cerr<<l<<" "<<r<<"\n";
            if (vec[r]-vec[l]-(r-l)<=k)
                ans=max(ans,r-l+1);
            r++;
            while(vec[r]-vec[l]-(r-l)>k)
                l++;
        }
        //cerr<<"!!!!!!\n";
    }
    cout<<ans;
}