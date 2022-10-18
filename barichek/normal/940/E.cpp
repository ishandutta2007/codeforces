#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
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

int dp[arr];
int a[arr];
int pref[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,c;
    cin>>n>>c;
    if (c==1){
        return cout<<0<<"\n", 0;
    }
    for (int i=1;i<=n;i++){
        cin>>a[i];
        pref[i]=pref[i-1]+a[i];
    }
    multiset<int> m;
    m.clear();
    int sum=0;
    for (int i=1;i<=n;i++){
        dp[i]=dp[i-1]+a[i];
        m.insert(a[i]);
        if (len(m)>c){
            m.erase(m.find(a[i-c]));
        }
        if (i>=c){
            dp[i]=min(dp[i],dp[i-c]+pref[i]-pref[i-c]-*m.begin());
        }
    }
    cout<<dp[n]<<"\n";
}