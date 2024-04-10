#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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

#define arr (int)(3e5+10)

int a[arr];
int cnt[arr];

int pref[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=__builtin_popcountll(a[i]);
        pref[i]=pref[i-1]+a[i];
    }

    const int L=200;
    int ans=0;
    for (int i=1;i<=n;i++){
        if (i>L){
            cnt[pref[i-L-1]%2]++;
        }
        ans+=cnt[pref[i]%2];
    }
    for (int i=1;i<=n;i++){
        int cur_max=a[i];
        for (int j=i;j<=n&&j-i+1<=L;j++){
            cur_max=max(cur_max,a[j]);
            if ((pref[j]-pref[i-1])%2==0&&2*cur_max<=pref[j]-pref[i-1]){
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
}