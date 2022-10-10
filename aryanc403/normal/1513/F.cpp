/* in the name of Anton */

/*
  Compete against Yourself.
  Author - Aryan (@aryanc403)
  Atcoder library - https://atcoder.github.io/ac-library/production/document_en/
*/

#include <algorithm>
#include <cassert>
#include <vector>


#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    segtree(int n) : segtree(std::vector<S>(n, e())) {}
    segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder

#ifdef ARYANC403
    #include <header.h>
#else
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
    #pragma GCC optimize ("-ffloat-store")
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
// const lli maxN = 1000000007L;
using node = array<lli,2>;
node op(node a, node b) {
    for(int i=0;i<2;++i)
        a[i]=min(a[i],b[i]);
    return a;
}

node ee() { return {INF,INF}; }

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vii a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli bf(){
    lli ans=INF;
    for(auto x:a)
    for(auto y:a){
        ans=min(ans,abs(x.X-y.Y)+abs(x.Y-y.X)-abs(x.X-y.X)-abs(x.Y-y.Y));
    }
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;
    a.resize(n);
    for(auto &x:a)
        cin>>x.X;
    for(auto &x:a)
        cin>>x.Y;
    dbg(bf());

    vi b;
    b.pb(-INF);b.pb(INF);
    for(auto x:a)
    {
        b.pb(x.X);
        b.pb(x.Y);
    }

    sort(all(b));
    b.erase(unique(all(b)),b.end());

    auto getIdx=[&](lli x){
        return lower_bound(all(b),x)-b.begin();
    };

    const lli m=sz(b);
    vii qur=a;

    for(auto &x:qur)
        swap(x.X,x.Y);

    sort(all(qur));
    sort(all(a));

    atcoder::segtree<node, op, ee> seg(m);

    lli i=0,ans=0;
    for(auto yy:qur){
        while(i<n&&a[i].X<=yy.X){
            const auto xx=a[i];
            const lli pos=getIdx(xx.Y);
            auto cur=seg.get(pos);
            cur[0]=min(cur[0],-xx.X-xx.Y-abs(xx.X-xx.Y));
            cur[1]=min(cur[1],-xx.X+xx.Y-abs(xx.X-xx.Y));
            seg.set(pos,cur);
            i++;
        }

        {
            const lli pos=getIdx(yy.Y);
            auto cur=seg.prod(0,pos+1);
            ans=min(ans,cur[0]+yy.X+yy.Y-abs(yy.X-yy.Y));
            cur=seg.prod(pos,m);
            ans=min(ans,cur[1]+yy.X-yy.Y-abs(yy.X-yy.Y));
        }
    }
    dbg("1",ans);
    reverse(all(a));
    reverse(all(qur));
    i=0;
    seg=atcoder::segtree<node, op, ee>(m);
    for(auto yy:qur){
        while(i<n&&a[i].X>=yy.X){
            const auto xx=a[i];
            const lli pos=getIdx(xx.Y);
            auto cur=seg.get(pos);
            cur[0]=min(cur[0],+xx.X-xx.Y-abs(xx.X-xx.Y));
            cur[1]=min(cur[1],+xx.X+xx.Y-abs(xx.X-xx.Y));
            seg.set(pos,cur);
            i++;
        }

        {
            const lli pos=getIdx(yy.Y);
            auto cur=seg.prod(0,pos+1);
            ans=min(ans,cur[0]-yy.X+yy.Y-abs(yy.X-yy.Y));
            cur=seg.prod(pos,m);
            ans=min(ans,cur[1]-yy.X-yy.Y-abs(yy.X-yy.Y));
        }
    }

    dbg("2",ans);
    for(auto x:a)
        ans+=abs(x.X-x.Y);
    cout<<ans<<endl;

}   aryanc403();
    return 0;
}