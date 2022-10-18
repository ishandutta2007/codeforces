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

void build(vi a,set<int>& s,int m)
{
    for (int mask=0;mask<(1ll<<len(a));mask++){
        int cur=0;
        for (int i=0;i<len(a);i++){
            if (mask&(1ll<<i)){
                cur=(cur+a[i])%m;
            }
        }
        s.insert(cur);
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,m;
    cin>>n>>m;
    vi a(n);
    for (auto& i:a){
        cin>>i;
    }
    int mid=n/2;
    vi left(0); ///[0;mid)
    for (int i=0;i<mid;i++){
        left.pb(a[i]);
    }
    vi right(0); ///[mid;n)
    for (int i=mid;i<n;i++){
        right.pb(a[i]);
    }
    set<int> L;
    build(left,L,m);
    set<int> R;
    build(right,R,m);
    int ans=0;
    for (auto i:L){
        auto it=R.lower_bound(m-i);
        if (it!=R.end()){
            ans=max(ans,(i+(*it))%m);
        }
        if (it!=R.begin()){
            it--;
            ans=max(ans,(i+(*it))%m);
        }
    }
    cout<<ans<<"\n";
}