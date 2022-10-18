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

int a[arr];
int c[arr];
bool use[arr];
int cnt[arr];
int lol[arr];
bool lol1[arr];

int ans=0;

bool cur_use[arr];

void dfs(int now)
{
    use[now]=1;
    cur_use[now]=1;
    if (use[a[now]]){
        if (cur_use[a[now]]){
            lol1[a[now]]=1;
        }
    }
    else{
        dfs(a[now]);
    }
    cur_use[now]=0;
}

int process(int now)
{
    int res=c[now];
    int kek=now;
    now=a[now];
    while (now!=kek){
        res=min(res,c[now]);
        now=a[now];
    }
    return res;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>c[i];
    }
    for (int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    for (int i=1;i<=n;i++){
        if (cnt[i]==0){
            dfs(i);
        }
    }
    for (int i=1;i<=n;i++){
        if (!use[i]){
            dfs(i);
        }
    }
    for (int i=1;i<=n;i++){
        if (lol1[i]){
            ans+=process(i);
        }
    }
    cout<<ans<<"\n";
}