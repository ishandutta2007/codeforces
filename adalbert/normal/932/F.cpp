#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=5e5+100;const ll is_query = -(1LL<<62);

const int MAX = 1e5 + 10;
class ConvexHullDynamic
{
    typedef long long coef_t;
    typedef long long coord_t;
    typedef long long val_t;

    /*
     * Line 'y=a*x+b' represented by 2 coefficients 'a' and 'b'
     * and 'xLeft' which is intersection with previous line in hull(first line has -INF)
     */
private:
    struct Line
    {
        coef_t a, b;
        double xLeft;

        enum Type {line, maxQuery, minQuery} type;
        coord_t val;

        explicit Line(coef_t aa=0, coef_t bb=0) : a(aa), b(bb), xLeft(-INFINITY), type(Type::line), val(0) {}
        val_t valueAt(coord_t x) const { return a*x+b; }
        friend bool areParallel(const Line& l1, const Line& l2) { return l1.a==l2.a; }
        friend double intersectX(const Line& l1, const Line& l2) { return areParallel(l1,l2)?INFINITY:1.0*(l2.b-l1.b)/(l1.a-l2.a); }
        bool operator<(const Line& l2) const
        {
            if (l2.type == line)
                return this->a     < l2.a;
            if (l2.type == maxQuery)
                return this->xLeft < l2.val;
            if (l2.type == minQuery)
                return this->xLeft > l2.val;
            return false;
        }
    };

private:
    bool            isMax; //whether or not saved envelope is top(search of max value)
    std::set<Line>  hull;  //envelope itself

private:
    /*
     * INFO:        Check position in hull by iterator
     * COMPLEXITY:  O(1)
     */
    bool hasPrev(std::set<Line>::iterator it) { return it!=hull.begin(); }
    bool hasNext(std::set<Line>::iterator it) { return it!=hull.end() && std::next(it)!=hull.end(); }

    /*
     * INFO:        Check whether line l2 is irrelevant
     * NOTE:        Following positioning in hull must be true
     *              l1 is next left to l2
     *              l2 is right between l1 and l3
     *              l3 is next right to l2
     * COMPLEXITY:  O(1)
     */
    bool irrelevant(const Line& l1, const Line& l2, const Line& l3) { return intersectX(l1,l3) <= intersectX(l1,l2); }
    bool irrelevant(std::set<Line>::iterator it)
    {
        return hasPrev(it) && hasNext(it)
        && (    isMax && irrelevant(*std::prev(it), *it, *std::next(it))
            || !isMax && irrelevant(*std::next(it), *it, *std::prev(it)) );
    }

    /*
     * INFO:        Updates 'xValue' of line pointed by iterator 'it'
     * COMPLEXITY:  O(1)
     */
    std::set<Line>::iterator updateLeftBorder(std::set<Line>::iterator it)
    {
        if (isMax && !hasPrev(it) || !isMax && !hasNext(it))
            return it;

        double val = intersectX(*it, isMax?*std::prev(it):*std::next(it));
        Line buf(*it);
        it = hull.erase(it);
        buf.xLeft = val;
        it = hull.insert(it, buf);
        return it;
    }

public:
    explicit ConvexHullDynamic(bool isMax): isMax(isMax) {}

    /*
     * INFO:        Adding line to the envelope
     *              Line is of type 'y=a*x+b' represented by 2 coefficients 'a' and 'b'
     * COMPLEXITY:  Adding N lines(N calls of function) takes O(N*log N) time
     */
    void addLine(coef_t a, coef_t b)
    {
        //find the place where line will be inserted in set
        Line l3 = Line(a, b);
        auto it = hull.lower_bound(l3);

        //if parallel line is already in set, one of them becomes irrelevant
        if (it!=hull.end() && areParallel(*it, l3))
        {
            if (isMax && it->b < b || !isMax && it->b > b)
                it = hull.erase(it);
            else
                return;
        }

        //try to insert
        it = hull.insert(it, l3);
        if (irrelevant(it)) { hull.erase(it); return; }

        //remove lines which became irrelevant after inserting line
        while (hasPrev(it) && irrelevant(std::prev(it))) hull.erase(std::prev(it));
        while (hasNext(it) && irrelevant(std::next(it))) hull.erase(std::next(it));

        //refresh 'xLine'
        it = updateLeftBorder(it);
        if (hasPrev(it))
            updateLeftBorder(std::prev(it));
        if (hasNext(it))
            updateLeftBorder(std::next(it));
    }
    /*
     * INFO:        Query, which returns max/min(depends on hull type - see more info above) value in point with abscissa 'x'
     * COMPLEXITY:  O(log N), N-amount of lines in hull
     */
    val_t getBest(coord_t x) const
    {
        Line q;
        q.val = x;
        q.type = isMax ? Line::Type::maxQuery : Line::Type::minQuery;

        auto bestLine = hull.lower_bound(q);
        if (isMax) --bestLine;
        return bestLine->valueAt(x);
    }

    ConvexHullDynamic()
    {

    }
};


ConvexHullDynamic v[4*arr];

vector<int> vec[arr];

int ans[arr],a[arr],b[arr],in[arr],out[arr];
int cnt;
int getmin(int i, int tl, int tr, int l, int r, int x)
{
    if (tl>=l && tr<=r)
        return(v[i].getBest(x));
    if (tl>r || tr<l)
        return(1e18);

    int d=(tl+tr)/2;

    return(min(getmin(i*2,tl,d,l,r,x),getmin(i*2+1,d+1,tr,l,r,x)));
}


    int n;

void change(int i, int tl, int tr, int x, int a, int b)
{
    v[i].addLine(a,b);
    if (tl==tr)
        return;
    int d=(tl+tr)/2;

    if (x<=d)
        change(i*2,tl,d,x,a,b); else
        change(i*2+1,d+1,tr,x,a,b);
}

void solve(int u, int pred)
{
    in[u]=++cnt;
    bool ch=1;
    for (auto i:vec[u])
        if (i!=pred)
        solve(i,u),ch=0;

    out[u]=cnt;
    if (ch && pred!=0)
        ans[u]=0; else
    {
        ans[u]=getmin(1,1,n,in[u]+1,out[u],a[u]);
    }

    change(1,1,n,in[u],b[u],ans[u]);
}

signed main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];

    for (int i=1;i<=n;i++)
        cin>>b[i];

    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        vec[u].pb(v);
        vec[v].pb(u);
    }

    solve(1,0);

    for (int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
}
/*
7
1 1 3
1 2 3
2 3 4
1 2 0
1 5 3
2 5 5
2 7 22
*/