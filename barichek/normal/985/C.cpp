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

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n,k,l;
    cin>>n>>k>>l;
    vi a(n*k);
    for (auto& i:a){
        cin>>i;
    }
    sort(all(a));
    int p=0;
    for (int i=0;i<len(a);i++){
        if (a[i]-a[0]<=l){
            p=i;
        }
    }
    if (p+1<n){
        cout<<0<<"\n";
        return 0;
    }
    int ans=0;
    int cur=0;
    int left=n;
    while (left>0){
        ans+=a[cur];
        cur++;
        left--;
        int lol=k-1;
        while (lol>0&&p-(cur+1)+1>=left){
            cur++;
            lol--;
        }
    }
    cout<<ans<<"\n";
}