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

int a[ar][ar];

vi x[arr];
vi y[arr];

int count_smaller(const vi& v,int x)
{
    return lower_bound(all(v),x)-v.begin();
}

int count_bigger(const vi& v,int x)
{
    return v.end()-upper_bound(all(v),x);
}

void doo(vi& v)
{
    vi res(0);
    for (int i=0;i<len(v);i++){
        if (i==0||v[i]!=v[i-1]){
            res.pb(v[i]);
        }
    }
    v=res;
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n,m;
    cin>>n>>m;

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>a[i][j];
            x[i].pb(a[i][j]);
            y[j].pb(a[i][j]);
        }
    }

    for (int i=0;i<n;i++){
        sort(all(x[i]));
        doo(x[i]);
    }
    for (int j=0;j<m;j++){
        sort(all(y[j]));
        doo(y[j]);
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            int val_me=
            max(count_smaller(x[i],a[i][j]),count_smaller(y[j],a[i][j]))+1+
            max(count_bigger(x[i],a[i][j]),count_bigger(y[j],a[i][j]));

//            cout<<i<<" "<<j<<" :: "<<count_bigger(x[i],a[i][j])<<" "<<count_bigger(y[j],a[i][j])<<"\n";

            cout<<val_me<<" ";
        }
        cout<<"\n";
    }
}