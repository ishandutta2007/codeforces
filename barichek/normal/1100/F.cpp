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

#define arr (int)(5e5+10)

inline void add(vi& b,int x)
{
    for (int t:b){
        if ((x^t)<x){
            x^=t;
        }
    }
    if (x==0){
        return;
    }
    for (int& t:b){
        if ((x^t)<t){
            t^=x;
        }
    }
    b.pb(x);
    sort(all(b),greater<int>());
}

bool is_comb(const vi& b,int x)
{
    for (int t:b){
        if ((x^t)<x){
            x^=t;
        }
    }
    return (x==0);
}

inline void merge(vi& b1,const vi& b2)
{
    for (auto i:b2){
        add(b1,i);
    }
}

bool is_comp_ignore_last_bits(const vi& b,int x,int bits)
{
    x>>=bits;
    for (int t:b){
        if ((x^(t>>bits))<x){
            x^=(t>>bits);
        }
    }
    return (x==0);
}

int get_ans(const vi& b)
{
    int x=0;
    for (int i=20;i>=0;i--){
        if (is_comp_ignore_last_bits(b,(x|(1ll<<i)),i)){
            x|=(1ll<<i);
        }
    }
    return x;
}

int a[arr];
int ans[arr];
int l[arr];
int r[arr];
vi basis[arr];

void solve(int L,int R,const vi& req)
{
    if (L==R){
        for (auto i:req){
            ans[i]=a[L];
        }
        return;
    }
    for (int i=L;i<=R;i++){
        if (!basis[i].empty()){
            basis[i].clear();
        }
    }

    int m=(L+R)/2;
    basis[m].clear();
    add(basis[m],a[m]);
    for (int i=m-1;i>=L;i--){
        basis[i]=basis[i+1];
        add(basis[i],a[i]);
    }
    basis[m+1].clear();
    add(basis[m+1],a[m+1]);
    for (int i=m+1;i<=R;i++){
        basis[i]=basis[i-1];
        add(basis[i],a[i]);
    }

    vi req1(0);
    vi req2(0);
    for (auto i:req){
        if (r[i]<=m){
            req1.pb(i);
        }
        elif (l[i]>m){
            req2.pb(i);
        }
        else{
            vi b1=basis[l[i]];
            vi b2=basis[r[i]];
            merge(b1,b2);
            ans[i]=get_ans(b1);
        }
    }
    solve(L,m,req1);
    req1.clear();
    solve(m+1,R,req2);
    req2.clear();
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
    int q;
    cin>>q;
    vi req(0);
    for (int i=1;i<=q;i++){
        cin>>l[i]>>r[i];
        req.pb(i);
    }
    solve(1,n,req);
    for (int i=1;i<=q;i++){
        cout<<ans[i]<<"\n";
    }
}