/*
  Compete against Yourself.
  Author - Aryan (@aryanc403)
  Atcoder library - https://atcoder.github.io/ac-library/production/document_en/
*/

#ifdef ARYANC403
    #include <header.h>
#else
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
    #pragma GCC optimize ("-ffloat-store")
    #include<bits/stdc++.h>
    #define dbg(args...) 42;
    #define endl "\n"
#endif

// y_combinator from @neal template https://codeforces.com/contest/1553/submission/123849801
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) ((lli)(x).size())
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;


const auto start_time = std::chrono::high_resolution_clock::now();
void aryanc403()
{
#ifdef ARYANC403
auto end_time = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end_time-start_time;
    cerr<<"Time Taken : "<<diff.count()<<"\n";
#endif
}

const lli INF = 0xFFFFFFFFFFFFFFFL;

lli seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline lli rnd(lli l=0,lli r=INF)
{return uniform_int_distribution<lli>(l,r)(rng);}

class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.X < b.X || ( a.X==b.X && a.Y <= b.Y ));   }};

void add( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt==m.end())         m.insert({x,cnt});
    else                    jt->Y+=cnt;
}

void del( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt->Y<=cnt)            m.erase(jt);
    else                      jt->Y-=cnt;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;

template <typename T>
struct segTreeWithRollBacks{
    int N;
    vector<vector<T>> values;
    segTreeWithRollBacks(int n):N(n),values(4*n,vi(1,-1)){};
    T op(const T a,const T b){
        return max(a,b);
    }
    void update(int id,int l,int r,int L,int R,T v){
        if(r<L||R<l)
            return;
        if(L<=l&&r<=R){
            if(v==-1)
                values[id].pop_back();
            else
                values[id].pb(op(v,values[id].back()));
            return;
        }
        lli m=(l+r)/2;
        update(2*id,l,m,L,R,v);
        update(2*id+1,m+1,r,L,R,v);
    }
    void update(int l,int r,T v){
        update(1,0,N-1,l,r,v);
    }
    T query(int id,int l,int r,int pos){
        if(r<pos||pos<l)
            return T(-1);
        auto cur=values[id].back();
        // dbg(id,values[id]);
        if(l==r)
            return cur;
        int m=(l+r)/2;
        cur=op(cur,query(2*id,l,m,pos));
        cur=op(cur,query(2*id+1,m+1,r,pos));
        return cur;
    }
    T query(int pos){
        return query(1,0,N-1,pos);
    }
};

namespace aho_corasick{
    const int K = 26;
    struct Vertex {
        int next[K];
        int leaf = -1;
        int p = -1;
        char pch;
        int link = -1;
        int go[K];
        set<int> queryTime;
        Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
            fill(begin(next), end(next), -1);
            fill(begin(go), end(go), -1);
        }
    };

    vector<Vertex> t(1);

    void add_string(string const& s,int idx) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (t[v].next[c] == -1) {
                t[v].next[c] = t.size();
                t.emplace_back(v, ch);
            }
            v = t[v].next[c];
            // dbg(v,ch,s);
        }
        t[v].leaf = idx;
        dbg(v,idx);
    }

    int go(int v, char ch);

    int get_link(int v) {
        if (t[v].link == -1) {
            if (v == 0 || t[v].p == 0)
                t[v].link = 0;
            else
                t[v].link = go(get_link(t[v].p), t[v].pch);
        }
        return t[v].link;
    }

    int go(int v, char ch) {
        int c = ch - 'a';
        if (t[v].go[c] == -1) {
            if (t[v].next[c] != -1)
                t[v].go[c] = t[v].next[c];
            else
                t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
        }
        return t[v].go[c];
    }

    void findString(const string &s,const int tim){
        int v=0;
        for(auto x:s){
            v=go(v,x);
            dbg(tim,v);
            t[v].queryTime.insert(tim);
        }
    }

    void solve(vi &ans,vector<vii> &updates){
        const int n=sz(ans);
        segTreeWithRollBacks<lli> seg(n);
        vector<vii> stk;
        const int N=sz(t);
        vector<vi> g(N);
        for(int v=0;v<N;++v){
            const int u=get_link(v);
            if(u!=v)
                g[u].pb(v);
        }
        y_combinator([&](const auto &self,const int v)->void{
            if(v==-1)
                return;
            const int leaf=t[v].leaf;
            if(leaf!=-1){
                auto &a=updates[leaf];
                a.pb({1e9,0});
                // stk.pb(a);
                for(int i=0;i+1<sz(a);++i){
                    seg.update(a[i].X,a[i+1].X-1,a[i].Y);
                }
            }
            dbg(t[v].queryTime);
            if(t[v].queryTime.count(4)){
                dbg(t[v].queryTime);
                dbg(stk);
            }
            for(const auto q:t[v].queryTime){
                ans[q]=max(ans[q],seg.query(q));
                // dbg(q,seg.query(q));
            }

            for(auto lk:g[v])
                self(lk);

            if(leaf!=-1){
                auto &a=updates[leaf];
                // stk.pop_back();
                for(int i=0;i+1<sz(a);++i){
                    seg.update(a[i].X,a[i+1].X-1,-1);
                }
            }
        })(0);
    }
};

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;
    vector<string> a(n);
    vi aa;
    for(auto &s:a)
        cin>>s;
    auto b=a;
    sort(all(b));
    (b).erase(unique(all(b)),(b).end());
    vi oldValue(n);
    n=sz(b);
    for(int i=0;i<n;++i)
        aho_corasick::add_string(b[i],i);
    vector<map<lli,lli>> scores(n,{{0,1}});
    vi maxScores(n);
    for(auto s:a)
    {
        const lli u=lower_bound(all(b),s)-b.begin();
        aa.pb(u);
        scores[u][0]++;
    }

    dbg(aa);
    dbg(scores);
    vector<vii> updates(n,{{0,0}});
    auto updateValue=[&](const lli idx,const lli val,const lli pos){
        const lli u=aa[idx];
        del(scores[u],oldValue[idx]);
        scores[u][val]++;
        oldValue[idx]=val;
        if(maxScores[u]!=scores[u].rbegin()->X){
            maxScores[u]=scores[u].rbegin()->X;
            updates[u].pb({pos,maxScores[u]});
        }
    };

    vi type2;
    vi answers(m+1,-1);
    fo(i,m)
    {
        cin>>T;
        if(T==2){
            cin>>s;
            aho_corasick::findString(s,i);
            type2.pb(i);
            continue;
        }
        lli idx,val;
        cin>>idx>>val;
        updateValue(idx-1,val,i);
    }
    dbg(type2);
    aho_corasick::solve(answers,updates);
    for(auto x:type2)
        cout<<answers[x]<<endl;
}   aryanc403();
    return 0;
}