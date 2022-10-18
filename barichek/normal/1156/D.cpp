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

int dp0[arr];
int dp1[arr];
int dp01[arr];
int dp10[arr];
int ans;
vector<pii> reb[arr];

void dfs(int now,int pred)
{
    for (auto wh:reb[now]){
        if (wh.fir!=pred){
            dfs(wh.fir,now);
        }
    }
    int sum;
    /// 0+1
    sum=0;
    for (auto wh:reb[now]){
        if (wh.fir==pred){
            continue;
        }

        if (wh.sec==0){
            sum+=dp0[wh.fir]+1;
        }
        else{
            ans+=sum*(dp1[wh.fir]+1);
        }
    }
//    cout<<"ans1 :: "<<ans<<"\n";
    /// 0+0
    sum=0;
    for (auto wh:reb[now]){
        if (wh.fir==pred){
            continue;
        }

        if (wh.sec==0){
            ans+=2*sum*(dp0[wh.fir]+1);
            sum+=dp0[wh.fir]+1;
        }
    }
//    cout<<"ans2 :: "<<ans<<"\n";
    /// 0+01
    sum=0;
    for (auto wh:reb[now]){
        if (wh.fir==pred){
            continue;
        }

        if (wh.sec==0){
            ans+=sum*(dp01[wh.fir]+dp1[wh.fir]);
            sum+=dp0[wh.fir]+1;
        }
    }
//    cout<<"ans3 :: "<<ans<<"\n";

    /// 1+0
    sum=0;
    for (auto wh:reb[now]){
        if (wh.fir==pred){
            continue;
        }

        if (wh.sec==1){
            sum+=dp1[wh.fir]+1;
        }
        else{
            ans+=sum*(dp0[wh.fir]+1);
        }
    }
//    cout<<"ans4 :: "<<ans<<"\n";
    /// 1+1
    sum=0;
    for (auto wh:reb[now]){
        if (wh.fir==pred){
            continue;
        }

        if (wh.sec==1){
            ans+=2*sum*(dp1[wh.fir]+1);
            sum+=dp1[wh.fir]+1;
        }
    }
//    cout<<"ans5 :: "<<ans<<"\n";
    /// 1+10
    sum=0;
    for (auto wh:reb[now]){
        if (wh.fir==pred){
            continue;
        }

        if (wh.sec==1){
            ans+=sum*(dp0[wh.fir]+dp10[wh.fir]);
            sum+=dp1[wh.fir]+1;
        }
    }
//    cout<<"ans6 :: "<<ans<<"\n";



    /// 01+0
    sum=0;
    for (auto wh:reb[now]){
        if (wh.fir==pred){
            continue;
        }

        if (wh.sec==0){
            ans+=sum*(dp0[wh.fir]+1);
            sum+=dp01[wh.fir]+dp1[wh.fir];
        }
    }
//    cout<<"ans7 :: "<<ans<<"\n";

    /// 10+1
    sum=0;
    for (auto wh:reb[now]){
        if (wh.fir==pred){
            continue;
        }

        if (wh.sec==1){
            ans+=sum*(dp1[wh.fir]+1);
            sum+=dp10[wh.fir]+dp0[wh.fir];
        }
    }
//    cout<<"ans8 :: "<<ans<<"\n";

    for (auto wh:reb[now]){
        if (wh.fir!=pred){
            if (wh.sec==0){
                dp0[now]+=dp0[wh.fir]+1;
                dp01[now]+=dp01[wh.fir]+dp1[wh.fir];
            }
            else{
                dp1[now]+=dp1[wh.fir]+1;
                dp10[now]+=dp10[wh.fir]+dp0[wh.fir];
            }
        }
    }

    ans+=2*dp0[now];
    ans+=2*dp1[now];
    ans+=dp01[now];
    ans+=dp10[now];

//    cout<<"after dfs :: "<<now<<" ans :: "<<ans<<"\n";
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n;
    cin>>n;
    for (int i=1;i<n;i++){
        int u,v,c;
        cin>>u>>v>>c;
        reb[u].pb(mp(v,c));
        reb[v].pb(mp(u,c));
    }
    dfs(1,1);
    cout<<ans<<"\n";
}