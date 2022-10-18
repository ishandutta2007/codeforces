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
#define int ll
int cnt[arr];

main()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for (auto i:s)
        cnt[i]++;
    vector<ll> use;
    for (char i='A';i<='Z';i++)
        if (cnt[i]>0)
            if (cnt[i]==1)
                use.pb(1);
            else
                use.pb(cnt[i]);
    sort(all(use));
    reverse(all(use));
    int ans=0;
    for (int i=0;i<(int)use.size()&&k>0;i++)
    {
        //cout<<use[i]<<" "<<k<<" "<<ans<<" !\n";
        if (k>=use[i])
            ans+=max(1ll*use[i]*use[i],1ll),
            k-=use[i];
        else
        {
            ans+=1ll*k*k;
            k=0;
        }
    }
    cout<<ans;
}