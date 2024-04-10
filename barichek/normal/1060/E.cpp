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

int cnt[arr][2];
int sum[arr];
vi reb[arr];
int lol[arr];

int ans=0;

int cnt1=0;

void dfs(int now,int pred)
{
    int kek=1;
    cnt[now][0]=1;
    for (auto wh:reb[now]){
        if (wh!=pred){
            dfs(wh,now);

            kek+=cnt[wh][0]+cnt[wh][1];

            sum[now]+=sum[wh]+cnt[wh][0]+cnt[wh][1];

            cnt1+=cnt[now][0]*cnt[wh][0];
            cnt1+=cnt[now][1]*cnt[wh][1];

            cnt[now][0]+=cnt[wh][1];
            cnt[now][1]+=cnt[wh][0];
        }
    }
    for (auto wh:reb[now]){
        if (wh!=pred){
            kek-=cnt[wh][0]+cnt[wh][1];
            ans+=kek*(sum[wh]+cnt[wh][0]+cnt[wh][1]);
            kek+=cnt[wh][0]+cnt[wh][1];
        }
    }
//    int kek=0;
//
//    int lol1=0;
//
//    int kekus=0;
//
//    for (auto wh:reb[now]){
//        if (wh!=pred){
//            dfs(wh,now);
//
//            ans+=kek*(cnt[wh][0]+cnt[wh][1]);
////            if (kek*(cnt[wh][0]+cnt[wh][1])){
////                cout<<"lol1 :: wh :: "<<wh<<" :: "<<kek*(cnt[wh][0]+cnt[wh][1])<<"\n";
////            }
//
//            kekus+=cnt[wh][1]*lol1;
//            lol1+=cnt[wh][1];
//
//
//            kek+=cnt[wh][0]+cnt[wh][1];
//
//            cnt[now][0]+=cnt[wh][1];
//            cnt[now][1]+=cnt[wh][0];
//
//            sum[now][0]+=sum[wh][1]+cnt[wh][1];
//            sum[now][1]+=sum[wh][0]+cnt[wh][0];
//        }
//    }
//
//    for (auto wh:reb[now]){
//        if (wh!=pred){
//            kek-=cnt[wh][0]+cnt[wh][1];
//            ans+=kek*lol[wh];
////            if (kek*lol[wh]){
////                cout<<"lol2 :: now :: "<<now<<" && wh :: "<<wh<<" :: "<<kek*lol[wh]<<"\n";
////            }
//            kek+=cnt[wh][0]+cnt[wh][1];
//        }
//    }
//
//    ans-=kekus;
//
//    lol[now]=sum[now][0]/2+(sum[now][1]-cnt[now][1])/2+cnt[now][1];
//    ans+=lol[now];
//
////    cout<<"lol["<<now<<"] :: "<<lol[now]<<"\n";
//
//    cnt[now][0]++;
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
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        reb[v].pb(u);
    }
    dfs(1,1);
//    cout<<ans<<" "<<cnt1<<"\n";
    cout<<(ans-cnt1)/2+cnt1<<"\n";
}