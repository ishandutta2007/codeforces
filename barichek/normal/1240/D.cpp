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
///#define int long long

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

const ll md1=1e9+9;

#define arr (int)(3e5+10)

ll rnd()
{
    ll res=0;
    for (int i=0;i<60;i++){
        if (rand()&1){
            res+=(1ll<<i);
        }
    }
    return res;
}

int a[arr];
ll ans;

int p[arr];
int p1[arr];

ll H[arr];
int sz=0;

int getH(ll val)
{
    return upper_bound(H,H+sz,val)-lower_bound(H,H+sz,val);
}

void solve(int l,int r)
{
//    cout<<"solve :: "<<l<<" "<<r<<"\n";
    if (l==r){
        return;
    }
    int m=(l+r)/2;

    vi cur(0);
    int h=0;
    int h1=0;

    sz=0;

    cur.clear();
    h=0;
    h1=0;
    for (int i=m;i>=l;i--){
        if (!cur.empty()&&cur.back()==a[i]){
            h=h-1ll*a[i]*p[len(cur)]%md;
            if (h<0){
                h+=md;
            }
            h1=h1-1ll*a[i]*p1[len(cur)]%md1;
            if (h1<0){
                h1+=md1;
            }
            cur.pop_back();
        }
        else{
            cur.pb(a[i]);
            h=h+1ll*a[i]*p[len(cur)]%md;
            if (h>=md){
                h-=md;
            }
            h1=h1+1ll*a[i]*p1[len(cur)]%md1;
            if (h1>=md1){
                h1-=md1;
            }
        }
        H[sz++]=h+1ll*h1*md;
    }
    sort(H,H+sz);

    cur.clear();
    h=0;
    h1=0;
    for (int i=m+1;i<=r;i++){
        if (!cur.empty()&&cur.back()==a[i]){
            h=h-1ll*a[i]*p[len(cur)]%md;
            if (h<0){
                h+=md;
            }
            h1=h1-1ll*a[i]*p1[len(cur)]%md1;
            if (h1<0){
                h1+=md1;
            }
            cur.pop_back();
        }
        else{
            cur.pb(a[i]);
            h=h+1ll*a[i]*p[len(cur)]%md;
            if (h>=md){
                h-=md;
            }
            h1=h1+1ll*a[i]*p1[len(cur)]%md1;
            if (h1>=md1){
                h1-=md1;
            }
        }
        ans+=getH(h+1ll*h1*md);
    }
    solve(l,m);
    solve(m+1,r);
}

void solve()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    ans=0;
    solve(1,n);
    cout<<ans<<"\n";
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    p[0]=1;
    p1[0]=1;

    for (int i=1;i<arr;i++){
        p[i]=1ll*p[i-1]*12324323%md;
        p1[i]=1ll*p1[i-1]*12324323%md1;
//        p[i]=rnd()%md;
//        p1[i]=rnd()%md1;
    }

    fast;

    int q;
    cin>>q;
    while (q--){
        solve();
    }
}