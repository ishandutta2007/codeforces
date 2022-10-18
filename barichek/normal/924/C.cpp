#pragma GCC optimize("O3")
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

int n;
int m[arr];
int a[arr];
int suf_a[arr];
int at_least_after[arr];
int live[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>m[i];
    }
    for (int i=1;i<=n;i++){
        a[i]=m[i]-i;
    }
    suf_a[n]=a[n];
    for (int i=n-1;i>=1;i--){
        suf_a[i]=max(suf_a[i+1],a[i]);
    }
    for (int i=1;i<=n;i++){
        at_least_after[i]=max(1ll,suf_a[i]+i+1);
//        cout<<"at_least_after["<<i<<"] :: "<<at_least_after[i]<<"\n";
    }
    for (int i=1;i<=n;i++){
        if (at_least_after[i]>live[i-1]){
            live[i]=live[i-1]+1;
        }
        else{
            live[i]=live[i-1];
        }
    }
    int ans=0;
    for (int i=1;i<=n;i++){
        ans+=live[i]-m[i]-1;
//        cout<<"live["<<i<<"] :: "<<live[i]<<"\n";
    }
    cout<<ans<<"\n";
}