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

#define arr (int)(3e5+10)

int a[arr];
int f[arr];
int ans[arr];

void upd(int pos,int val)
{
    for (int i=pos;i<arr;i|=i+1){
        f[i]=min(f[i],val);
    }
}

int n;

int get(int pos)
{
    int res=3*n+1;
    for (int i=pos;i>=0;i&=i+1,i--){
        res=min(res,f[i]);
    }
    return res;
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    cin>>n;
    map<int,int> vh;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        a[n+i]=a[i];
        a[2*n+i]=a[i];

        vh[a[i]];
        vh[(a[i]-1)/2];
    }
    int cnt_vh=0;
    for (auto& i:vh){
        i.sec=cnt_vh++;
    }
    for (int i=0;i<arr;i++){
        f[i]=3*n+1;
    }
    int best=3*n+1;
    for (int i=3*n;i>=1;i--){
        int right=get(vh[(a[i]-1)/2]);
        best=min(best,right);
        if (i<=n){
            ans[i]=(best==3*n+1?-1:best-i);
        }
        upd(vh[a[i]],i);
    }
    for (int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}