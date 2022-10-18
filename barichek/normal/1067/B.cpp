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

vi reb[arr];

const int M=20;

bool down[arr][M];
bool up[arr][M];
int pp[arr];

void dfs1(int now,int pred)
{
    pp[now]=pred;
    if (len(reb[now])==1){
        down[now][0]=1;
    }
    int cnt_go=0;
    for (auto wh:reb[now]){
        if (wh!=pred){
            cnt_go++;
            dfs1(wh,now);
        }
    }
    if (cnt_go>=3){
        for (int k=1;k<M;k++){
            down[now][k]=1;
            for (auto wh:reb[now]){
                if (wh!=pred){
                    down[now][k]&=down[wh][k-1];
                }
            }
        }
    }
}

int cur_cnt[M];

void dfs2(int now,int pred)
{
    if (now==pred){
        /// we are in root
        /// to zhe samoe
        /// plus up[wh][1]

        int cnt_leaf=0;
        for (auto wh:reb[now]){
            if (len(reb[wh])==1){
                cnt_leaf++;
            }
        }
        for (auto wh:reb[now]){
            if (len(reb[wh])==1){
                cnt_leaf--;
            }

            if (cnt_leaf>=3&&len(reb[now])-1==cnt_leaf){
                up[wh][1]=1;
            }

            if (len(reb[wh])==1){
                cnt_leaf++;
            }
        }
    }

    memset(cur_cnt,0,sizeof(cur_cnt));
    for (auto wh:reb[now]){
        if (wh!=pred){
            for (int k=1;k<M;k++){
                if (down[wh][k]){
                    cur_cnt[k]++;
                }
            }
        }
        else{
            for (int k=1;k<M;k++){
                if (up[now][k]){
                    cur_cnt[k]++;
                }
            }
        }
    }

    for (auto wh:reb[now]){
        if (wh!=pred){
            for (int k=1;k<M;k++){
                if (down[wh][k]){
                    cur_cnt[k]--;
                }
            }

            for (int k=1;k+1<M;k++){
                if (len(reb[now])-1==cur_cnt[k]&&cur_cnt[k]>=3){
                    up[wh][k+1]=1;
                }
            }

            for (int k=1;k<M;k++){
                if (down[wh][k]){
                    cur_cnt[k]++;
                }
            }
        }
    }

    for (auto wh:reb[now]){
        if (wh!=pred){
            dfs2(wh,now);
        }
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n,k;
    cin>>n>>k;
    if (n<=2||k>=M){
        cout<<"No"<<"\n";
        return 0;
    }
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        reb[v].pb(u);
    }

    int root=-1;
    for (int i=1;i<=n;i++){
        if (len(reb[i])>1){
            root=i;
        }
    }

    if (k==1){
        if (n>=4&&len(reb[root])==n-1){
            cout<<"Yes"<<"\n";
            return 0;
        }
        else{
            cout<<"No"<<"\n";
            return 0;
        }
    }

    dfs1(root,root);
    dfs2(root,root);

    for (int i=1;i<=n;i++){
        if (1){
            bool ok=1;
            int cnt_go=0;
            for (auto wh:reb[i]){
                if (wh!=pp[i]){
                    cnt_go++;
                    ok&=down[wh][k-1];
                }
                else{
                    cnt_go++;
                    ok&=up[i][k-1];
                }
            }
            ok&=(cnt_go>=3);

            if (ok){
                cout<<"Yes"<<"\n";
//                cout<<"answer :: "<<i<<"\n";
                return 0;
            }
        }
    }

    cout<<"No"<<"\n";
}