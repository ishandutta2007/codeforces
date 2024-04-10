#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
int MOD = 1e9 + 7;
const ld E = 1e-9;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#ifndef LONG_LONG_MAX
#define LONG_LONG_MAX LLONG_MAX
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".DAT"); _write(x ".SOL")
#define output _write("output.txt")
#define input _read("input.txt")
#ifndef M_PI
#define M_PI acos(-1)
#endif
#define remove tipa_remove
#define left tipa_left
#define right tipa_right
#define y1 hello_world
unsigned char ccc;
bool _minus = false;
template<typename T>
inline T sqr(T t) {
    return (t * t);
}
inline void read(ll &n) {
    n = 0;
    _minus = false;
    while (true) {
        ccc = getchar();
        if (ccc == ' ' || ccc == '\n')
            break;
        if (ccc == '-') {
            _minus = true;
            continue;
        }
        n = n * 10 + ccc - '0';
    }
    if (_minus)
        n *= -1;
}
inline bool read(int &n) {
    n = 0;
    _minus = false;
    while (true) {
        ccc = getchar();
        if (ccc == ' ' || ccc == '\n') {
            if (ccc == '\n')
                return true;
            break;
        }
        if (ccc == '-') {
            _minus = true;
            continue;
        }
        n = n * 10 + ccc - '0';
    }
    if (_minus)
        n *= -1;
    return false;
}
char wwww[19];
int kkkk;
inline void write(ll y) {
    long long x = y;
    kkkk = 0;
    if (x < 0) {
        putchar('-');
        x *= -1;
    }
    if (!x){
        ++kkkk; wwww[kkkk] = '0';
    }else
        while (x) {
            ++kkkk;
            wwww[kkkk] = char(x % 10 + '0');
            x /= 10;
        }
    for (int i = kkkk; i >= 1; --i)
        putchar(wwww[i]);
}
#ifdef LOCAL
//#define __DEBUG
#endif
#ifdef __DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif
#define int ll
const ll is_query = -(1LL<<62);

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
};

vector<ConvexHullDynamic> t;

int ind[MAX];
ll a[MAX], b[MAX];
int n;
int down[MAX];
vector<int> vec[MAX];
ll ans[MAX];
int p[MAX];

ll dp[MAX];

void add(int pos, int a, int prev = 0){
    t[a].addLine(b[pos], ans[pos]);
    for(int b : vec[pos]){
        if(b != prev){
            add(b, a, pos);
        }
    }
}

void dfs(int pos, int prev = 0){
    p[pos] = prev;
    dp[pos] = 1e18;
    down[pos] = 1;
    if(prev != 0 && (int) vec[pos].size() == 1){
        ans[pos] = 0;
        ind[pos] = pos;
        dp[pos] = 0;
        t[pos].addLine(b[pos], 0);
        int v = pos;
        if(0)
        while(p[v]){
            v = p[v];
            dp[v] = min(dp[v], a[v] * b[pos]);
        }
        return;
    }
    vector<pair<int, int> > v;
    for(int a : vec[pos]){
        if(a != prev){
            dfs(a, pos);
            v.push_back(make_pair(down[a], a));
            down[pos] += down[a];
        }
    }
    sort(v.rbegin(), v.rend());
    ind[pos] = ind[v[0].second];
    for(int i = 1; i < (int) v.size(); i++){
        add(v[i].second, ind[pos], pos);
    }
    ans[pos] = (t[ind[pos]].getBest(a[pos]));
    t[ind[pos]].addLine(b[pos], ans[pos]);
    int vv = pos;
    if(0)
    while(p[vv]){
        vv = p[vv];
        dp[vv] = min(dp[vv], a[vv] * b[pos] + ans[pos]);
    }
}
#undef int

int main() {
    sync;
    srand((unsigned int) time(NULL));
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL
    input;
    output;
#else
    
#endif
    
    cin >> n;
    
    for(int i = 0; i <= n; i++){
        t.push_back(ConvexHullDynamic(false));
    }
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    
    dfs(1);
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    
#ifdef LOCAL
    cout << "---------- " << clock() << endl;
#endif
    
}