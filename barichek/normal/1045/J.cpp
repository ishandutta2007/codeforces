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

#define md1 (ll)(1e9+7)
#define md2 (ll)(1e9+9)

ll p1[arr];
ll p2[arr];

unordered_map<ll,int> hashes[101];

ll get_hash(pii a)
{
    return a.fir*1256336ll+a.sec^12453624ll;
}

void add_string(const string& s,int val)
{
    ll h1=0;
    ll h2=0;
    for (int i=0;i<len(s);i++){
        h1=(h1+1ll*(s[i]-'a'+1)*p1[i]%md1)%md1;
        h2=(h2+1ll*(s[i]-'a'+1)*p2[i]%md2)%md2;
        if (hashes[i+1].count(get_hash({h1,h2}))){
            hashes[i+1][get_hash({h1,h2})]+=val;
        }
    }
}

int get_cnt(const string& s)
{
    ll h1=0;
    ll h2=0;
    for (int i=0;i<len(s);i++){
        h1=(h1+1ll*(s[i]-'a'+1)*p1[i]%md1)%md1;
        h2=(h2+1ll*(s[i]-'a'+1)*p2[i]%md2)%md2;
    }
    return hashes[len(s)][get_hash({h1,h2})];
}

vector<pair<int,bool>> rem_req[arr];

int ans[arr];

string sss[arr];

void process(pair<int,bool> req)
{
    if (req.sec){
        reverse(all(sss[abs(req.fir)]));
    }
    if (req.fir<0){
        ans[-req.fir]-=get_cnt(sss[-req.fir]);
    }
    else{
        ans[req.fir]+=get_cnt(sss[req.fir]);
    }
    if (req.sec){
        reverse(all(sss[abs(req.fir)]));
    }
}

vector<pair<int,char>> reb[arr];
int pred[arr][20];
char char_up[arr];
int d[arr];

void dfs(int now,int pred)
{
    ::pred[now][0]=pred;
    for (int i=1;i<20;i++){
        ::pred[now][i]=::pred[::pred[now][i-1]][i-1];
    }
    for (auto wh:reb[now]){
        if (wh.fir!=pred){
            d[wh.fir]=d[now]+1;
            dfs(wh.fir,now);
            char_up[wh.fir]=wh.sec;
        }
    }
}

void dfs2(int u,int pred)
{
    string cur;
    cur.clear();
    int uu=u;
    while (len(cur)<100&&uu!=1){
        cur+=char_up[uu];
        uu=::pred[uu][0];
    }
    add_string(cur,+1);
    for (auto q:rem_req[u]){
        process(q);
    }
    for (auto wh:reb[u]){
        if (wh.fir!=pred){
            dfs2(wh.fir,u);
        }
    }
    add_string(cur,-1);
}

int lca(int u,int v)
{
    if (d[u]>d[v]){
        swap(u,v);
    }
    for (int i=19;i>=0;i--){
        if (d[pred[v][i]]>=d[u]){
            v=pred[v][i];
        }
    }
    if (u==v){
        return u;
    }
    for (int i=19;i>=0;i--){
        if (pred[u][i]!=pred[v][i]){
            u=pred[u][i];
            v=pred[v][i];
        }
    }
    return pred[u][0];
}

int get_kth(int u,int k)
{
    for (int i=0;i<20;i++){
        if (k&(1ll<<i)){
            u=pred[u][i];
        }
    }
    return u;
}

int z[arr];

void build_z(const string& s)
{
    for (int i=1,l=0,r=0;i<len(s);i++){
        z[i]=0;
        if (i<=r){
            z[i]=min(z[i-l],r-i+1);
        }
        while (i+z[i]<len(s)&&s[i+z[i]]==s[z[i]]){
            z[i]++;
        }
        if (i+z[i]-1>r){
            r=i+z[i]-1;
            l=i;
        }
    }
}

int get_naive(const string& s,const string& t)
{
    string T=s+"#"+t;
    build_z(T);
    int res=0;
    for (int i=0;i+len(s)-1<len(T);i++){
        res+=(z[i]>=len(s));
    }
    return res;
}

void do_req(int u,int v,const string& s,int id)
{
    int l=lca(u,v);

    if (d[u]-d[l]>len(s)){
        rem_req[u].pb({id,0});
        u=get_kth(u,d[u]-d[l]-len(s));
        rem_req[u].pb({-id,0});
    }
    if (d[v]-d[l]>len(s)){
        rem_req[v].pb({id,1});
        v=get_kth(v,d[v]-d[l]-len(s));
        rem_req[v].pb({-id,1});
    }

    string t1="";
    string t2="";
    while (u!=l){
        t1+=char_up[u];
        u=pred[u][0];
    }
    while (v!=l){
        t2+=char_up[v];
        v=pred[v][0];
    }
    reverse(all(t2));

    ans[id]+=get_naive(s,t1+t2);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    p1[0]=1;
    for (int i=1;i<arr;i++){
        p1[i]=p1[i-1]*31%md1;
    }
    p2[0]=1;
    for (int i=1;i<arr;i++){
        p2[i]=p2[i-1]*31%md2;
    }

    int n;
    cin>>n;
    for (int i=1;i<n;i++){
        int u,v;
        char c;
        cin>>u>>v>>c;
        reb[u].pb({v,c});
        reb[v].pb({u,c});
    }
    dfs(1,1);
    int q;
    cin>>q;
    for (int i=1;i<=q;i++){
        int u,v;
        string s;
        cin>>u>>v>>s;

        get_cnt(s);
        reverse(all(s));
        get_cnt(s);
        reverse(all(s));

        sss[i]=s;
        do_req(u,v,s,i);
    }
    dfs2(1,1);
    for (int i=1;i<=q;i++){
        cout<<ans[i]<<"\n";
    }
}