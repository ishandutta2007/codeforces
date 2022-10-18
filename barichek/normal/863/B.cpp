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

int get(vi a)
{
    sort(all(a));
    int res=0;
    for (int i=0;i<len(a);i+=2){
        res+=abs(a[i]-a[i+1]);
    }
    return res;
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

    int n;
    cin>>n;
    n*=2;
    vi a(n);
    for (auto& i:a){
        cin>>i;
    }
    int ans=1e15;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            vi cur(0);
            for (int k=0;k<n;k++){
                if (k!=i&&k!=j){
                    cur.pb(a[k]);
                }
            }
            ans=min(ans,get(cur));
        }
    }
    cout<<ans<<"\n";
}