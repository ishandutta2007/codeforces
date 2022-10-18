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

#define arr (int)(3e5+10)

int n,m;
bool use[arr];
vector<pii> reb[arr];
vi way;
int p[arr];

void dfs(int now,int pred)
{
    p[now]=pred;
    for (auto wh:reb[now]){
        if (wh.fir!=pred){
            dfs(wh.fir,now);
        }
    }
}

int kek[arr];
int l[arr];

int pref[arr];

map<pii,int> mapa;

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    cin>>n>>m;
    for (int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        reb[u].pb({v,w});
        reb[v].pb({u,w});
        mapa[{u,v}]=w;
        mapa[{v,u}]=w;
    }
    dfs(1,-1);
    int cur=n;
    while (cur!=-1){
        way.pb(cur);
        cur=p[cur];
    }
    reverse(all(way));
    for (auto i:way){
        use[i]=1;
    }

    bool easy=0;
    for (auto now:way){
        int cnt=0;
        for (auto wh:reb[now]){
            if (!use[wh.fir]){
                if (len(reb[wh.fir])!=1){
                    easy=1;
                }
                cnt++;
                kek[now]=wh.fir;
                l[now]=wh.sec;
            }
        }
        if (cnt>1){
            easy=1;
        }
    }
    for (int i=1;i<len(way);i++){
        pref[i]=pref[i-1]+mapa[{way[i-1],way[i]}];
    }

    int easy_ans=pref[len(way)-1];

    int best_diff=1e18;

    #define lol l

    if (kek[1]){
        for (int i=1;i<len(way);i++){
            if (kek[way[i]]){
                int cur_diff=(pref[i]-pref[0])-(lol[1]+lol[way[i]]);
                best_diff=min(best_diff,cur_diff);
            }
            else{
                int cur_diff=(pref[i]-pref[0])-(lol[1]);
                best_diff=min(best_diff,cur_diff);
            }
        }
    }
    else{
        for (int i=1;i<len(way);i++){
            if (kek[way[i]]){
                int cur_diff=(pref[i]-pref[0])-(lol[way[i]]);
                best_diff=min(best_diff,cur_diff);
            }
            else{
                continue;
            }
        }
    }

//    cout<<best_diff<<" 111\n";

    if (kek[n]){
        for (int i=0;i+1<len(way);i++){
            if (kek[way[i]]){
                int cur_diff=(pref[len(way)-1]-pref[i])-(lol[n]+lol[way[i]]);
                best_diff=min(best_diff,cur_diff);
            }
            else{
                int cur_diff=(pref[len(way)-1]-pref[i])-(lol[n]);
                best_diff=min(best_diff,cur_diff);
            }
        }
    }
    else{
        for (int i=0;i+1<len(way);i++){
            if (kek[way[i]]){
                int cur_diff=(pref[len(way)-1]-pref[i])-(lol[way[i]]);
                best_diff=min(best_diff,cur_diff);
            }
            else{
                continue;
            }
        }
    }

//    cout<<best_diff<<" nnn\n";

//    for (int i=0;i+2<len(way);i++){
//        int cur_diff=(pref[i+2]-pref[i]);
//        best_diff=min(best_diff,cur_diff);
//    }

//    cout<<best_diff<<" +2+2+2\n";

    int best_value=1e18;
    bool last_added=1;
    for (int i=0;i<len(way);i++){
        if (!last_added&&kek[way[i]]){
            best_value=min(best_value,-pref[i-1]-lol[way[i-1]]);
            last_added=1;
        }
//        cout<<"pref["<<i<<"] :: "<<pref[i]<<"\n";
        int cur_diff=pref[i]-lol[way[i]]+best_value;
        best_diff=min(best_diff,cur_diff);

        if (!last_added){
            best_value=min(best_value,-pref[i-1]-lol[way[i-1]]);
            last_added=1;
        }

        last_added=0;

        if (kek[way[i]]){
            best_value=min(best_value,-pref[i]-lol[way[i]]);
            last_added=1;
        }
    }

//    cout<<best_diff<<" end\n";

//    cout<<"easy :: "<<easy<<" !!!\n";

    for (int i=1;i<=m;i++){
        int x;
        cin>>x;
        int answer;

        if (easy){
            answer=easy_ans;
        }
        else{
            answer=min(easy_ans,easy_ans-(best_diff-x));
        }

        cout<<answer<<"\n";
    }
}