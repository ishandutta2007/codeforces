#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define files_ds(name) name!=""?freopen(name".dat","r",stdin),freopen(name".sol","w",stdout):0
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

#define arr (int)(4e5+10)

int pw2[arr];

void inc(int &a,int b)
{
    a+=b;
    a%=md;
    a+=md;
    a%=md;
}

void dec(int &a,int b)
{
    a-=b;
    a%=md;
    a+=md;
    a%=md;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    pw2[0]=1;
    for (int i=1;i<arr;i++){
        pw2[i]=pw2[i-1]*2%md;
    }

    fast;
    int n;
    cin>>n;
    vi a(n);
    for (auto& i:a){
        cin>>i;
    }
    sort(all(a));
    int ans=0;
    for (int i=0;i<n;i++){
        inc(ans,pw2[i]*a[i]);
        dec(ans,pw2[n-i-1]*a[i]);
    }
    cout<<ans<<"\n";
}