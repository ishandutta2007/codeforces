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

int a[arr];
int ans[arr];

int t[4*arr];

void upd(int v,int l,int r,int pos,int val)
{
    if (l==r){
        t[v]=val;
        return;
    }
    int m=(l+r)/2;
    if (pos<=m){
        upd(v*2,l,m,pos,val);
    }
    else{
        upd(v*2+1,m+1,r,pos,val);
    }
    t[v]=t[v*2]+t[v*2+1];
}

int get(int v,int l,int r,int k)
{
    if (l==r){
        return l;
    }
    int m=(l+r)/2;
    if (t[v*2]>=k){
        return get(v*2,l,m,k);
    }
    else{
        return get(v*2+1,m+1,r,k-t[v*2]);
    }
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }

    for (int i=1;i<=n;i++){
        upd(1,1,n,i,i);
    }

    for (int i=n;i>=1;i--){
        ans[i]=get(1,1,n,a[i]+1);
        upd(1,1,n,ans[i],0);
    }

    for (int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}