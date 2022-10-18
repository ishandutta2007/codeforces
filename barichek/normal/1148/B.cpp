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

int a[arr];
int b[arr];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n,m,ta,tb,k;
    cin>>n>>m>>ta>>tb>>k;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<m;i++){
        cin>>b[i];
    }
    int ans=-1e18;
    bool inf=0;
    for (int l=0;l<=min(k,n);l++){
        int lm=min(m,k-l);
        if (l==n||lm==m){
            inf=1;
        }
        else{
            if (a[l]+ta<=b[m-lm-1]){
                int id=lower_bound(b,b+m,a[l]+ta)-b;
                id+=lm;
                ans=max(ans,b[id]+tb);
            }
            else{
                inf=1;
            }
        }
    }
    if (inf){
        ans=-1;
    }
    cout<<ans<<"\n";
}