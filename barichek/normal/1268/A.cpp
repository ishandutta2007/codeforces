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
const ll inf=1e18+10;

///---program start---///

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    /// check if ok
    bool ok=0;
    bool is_eq=1;
    for (int i=k;i<len(s);i++){
        ok|=(is_eq&&s[i%k]>s[i]);
        is_eq&=(s[i]==s[i%k]);
    }
    ok|=is_eq;
    if (ok){
        cout<<n<<"\n";
        for (int i=0;i<n;i++){
            cout<<s[i%k];
        }
        cout<<"\n";
        return 0;
    }
    bool done=0;
    for (int i=k-1;i>=0;i--){
        if (s[i]=='9'){
            s[i]='0';
        }
        else{
            s[i]++;
            done=1;
            break;
        }
    }
    int ans=n;
    if (!done){
        s="1"+s;
        ans=n+1;
    }
    cout<<ans<<"\n";
    for (int i=0;i<n;i++){
        cout<<s[i%k];
    }
    cout<<"\n";
}