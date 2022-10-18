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

int f(int n)
{
    int res=0;
    for (int i=1;i<=n/2;i++){
        res+=n-2*i;
    }
    return res;
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif
    
    int n,m;
    cin>>n>>m;
    
    int fn=f(n);
    if (fn<m){
        cout<<-1<<"\n";
        return 0;
    }
    int k=0;
    while (k+1<=n&&f(k+1)<=m){
        k++;
    }
    // cout<<k<<" "<<f(k)<<"\n";
    vi ans(0);
    for (int i=1;i<=k;i++){
        ans.pb(i);
    }
    int rest=m-f(k);
    // cout<<"rest :: "<<rest<<"\n";
    if (rest!=0){
        int pos=k+1;
        while ((2*k-pos+1)/2>rest){
            pos++;
        }
        assert((2*k-pos+1)/2==rest);
        ans.pb(pos);
    }
    int PPP=6000+13000*100;
    while (len(ans)<n){
        ans.pb(PPP);
        PPP+=13000;
    }
    for (auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}