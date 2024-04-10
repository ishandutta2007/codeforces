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

int n,m,k;
int a[arr];
int b[arr];

int next_zero[arr];
int prev_zero[arr];

vector<pii> keks;

int best_right[arr];

bool check(int x)
{
    for (int i=1;i<=n;i++){
        b[i]=(a[i]>=x); /// 1 or 0
    }
    for (int i=1;i<=n;i++){
        best_right[i]=inf;
    }
    for (auto i:keks){
        if (b[i.fir]==0&&b[i.sec]==0){
            best_right[i.fir]=min(best_right[i.fir],i.sec);
        }
    }
    for (int i=n-1;i>=1;i--){
        best_right[i]=min(best_right[i],best_right[i+1]);
    }
    
    for (int take_left=0;take_left<=k;take_left++){
        int take_right=k-take_left;
        if (best_right[take_left+1]<=n-take_right){
            /// i lose
        }
        else{
            /// i win
            return 1;
        }
    }
    return 0;
}

void solve()
{
    keks.clear();
    cin>>n>>m>>k;
    for (int l=1;l<=n;l++){
        for (int r=l;r<=n;r++){
            if (l-1+n-r==m-1){
                keks.pb(mp(l,r));
            }
        }
    }
    if (k>m-1){
        k=m-1;
    }
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=0,r=1e9;
    while (r-l>0){
        int m=(l+r+1)/2;
        if (check(m)){
            l=m;
        }
        else{
            r=m-1;
        }
    }
    cout<<l<<"\n";
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif
    
    int test;
    cin>>test;
    while (test--){
        solve();
    }
}