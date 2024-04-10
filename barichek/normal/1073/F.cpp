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

struct answer
{
    int u1,v1;
    int u2,v2;
    int intersect;
    int sum_length;

    answer()
    {
        u1=-1;
        v1=-1;
        u2=-1;
        v2=-1;
        intersect=-1e18;
        sum_length=-1e18;
    }
};

ostream& operator<<(ostream& os,answer ans)
{
    os<<"{"<<ans.intersect<<", "<<ans.sum_length<<", "<<ans.u1<<" "<<ans.v1<<", "<<ans.u2<<" "<<ans.v2<<"}";
    return os;
}

bool operator<(const answer& a1,const answer& a2)
{
    if (a1.intersect!=a2.intersect){
        return a1.intersect>a2.intersect;
    }
    return a1.sum_length>a2.sum_length;
}

answer ans=*new answer();

void relax(answer a1)
{
    if (a1<ans){
//        cout<<"relaxing :)"<<"\n";
        ans=a1;
    }
}

int d[arr];

const int M=20;

int p[arr][M];

int lca(int u,int v)
{
    if (d[u]>d[v]){
        swap(u,v);
    }
    for (int i=M-1;i>=0;i--){
        if (d[u]<=d[p[v][i]]){
            v=p[v][i];
        }
    }
    if (u==v){
        return u;
    }
    for (int i=M-1;i>=0;i--){
        if (p[u][i]!=p[v][i]){
            u=p[u][i];
            v=p[v][i];
        }
    }
    return p[u][0];
}

int dist(int u,int v)
{
    int l=lca(u,v);
    return d[u]+d[v]-2*d[l];
}

void dfs0(int now,int pred)
{
    p[now][0]=pred;
    for (int j=1;j<M;j++){
        p[now][j]=p[p[now][j-1]][j-1];
    }

    for (auto wh:reb[now]){
        if (wh!=pred){
            d[wh]=d[now]+1;
            dfs0(wh,now);
        }
    }
}

int best_up[arr];
int best_down[arr];

void dfs1(int now,int pred)
{
    best_down[now]=now;
    for (auto wh:reb[now]){
        if (wh!=pred){
            dfs1(wh,now);
            if (d[best_down[now]]<d[best_down[wh]]){
                best_down[now]=best_down[wh];
            }
        }
    }

//    cout<<"best_down["<<now<<"] :: "<<best_down[now]<<"\n";
}

void dfs2(int now,int pred)
{
    if (now==pred){
        best_up[now]=now;
    }
    set<pii> s;
    s.clear();
    if (now!=pred){
        s.insert(mp(dist(now,best_up[now]),best_up[now]));
    }
    for (auto wh:reb[now]){
        if (wh!=pred){
            s.insert(mp(dist(now,best_down[wh]),best_down[wh]));
        }
    }

    for (auto wh:reb[now]){
        if (wh!=pred){
            s.erase(mp(dist(now,best_down[wh]),best_down[wh]));
            if (!s.empty()){
                best_up[wh]=(--s.end())->sec;
            }
            else{
                best_up[wh]=now;
            }
            s.insert(mp(dist(now,best_down[wh]),best_down[wh]));
        }
    }

    for (auto wh:reb[now]){
        if (wh!=pred){
            dfs2(wh,now);
        }
    }
}

int r_cur_d[arr];

set<pair<int,pair<int,pii>>> ss;

void dfs3(int now,int pred)
{
//    cout<<"  dfs3 :: "<<now<<" "<<pred<<"\n";
//    cout<<"    len(ss) :: "<<len(ss)<<"\n";
    r_cur_d[d[now]]=now;
    if (!ss.empty()){
        vector<pii> vv(0);
        for (auto wh:reb[now]){
            if (wh!=pred){
                vv.pb(mp(d[best_down[wh]],best_down[wh]));
            }
        }
        sort(all(vv));
        reverse(all(vv));

        if (len(vv)>=2){
//            cout<<"    i am here :: "<<"label1"<<"\n";
            auto kek=*ss.begin();

            answer cur_ans;
            cur_ans.intersect=d[now]-kek.fir+1;
            cur_ans.sum_length=0;

            cur_ans.u1=vv[0].sec;
            cur_ans.u2=vv[1].sec;

            cur_ans.v1=kek.sec.sec.fir;
            cur_ans.v2=kek.sec.sec.sec;

            cur_ans.sum_length=(vv[0].fir-d[now])+(vv[1].fir-d[now])+(d[now]-kek.fir)*2+(-kek.sec.fir);

//            cout<<"cur_ans :: "<<cur_ans<<"\n";

            relax(cur_ans);
        }
    }
    set<pii> s;
    s.clear();
    if (now!=pred){
        s.insert(mp(dist(now,best_up[now]),best_up[now]));
    }
    for (auto wh:reb[now]){
        if (wh!=pred){
            s.insert(mp(dist(now,best_down[wh]),best_down[wh]));
        }
    }
    for (auto wh:reb[now]){
        if (wh!=pred){
            s.erase(mp(dist(now,best_down[wh]),best_down[wh]));

            pair<int,pair<int,pii>> cur_kek;
            if (len(s)>=2){
                cur_kek.fir=d[now];

                cur_kek.sec.fir=(--(s.end()))->fir+(--(--(s.end())))->fir;
                cur_kek.sec.fir*=-1;

                cur_kek.sec.sec.fir=(--(s.end()))->sec;
                cur_kek.sec.sec.sec=(--(--(s.end())))->sec;

                ss.insert(cur_kek);
            }
            dfs3(wh,now);
            if (len(s)>=2){
                ss.erase(cur_kek);
            }

            s.insert(mp(dist(now,best_down[wh]),best_down[wh]));
        }
    }
}

int n;

void solve_up()
{
    dfs1(1,1);
    dfs2(1,1);
    dfs3(1,1);
}

pair<int,pii> best_two[arr];
pair<pair<int,pair<int,pii>>,int> best_two_in_sub[arr];

void dfs5(int now,int pred)
{
    best_two[now]=mp(-1e18,mp(-1,-1));

    vector<pii> vv(0);
    for (auto wh:reb[now]){
        if (wh!=pred){
            vv.pb(mp(d[best_down[wh]],best_down[wh]));
        }
    }
    sort(all(vv));
    reverse(all(vv));

    if (len(vv)>=2){
        best_two[now]=mp((vv[0].fir-d[now])+(vv[1].fir-d[now]),mp(vv[0].sec,vv[1].sec));
    }

//    cout<<"best_two["<<now<<"] :: "<<best_two[now].fir<<", "<<best_two[now].sec.fir<<" "<<best_two[now].sec.sec<<"\n";

    for (auto wh:reb[now]){
        if (wh!=pred){
            dfs5(wh,now);
        }
    }
}

void dfs6(int now,int pred)
{
    for (auto wh:reb[now]){
        if (wh!=pred){
            dfs6(wh,now);
        }
    }

    vector<pair<pair<int,pair<int,pii>>,int>> vv(0);
    if (best_two[now].fir>=0){
        vv.pb(mp(mp(d[now],best_two[now]),now));
    }

    for (auto wh:reb[now]){
        if (wh!=pred){
            if (best_two_in_sub[wh].fir.fir>=0){
                vv.pb(best_two_in_sub[wh]);
            }
        }
    }
    sort(all(vv));
    reverse(all(vv));

    if (!vv.empty()){
        best_two_in_sub[now]=vv[0];
    }
    else{
        best_two_in_sub[now]=mp(mp(-1e18,mp(-1e18,mp(-1,-1))),now);
    }
//    cout<<"best_two_in_sub["<<now<<"] :: "<<best_two_in_sub[now].fir.fir<<" "<<best_two_in_sub[now].fir.sec.fir<<" || "<<best_two_in_sub[now].fir.sec.sec.fir<<" "<<best_two_in_sub[now].fir.sec.sec.sec<<"\n";
}

void dfs7(int now,int pred)
{
    vector<pair<pair<int,pair<int,pii>>,int>> vv(0);
    for (auto wh:reb[now]){
        if (wh!=pred){
            vv.pb(best_two_in_sub[wh]);
        }
    }
    sort(all(vv));
    reverse(all(vv));

    if (len(vv)>=2&&vv[0].fir.fir>=0&&vv[1].fir.fir>=0){
        answer cur_ans;

        auto kek1=vv[0];
        auto kek2=vv[1];

        cur_ans.intersect=(kek1.fir.fir-d[now]+1)+(kek2.fir.fir-d[now]+1);
        cur_ans.sum_length=kek1.fir.sec.fir+2*(kek1.fir.fir-d[now])+kek2.fir.sec.fir+2*(kek2.fir.fir-d[now]);

        cur_ans.u1=kek1.fir.sec.sec.fir;
        cur_ans.u2=kek1.fir.sec.sec.sec;

        cur_ans.v1=kek2.fir.sec.sec.fir;
        cur_ans.v2=kek2.fir.sec.sec.sec;

        relax(cur_ans);
    }

    for (auto wh:reb[now]){
        if (wh!=pred){
            dfs7(wh,now);
        }
    }
}

void solve_down()
{
    dfs5(1,1);
    dfs6(1,1);
    dfs7(1,1);
}

void dfs4(int now,int pred)
{
    vector<pii> vv(0);
    if (now!=pred){
        vv.pb(mp(dist(now,best_up[now]),best_up[now]));
    }
    for (auto wh:reb[now]){
        if (wh!=pred){
            vv.pb(mp(dist(now,best_down[wh]),best_down[wh]));
        }
    }
    sort(all(vv));
    reverse(all(vv));

    if (len(vv)>=4){
        answer cur_ans;

        cur_ans.intersect=1;
        cur_ans.sum_length=vv[0].fir+vv[1].fir+vv[2].fir+vv[3].fir;

        cur_ans.u1=vv[0].sec;
        cur_ans.u2=vv[1].sec;

        cur_ans.v1=vv[2].sec;
        cur_ans.v2=vv[3].sec;

        relax(cur_ans);
    }

    for (auto wh:reb[now]){
        if (wh!=pred){
            dfs4(wh,now);
        }
    }
}

void solve_ans_eq_1()
{
    dfs4(1,1);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    cin>>n;
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        reb[v].pb(u);
    }

    dfs0(1,1);

    solve_up();
//    if (n==200000){
//        cout<<"after up :: "<<"\n";
//        cout<<ans<<"\n";
//    }
    solve_down();
//    if (n==200000){
//        cout<<"after down :: "<<"\n";
//        cout<<ans<<"\n";
//    }
    solve_ans_eq_1();

//    cout<<"last_ans :: "<<"\n";
    cout<<ans.u1<<" "<<ans.v1<<"\n";
    cout<<ans.u2<<" "<<ans.v2<<"\n";
}