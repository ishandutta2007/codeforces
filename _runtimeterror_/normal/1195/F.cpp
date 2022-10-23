#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll>
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2401
#endif

template<typename T = long long>
struct Point
{
    T x,y;
    Point() : x(0),y(0) {}
    Point(T x_,T y_): x(x_),y(y_) {}
    friend Point operator-(const Point &a, const Point &b) { return Point(a.x-b.x,a.y-b.y); }
    friend Point operator+(const Point &a, const Point &b) { return Point(a.x+b.x,a.y+b.y); }
    friend ostream& operator << (ostream &stream, const Point &P) { return stream<<"("<<P.x<<","<<P.y<<")"; }
    long long abs() { return x*x + y*y; }
};
template<typename T>
T dot(const Point<T> &a,const Point<T> &b)
{
    return a.x*b.x+a.y*b.y;
}
template<typename T>
T cross(const Point<T> &a,const Point<T> &b)
{
    return a.x*b.y-b.x*a.y;
}
using Pt = Point<ll> ;
struct AngCmp
{
    // centred at origin and anticlockwise relative to V;
    Pt origin,V;
    AngCmp(Pt a,Pt b): origin(a),V(b) {}

    bool operator() (const Pt &a,const Pt &b) const
    {
        Pt A = a-origin;
        Pt B = b-origin;

        bool x = cross(V,A)>=0;
        bool y = cross(V,B)>=0;
        if(x^y)
            return x;
        ll u = cross(A,B);
        if(u != 0)
            return u > 0;
        ll ux = dot(A,B);
        ll vx = dot(A,V);
        if(ux < 0)
            return vx > 0;
        // change here for same polar angle
        return A.abs()>B.abs();
    }
};

// AngCmp cmp(Pt(0,0),Pt(1,0)) <-- Like this

template<typename T=long long>
struct fenwick {
    vector<T> bit;
    int n;
    fenwick(int x) {
        n = x;
        bit.resize(x + 1, T(0));
    }
    void update(int j,T val)
    {
        for(;j<=n;j+=j&-j)
            bit[j] += val;
    }
    T get(int r)
    {
        T u = 0;
        for(;r;r-=r&-r)
            u += bit[r]; 
        return u;
    }
    T query(int l,int r)
    {
        return get(r)-get(l-1);
    }
    // kth element
    int getKth(T k) {
        int ans = 0;
        T cnt = 0;
        for(int i=20;i>=0;--i) {
            if(ans + (1 << i) <= n && cnt + bit[ans + (1 << i)] < k) {
                ans += (1 << i);
                cnt += bit[ans];
            }
        }
        if(ans == n) {
            return -1;
        }
        return ans + 1;
    }
    void insert(int x) {
        update(x, 1);
    }
    void erase(int x) {
        update(x, -1);
    }
};


int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<vector<int>> slps(n + 1);
    vector<vector<Pt>> poly(n+1);

    vector<Pt> cmp;
    for(int i=1;i<=n;++i) {
        int k;
        cin >> k;
        poly[i].resize(k);
        for(int j=0;j<k;++j) {
            cin >> poly[i][j].x >> poly[i][j].y;
        }
        vector<Pt> edges;
        for(int j=0;j<k;++j) {
            edges.push_back(poly[i][(j+1)%k] - poly[i][j]);
            cmp.push_back(edges.back());
        }
        poly[i] = edges;
    }
    sort(all(cmp), AngCmp(Pt(0, 0), Pt(1, 0)));
    int cur = 1;
    map<pii, int> id;
    for(int i=0;i<sz(cmp);++i) {
        int j = i;
        while(j < sz(cmp) && dot(cmp[i], cmp[j]) > 0 and cross(cmp[i], cmp[j]) == 0) {
            id[{cmp[j].x, cmp[j].y}] = cur;
            ++j;
        }
        ++cur;
        i = j - 1;
    }
    for(int i=1;i<=n;++i) {
        for(auto &j:poly[i]) {
            slps[i].push_back(id[{j.x, j.y}]);
        }
    }
    int Q;
    cin >> Q;
    vector<vector<array<int,2>>> queries(n+1);
    vector<int> ans(Q);
    for(int i=1;i<=Q;++i) {
        int l, r;
        cin >> l >> r;
        queries[r].push_back({l, i - 1});
    }
    map<int,int> last;
    fenwick<int> fenw(3e5);
    for(int i=1;i<=n;++i) {
        for(auto &j:slps[i]) {
            if(last.count(j)) {
                fenw.update(last[j], -1);
            }
            last[j] = i;
            fenw.update(last[j], 1);
        }
        for(auto &[l, id]:queries[i]) {
            ans[id] = fenw.query(l, i);
        }
    }
    for(auto i:ans) {
        cout << i << "\n";
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}