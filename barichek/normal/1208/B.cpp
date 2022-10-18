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

int cnt[ar];
int a[ar];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    map<int,int> vh;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        vh[a[i]];
    }
    if (vh.size()==n){
        cout<<0<<"\n";
        return 0;
    }
    int kek=0;
    for (auto& i:vh){
        i.sec=kek++;
    }
    for (int i=1;i<=n;i++){
        a[i]=vh[a[i]];
    }
    int ans=1e9;
    for (int i=1;i<=n;i++){
        for (int j=0;j<ar;j++){
            cnt[j]=0;
        }
        bool bad=0;
        for (int j=1;j<i;j++){
            cnt[a[j]]++;
            if (cnt[a[j]]>=2){
                bad=1;
                break;
            }
        }
        for (int j=n;j>=i;j--){
            if (!bad){
                ans=min(ans,j-i+1);
            }
            cnt[a[j]]++;
            if (cnt[a[j]]>=2){
                bad=1;
            }
        }
    }
    cout<<ans<<"\n";
}