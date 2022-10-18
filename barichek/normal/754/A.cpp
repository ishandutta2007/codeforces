#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) (name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0)
#define files_ds(name) (name!=""?freopen(name".dat","r",stdin),freopen(name".sol","w",stdout):0)
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
    #else
        files("");
    #endif

    int n;
    cin>>n;
    vi a;
    a.clear();
    a.resize(n);
    for (auto &i:a)
        cin>>i;
    vi dp(n,-1);
    vi pref;
    pref.clear();
    for (auto i:a)
        pref.pb((pref.empty()?0:pref.back())+i);
    for (int i=0;i<n;i++)
        for (int j=0;j<=i;j++)
            if (j==0||dp[j-1]!=-1)
                if (pref[i]-(j==0?0:pref[j-1])!=0)
                    if (dp[i]==-1)
                        dp[i]=j;
    if (dp.back()==-1) return cout<<"NO", 0;
    cout<<"YES\n";
    vector<pii> ans;
    ans.clear();
    for (int cur=n-1;cur!=-1;cur=dp[cur]-1)
        ans.pb(mp(dp[cur]+1,cur+1));
    reverse(all(ans));
    cout<<ans.size()<<"\n";
    for (auto i:ans)
        cout<<i.fir<<" "<<i.sec<<"\n";
}