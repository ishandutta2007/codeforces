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
int pr[arr];
int ans;
int pos[arr];
int n;

void solve(int l,int r)
{
    if (l==r){
        return;
    }
    int m=(l+r)/2;
    /// [l;m] [m+1;r]
    solve(l,m);
    solve(m+1,r);

    pr[m]=a[m];
    for (int i=m-1;i>=l;i--){
        pr[i]=max(pr[i+1],a[i]);
    }

    pr[m+1]=a[m+1];
    for (int i=m+2;i<=r;i++){
        pr[i]=max(pr[i-1],a[i]);
    }

    for (int i=l;i<=m;i++){
        int a_r=pr[i]-a[i];
        if (a_r>=1&&a_r<=n&&pos[a_r]>=m+1&&pos[a_r]<=r&&pr[pos[a_r]]<pr[i]){
            ans++;
        }
    }
    for (int i=m+1;i<=r;i++){
        int a_l=pr[i]-a[i];
        if (a_l>=1&&a_l<=n&&pos[a_l]>=l&&pos[a_l]<=m&&pr[pos[a_l]]<pr[i]){
            ans++;
        }
    }
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=i;
    }
    solve(1,n);
    cout<<ans<<"\n";
}