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

map<vi,int> rem;

int get(vi a)
{
    sort(all(a));
    if (len(a)==1){
        return 0;
    }
    if (rem.count(a)){
        return rem[a];
    }
    cout<<"?"<<" "<<len(a)<<"\n";
    for (auto i:a){
        cout<<i<<" ";
    }
    cout<<"\n";
    fflush(stdout);
    int res;
    cin>>res;
    fflush(stdout);
    return rem[a]=res;
}

vi merge(vi a,vi b)
{
    for (auto i:b){
        a.pb(i);
    }
    return a;
}

int get(vi a,vi b)
{
    int res=0;

    res+=get(merge(a,b));

    res-=get(a);
    res-=get(b);

    return res;
}

pii find_edge(vi a,vi b)
{
    while (len(a)!=1||len(b)!=1){
        if (len(a)==1){
            a.swap(b);
        }
        vi a1(0);
        vi a2(0);
        for (int i=0;i<len(a)/2;i++){
            a1.pb(a[i]);
        }
        for (int i=len(a)/2;i<len(a);i++){
            a2.pb(a[i]);
        }
        if (get(a1,b)!=0){
            a=a1;
        }
        else{
            a=a2;
        }
    }

    return mp(a[0],b[0]);
}

vi erase(vi a,int b)
{
    vi res(0);
    for (auto i:a){
        if (i!=b){
            res.pb(i);
        }
    }
    return res;
}

int count(vi a,int b)
{
    int res=0;
    for (auto i:a){
        res+=(i==b);
    }
    return res;
}

pii find_edge(vi a)
{
    for (auto i:a){
        if (get(vi{i},erase(a,i))!=0){
            return find_edge(vi{i},erase(a,i));
        }
    }
}

int n;

vi reb[arr];

void add_edge(int u,int v)
{
    reb[u].pb(v);
    reb[v].pb(u);
}

void build_tree()
{
    vi s(0);
    s.pb(1);

    vi nots(0);
    for (int i=2;i<=n;i++){
        nots.pb(i);
    }

    while (len(s)!=n){
        pii kek=find_edge(s,nots);
        if (!count(s,kek.fir)){
            swap(kek.fir,kek.sec);
        }

        add_edge(kek.fir,kek.sec);

        s.pb(kek.sec);
        nots=erase(nots,kek.sec);
    }
}

bool use[arr];
int color[arr];
int p[arr];

void dfs(int now)
{
    use[now]=1;
    for (auto wh:reb[now]){
        if (!use[wh]){
            p[wh]=now;
            color[wh]=color[now]^1;

            dfs(wh);
        }
    }
}

void print_answer_yes(vi a)
{
    cout<<"Y"<<" "<<len(a)<<"\n";
    for (auto i:a){
        cout<<i<<" ";
    }
    cout<<"\n";
    exit(0);
}

int lca(int u,int v)
{
    set<int> s;
    s.clear();

    while (u){
        s.insert(u);
        u=p[u];
    }

    while (!s.count(v)){
        v=p[v];
    }
    return v;
}

void print_answer_cycle(int u,int v)
{
    int l=lca(u,v);
    vi res1(0);
    vi res2(0);

    while (u!=l){
        res1.pb(u);
        u=p[u];
    }
    res1.pb(l);

    while (v!=l){
        res2.pb(v);
        v=p[v];
    }
    reverse(all(res2));

    vi res=merge(res1,res2);

    cout<<"N"<<" "<<len(res)<<"\n";
    for (auto i:res){
        cout<<i<<" ";
    }
    cout<<"\n";
    exit(0);
}

void do_check()
{
    build_tree();
    dfs(1);
    vi a1(0);
    vi a2(0);
    for (int i=1;i<=n;i++){
        if (color[i]==0){
            a1.pb(i);
        }
        else{
            a2.pb(i);
        }
    }
    if (get(a1)!=0){
        pii kek=find_edge(a1);
        print_answer_cycle(kek.fir,kek.sec);
    }
    if (get(a2)!=0){
        pii kek=find_edge(a2);
        print_answer_cycle(kek.fir,kek.sec);
    }
    print_answer_yes(a1);
}

main()
{
//    #ifdef I_love_Maria_Ivanova
//        files("barik");
//        freopen("debug.txt","w",stderr);
//    #endif

    cin>>n;
    if (n==1){
        print_answer_yes(vi{1});
    }
    do_check();
}