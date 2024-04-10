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

void maximize(int& a,int b)
{
    if (a<b){
        a=b;
    }
}

int n,s,m,k;
int a[arr];
bool use[arr];
vi vh[arr];

int dp[1501+10][1501+10];
int cnt[1501+10];

int best_from[arr];

bool check(int x)
{
    memset(dp,0,sizeof(dp));
    memset(cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++){
        cnt[i]=cnt[i-1]+(a[i]<=x);
    }
    for (int i=0;i+1<=n;i++){
        for (int j=0;j<=m;j++){
            if (best_from[i+1]){
                maximize(dp[best_from[i+1]][j+1],dp[i][j]+cnt[best_from[i+1]]-cnt[i]);
            }
            maximize(dp[i+1][j],dp[i][j]);
        }
    }
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            if (dp[i][j]>=k){
                return 1;
            }
        }
    }
    return 0;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    cin>>n>>s>>m>>k;
    set<int> kek;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        kek.insert(a[i]);
    }
    int cnt_closed=0;
    for (int i=1;i<=s;i++){
        int l,r;
        cin>>l>>r;
        for (int j=l;j<=r;j++){
            if (!use[j]){
                cnt_closed++;
                use[j]=1;
            }
            best_from[j]=max(best_from[j],r);
        }
        vh[l].pb(r);
    }

    if (!check(1e9+10)){
        cout<<-1<<"\n";
        return 0;
    }

    vi lol(all(kek));
    int l=0,r=len(lol)-1;
    while (r-l>0){
        int m=(l+r)/2;
        if (check(lol[m])){
            r=m;
        }
        else{
            l=m+1;
        }
    }
    cout<<lol[l]<<"\n";
}