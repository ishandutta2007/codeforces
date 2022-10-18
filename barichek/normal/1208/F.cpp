//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
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

#define arr (int)(1e6+10)

int a[arr];

const int K=22;
int cnt[(1ll<<K)];
int first_bit[(1ll<<K)];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    for (int i=1;i<(1ll<<K);i++){
        first_bit[i]=(i&1?0:1+first_bit[i>>1]);
    }

    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }

    function<void(int,int)> upd=[&](int a,int b)
    {
//        cout<<bitset<5>(a)<<" "<<bitset<5>(b)<<"\n";
//        cout<<"a|b :: "<<bitset<5>(a|b)<<"\n";
        if (cnt[a|b]>=2){
            return;
        }
        if (a==0){
            cnt[a|b]++;
            return;
        }
        int bit=first_bit[a];
        upd(a^(1ll<<bit),b);
        upd(a^(1ll<<bit),b|(1ll<<bit));
    };

    int ans=0;
    for (int i=n;i>=1;i--){
//        cout<<i<<" :: "<<a[i]<<"\n";
        if (cnt[0]>=2){
            int cur=0;
            for (int j=K-1;j>=0;j--){
                if (!(a[i]&(1ll<<j))){
                    if (cnt[cur|(1ll<<j)]>=2){
                        cur|=(1ll<<j);
                    }
                }
            }
            ans=max(ans,a[i]|cur);
        }
        upd(a[i],0);
    }
    cout<<ans<<"\n";
}