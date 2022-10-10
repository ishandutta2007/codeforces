/* in the name of Anton */

/*
  Compete against Yourself.
  Author - Aryan (@aryanc403)
  Atcoder library - https://atcoder.github.io/ac-library/production/document_en/
*/

#ifdef ARYANC403
    #include <header.h>
#else
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
    //#pragma GCC optimize ("-ffloat-store")
    #include<bits/stdc++.h>
    #define dbg(args...) 42;
#endif

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
#define endl "\n"

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
const int logN = 19;

inline int ff(lli v){
    return min(64-__builtin_clzll(v),logN-1);
}

struct ND{
    lli mn;
    ii cur,small;
    ND():mn(INF),cur({0,0}),small({0,0}){};
    ND operator+(const ND &b){
        ND ans;
        ans.mn=min(mn,b.mn);
        ans.cur.X=cur.X+b.cur.X;
        ans.cur.Y=cur.Y+b.cur.Y;
        ans.small.X=small.X+b.small.X;
        ans.small.Y=small.Y+b.small.Y;
        return ans;
    }
};

struct Node{
    lli w,v,freq;
    int fl;
    array<ND,logN> a;
    Node():w(INF),v(0),freq(0),fl(0){};
    Node(lli _w,lli _v):w(_w),v(_v),freq(0),fl(ff(_w)){};
    Node operator+(const Node &b){
        Node ans;
        for(int i=0;i<logN;++i)
            ans.a[i]=a[i]+b.a[i];
        return ans;
    }

    void increase(lli f){
        dbg("bf",a[fl].cur,f,freq);
        a[fl].cur.X+=f*w;
        a[fl].cur.Y+=f*v;
        freq+=f;
        dbg("af",w,v,a[fl].cur,f*w,f*v,freq);
        if(freq)
            a[fl].mn=w;
        else
            a[fl].mn=INF;
        for(int i=fl+1;i<logN;++i){
            a[i].small.X+=f*w;
            a[i].small.Y+=f*v;
        }
    }

    //-1 skip and dont take anything
    //0 go down
    //1 take here
    int doesChange(lli w){
        const int gl=ff(w);
        if(a[gl].mn<=w||a[gl].small.X>=w)
            return 0;
        if(a[gl].small.X<w)
            return 1;
        return -1;
    }
    ii take(lli w){
        const int gl=ff(w);
        dbg("Hello",w,a[gl].small,gl);
        w-=a[gl].small.X;
        return {w,a[gl].small.Y};
    }
    ii takeCur(lli ww){
        lli tt=min(freq,ww/w);
        return {ww-tt*w,tt*v};
    }
};

struct SegTree{
    vector<Node> a;
    int n;
    SegTree(int _n=0):a(4*_n),n(_n){};
    map<ii,lli> dp;
    void update(int id,int l,int r,int pos,lli f){
        if(pos<l||r<pos)
            return;
        if(l==r){
            a[id].increase(f);
            return;
        }
        int m=(l+r)>>1;
        update(id<<1,l,m,pos,f);
        update((id<<1)|1,m+1,r,pos,f);
        a[id]=a[id<<1]+a[(id<<1)|1];
    }

    void update(int pos,lli f){
        dp.clear();
        return update(1,0,n-1,pos,f);
    }

    void build(vector<vi> &aa,int id,int l,int r){
        if(l==r){
            a[id]=Node(aa[l][1],aa[l][2]);
            a[id].increase(aa[l][0]);
            return;
        }
        int m=(l+r)/2;
        build(aa,2*id,l,m);
        build(aa,2*id+1,m+1,r);
        a[id]=a[2*id]+a[2*id+1];
    }

    ii run(int id,int l,int r,lli w){
        if(w==0)
            return {0,0};
        auto &cur=a[id];
        dbg(id,l,r,w);
        if(l==r){
            dbg(l,r,w);
            return cur.takeCur(w);
        }
        const auto action = cur.doesChange(w);
        dbg(id,l,r,w,action);
        if(action){
            if(action==1)
            {
                dbg(cur.take(w));
                return cur.take(w);
            }
            return {w,0};
        }
        int m=(l+r)>>1;
        lli val1=0,val2=0,w2;
        tie(w2,val1)=run(id<<1,l,m,w);
        w=w2;
        tie(w2,val2)=run((id<<1)|1,m+1,r,w);
        return {w2,val1+val2};
    }

    lli run(lli w){
        auto it=dp.upper_bound({w,INF});
        if(it!=dp.begin()){
            --it;
            if(it->X.X<=w&&w<=it->X.Y)
                return it->Y;
        }
        dbg("calc");
        ii ans=run(1,0,n-1,w);
        const lli l=w-ans.X,r=w;
        dp[{l,r}]=ans.Y;
        return ans.Y;
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
    lli q;
    cin>>n>>q;
    vector<vi> a(n,vi(3));
    for(auto &v:a)
        cin>>v[0]>>v[1]>>v[2];

    vi b(n);
    iota(all(b),0);
    sort(all(b),[&](const lli x,const lli y){
        if(a[x][2]!=a[y][2])
            return a[x][2]>a[y][2];
        return a[x][1]<a[y][1];
    });

    vi id(n);
    for(int i=0;i<n;++i)
        id[b[i]]=i;

    sort(all(a),[](const vi &a,const vi &b){
        if(a[2]!=b[2])
            return a[2]>b[2];
        return a[1]<b[1];
    });
    vector<vi> ab;
    map<ii,lli> mm;
    for(int i=0;i<n;++i){
        auto it=mm.find({a[i][1],a[i][2]});
        if(it!=mm.end()){
            ab[it->Y][0]+=a[i][0];
            continue;
        }
        mm[{a[i][1],a[i][2]}]=sz(ab);
        ab.pb(a[i]);
    }
    n=sz(ab);
    SegTree seg(n);
    seg.build(ab,1,0,n-1);
    while(q--){
        cin>>T;
        if(T==3){
            lli w;
            cin>>w;
            cout<<seg.run(w)<<endl;
            continue;
        }
        lli k,d;
        cin>>k>>d;
        d=id[d-1];
        d=mm[{a[d][1],a[d][2]}];
        if(T==2)
            k*=-1;
        dbg(d,k);
        seg.update(d,k);
    }

}   aryanc403();
    return 0;
}