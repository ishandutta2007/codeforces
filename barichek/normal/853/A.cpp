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

#define arr (int)(1e6+10)

pii a[arr];
int answer[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    fast;
    int n,k;
    cin>>n>>k;
    set<int> open;
    for (int i=k+1;i<=n+k+1;i++){
        open.insert(i);
    }
    for (int i=1;i<=n;i++){
        cin>>a[i].fir;
        a[i].sec=i;
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    int ans=0;
    for (int i=1;i<=n;i++){
        auto it=open.lower_bound(a[i].sec);
        ans+=(*it-a[i].sec)*a[i].fir;
        answer[a[i].sec]=*it;
        open.erase(it);
    }
    cout<<ans<<"\n";
    for (int i=1;i<=n;i++){
        cout<<answer[i]<<" ";
    }
    cout<<"\n";
}