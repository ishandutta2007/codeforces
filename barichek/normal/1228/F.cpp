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

#define arr (int)(1e6+10)

set<int> reb[arr];

int n;

int sz[arr];
bool use[arr];

void dfs1(int now)
{
    use[now]=1;
    sz[now]=1;
    for (auto wh:reb[now]){
        if (!use[wh]){
            dfs1(wh);
            sz[now]+=sz[wh];
        }
    }
}

int f(int start,int now,int pred)
{
    for (auto wh:reb[now]){
        if (wh!=pred){
            if (2*sz[wh]>sz[start]){
                return f(start,wh,now);
            }
        }
    }
    return now;
}

bool flag_ans_2=0;

int find_c()
{
    int any_step_2=-1;
    for (int i=1;i<=n;i++){
        if (len(reb[i])==2){
            any_step_2=i;
        }
    }
//    cout<<"any_step_2 :: "<<any_step_2<<"\n";
//    if (any_step_2==-1){
//        cout<<0<<"\n";
//        exit(0);
//    }
    if (any_step_2!=-1){
        dfs1(any_step_2);
        return f(any_step_2,any_step_2,-1);
    }
    else{
        flag_ans_2=1;
        dfs1(1);
        return f(1,1,-1);
    }
}

void dfs2(int now,int pred)
{
    sz[now]=1;
    for (auto wh:reb[now]){
        if (wh!=pred){
            dfs2(wh,now);
            sz[now]+=sz[wh];
        }
    }
}

int answer=-1;
vi to[arr];

void dfs3(int now,int pred,int want)
{
//    cout<<"dfs3 :: "<<now<<" "<<pred<<" "<<want<<"\n";
    for (auto wh:reb[now]){
        if (wh!=pred){
//            cout<<now<<" -> "<<wh<<"\n";
            to[now].pb(wh);
        }
    }
    if (len(to[now])>3){
        cout<<0<<"\n";
        exit(0);
    }
    if (len(to[now])==1){
        answer=now;
        return;
    }
    if (len(to[now])==3){
        answer=now;
        return;
    }
    for (auto wh:to[now]){
        if (sz[wh]!=(want-1)/2){
            dfs3(wh,now,(want-1)/2);
        }
    }
}

void dfs4(int now,int pred,int want)
{
    sz[now]=1;
    for (auto wh:reb[now]){
        if (wh!=pred){
            dfs4(wh,now,(want-1)/2);
            sz[now]+=sz[wh];
        }
    }
    if (sz[now]!=want){
        cout<<0<<"\n";
        exit(0);
    }
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    cin>>n;
    if (n==2){
        cout<<2<<"\n";
        cout<<1<<" "<<2<<"\n";
        return 0;
    }

    auto add_edge=[&](int u,int v)
    {
        reb[u].insert(v);
        reb[v].insert(u);
    };

    auto del_edge=[&](int u,int v)
    {
        reb[u].erase(v);
        reb[v].erase(u);
    };

    n=(1ll<<n)-2;
    vector<pii> st_edge;
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add_edge(u,v);
        st_edge.pb(mp(u,v));
    }
    int c=find_c();
//    cout<<"c :: "<<c<<"\n";
    dfs2(c,-1);
    dfs3(c,-1,n+1);
//    cout<<"answer :: "<<answer<<"\n";
    if (answer==-1){
        cout<<0<<"\n";
        return 0;
    }

    n++;
    if (len(to[answer])==1){
        add_edge(answer,n);
    }
    else{
        set<int> them;
        them.clear();
        for (auto i:to[answer]){
            them.insert(i);
        }
        int poson=-1;
        for (auto i:to[answer]){
            if (poson==-1||sz[poson]<sz[i]){
                poson=i;
            }
        }
        them.erase(poson);

        for (auto i:them){
            del_edge(answer,i);
            add_edge(n,i);
        }
        add_edge(answer,n);
    }

    dfs4(c,-1,n);

    if (!flag_ans_2){
        cout<<1<<"\n";
        cout<<answer<<"\n";
    }
    else{
//        if (answer==53){
//            exit(1);
//        }
        for (int i=1;i<=n;i++){
            reb[i].clear();
        }
        for (auto i:st_edge){
            add_edge(i.fir,i.sec);
        }
        int answer1=answer;
        int answer2=-1;
        dfs2(answer1,-1);
        for (auto wh:reb[answer1]){
            if (answer2==-1||sz[wh]>sz[answer2]){
                answer2=wh;
            }
        }
        if (answer1>answer2){
            swap(answer1,answer2);
        }
        cout<<2<<"\n";
        cout<<answer1<<" "<<answer2<<"\n";
    }
}