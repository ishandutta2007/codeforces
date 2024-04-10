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

template<typename type1,typename type2> bool maximize(type1& a,type2 b)
{
    if (a<b){
        a=b;
        return 1;
    }
    return 0;
}

vi reb[arr];

short int dp[5001][5001][3];
short int new_dp[5001][3];

int c[arr];

void dfs(int now,int pred)
{
    c[now]=1;
    for (auto wh:reb[now]){
        if (wh!=pred){
            dfs(wh,now);
            c[now]+=c[wh];
        }
    }


    int lol=1;
    dp[now][1][0]=0;
    dp[now][0][1]=1;
    dp[now][0][2]=0;
    for (auto wh:reb[now]){
        if (wh!=pred){

            for (int j=0;j<=lol+c[wh];j++){
                new_dp[j][0]=-10000;
                new_dp[j][1]=-10000;
                new_dp[j][2]=-10000;
            }

            for (int j=0;j<=lol;j++){
                for (int k=0;k<=c[wh];k++){
                    maximize(new_dp[j+k][0],dp[now][j][0]+dp[wh][k][0]);
                    maximize(new_dp[j+k][0],dp[now][j][0]+dp[wh][k][2]);

                    maximize(new_dp[j+k][1],dp[now][j][1]+dp[wh][k][1]);
                    maximize(new_dp[j+k][1],dp[now][j][1]+dp[wh][k][2]);

                    maximize(new_dp[j+k][2],dp[now][j][2]+dp[wh][k][0]);
                    maximize(new_dp[j+k][2],dp[now][j][2]+dp[wh][k][1]);
                    maximize(new_dp[j+k][2],dp[now][j][2]+dp[wh][k][2]);
                }
            }

            for (int j=0;j<=lol+c[wh];j++){
                dp[now][j][0]=new_dp[j][0];
                dp[now][j][1]=new_dp[j][1];
                dp[now][j][2]=new_dp[j][2];
            }

            lol+=c[wh];
        }
    }

//    for (int i=0;i<=c[now];i++){
//        cout<<"dp["<<now<<"]["<<i<<"]["<<0<<"] :: "<<dp[now][i][0]<<"\n";
//        cout<<"dp["<<now<<"]["<<i<<"]["<<1<<"] :: "<<dp[now][i][1]<<"\n";
//        cout<<"dp["<<now<<"]["<<i<<"]["<<2<<"] :: "<<dp[now][i][2]<<"\n";
//    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

//    return cout<<(sizeof(dp)>>20)<<"\n", 0;

    for (int i=0;i<5001;i++){
        for (int j=0;j<5001;j++){
            dp[i][j][0]=-10000;
            dp[i][j][1]=-10000;
            dp[i][j][2]=-10000;
        }
    }

    int n;
    cin>>n;
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        reb[v].pb(u);
    }

    dfs(1,1);

    int best=-1e9;
    for (int i=1;i<n;i++){
        int cur_a=i;
        int cur_b=max({dp[1][cur_a][0],dp[1][cur_a][1],dp[1][cur_a][2]});
        if (cur_b!=0&&cur_a+cur_b>best){
            best=cur_a+cur_b;
//            cout<<"new best :: "<<cur_a<<" "<<cur_b<<"\n";
        }
    }

    vector<pii> ans(0);
    for (int i=1;i<n;i++){
        int cur_a=i;
        int cur_b=max({dp[1][cur_a][0],dp[1][cur_a][1],dp[1][cur_a][2]});
        if (cur_b!=0&&cur_a+cur_b==best){
            ans.pb(mp(cur_a,cur_b));
        }
    }

    cout<<len(ans)<<"\n";
    for (auto i:ans){
        cout<<i.fir<<" "<<i.sec<<"\n";
    }
}