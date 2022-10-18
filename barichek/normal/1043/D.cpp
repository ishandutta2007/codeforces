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

map<pii,int> cnt_pairs;
int a[11][100000+10];

int lcp[arr];
bool ok[arr];
int before[arr];
int F[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n,m;
    cin>>n>>m;
    for (int j=1;j<=m;j++){
        for (int i=1;i<=n;i++){
            cin>>a[j][i];
            if (j!=1){
                if (i>1){
                    if (before[a[j][i]]!=a[j][i-1]){
                        ok[a[j][i]]=0;
                    }
                }
                else{
                    F[a[j][i]]++;
                }
            }
            else{
                ok[a[j][i]]=1;
                if (i>1){
                    before[a[j][i]]=a[j][i-1];
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        if (i==1){
            lcp[i]=1;
        }
        else{
            lcp[i]=(ok[a[1][i]]&&F[a[1][i]]==0?lcp[i-1]:0)+1;
        }
    }
    ll ans=0;
    for (int i=1;i<=n;i++){
        ans+=lcp[i];
    }
    cout<<ans<<"\n";
}