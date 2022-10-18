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

int a[arr];
int b[arr];
bool live[arr];
int cnt[arr];

bool better(int a,int b)
{
    return (a&(((1ll<<60)-1)^b))>0;
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        live[i]=1;
    }
    for (int i=1;i<=n;i++){
        cin>>b[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (i!=j){
                if (better(a[i],a[j])){
                    cnt[i]++;
                }
            }
        }
    }
    int cur_live=n;
    while (1){
        int pos=-1;
        for (int i=1;i<=n;i++){
            if (live[i]&&cnt[i]==cur_live-1){
                pos=i;
            }
        }
        if (pos==-1){
            break;
        }
        live[pos]=0;
        for (int j=1;j<=n;j++){
            if (live[j]&&better(a[j],a[pos])){
                cnt[j]--;
            }
        }
        cur_live--;
    }
    int ans=0;
    for (int i=1;i<=n;i++){
        if (live[i]){
            ans+=b[i];
        }
    }
    if (cur_live==1){
        ans=0;
    }
    cout<<ans<<"\n";
}