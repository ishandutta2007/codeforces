///
///    "Excuse me... What did you say about my hair?!"
///
///                                    -Josuke Higashikata

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) exit((cout << (x) << '\n', 0))
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;
//#pragma GCC optimize("O0")

typedef complex<ll> fnc;
inline ll F(fnc f, ll x){return f.real()*x + f.imag();}
const ll inf = 1e18;

struct node
{
    fnc f;
    node *l, *r;
    node(fnc func)
    {
        f = func;
        l = r = 0;
    }
};

ll get(node* t, int x, int b = -100010, int e = 100010)
{
    if(b+1 == e) return F(t->f, x);
    if(x < (b+e)/2) return min(F(t->f, x), t->l? get(t->l, x, b, (b+e)/2): inf);
    else            return min(F(t->f, x), t->r? get(t->r, x, (b+e)/2, e): inf);
}

node* add(node* t, fnc f, int b = -100010, int e = 100010)
{
    int m = (b+e)/2;
    bool b1 = F(t->f, b) > F(f, b);
    bool b2 = F(t->f, m) > F(f, m);
    if(b2) swap(f, t->f);
    if(b+1 == e) return 0;
    if(b1 != b2) return t->l? add(t->l, f, b, m): t->l = new node(f);
    else         return t->r? add(t->r, f, m, e): t->r = new node(f);
}

void add(node* des, node* src)
{
    if(!src) return;
    add(des, src->f);
    add(des, src->l);
    add(des, src->r);
}

const int N = 200'010;
fnc ans[N];
vector<int> A[N];
int a[N], b[N];
int n;

pair<node*, int> dfs(int v, int p = -1)
{
    if(p != -1 && A[v].size() == 1) return {new node(ans[v] = {b[v], 0}), 1};
    node* ans = 0; int cnt = 0;
    for(int u : A[v])
    {
        if(u == p) continue;
        auto [ans2, cnt2] = dfs(u, v);
        if(cnt < cnt2) swap(ans, ans2);
        add(ans, ans2);
        cnt += cnt2;
    }
    ::ans[v] = {b[v], get(ans, a[v])};
    add(ans, ::ans[v]);
    return {ans, cnt+1};
}

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,n) cin >> a[i];
    Loop(i,0,n) cin >> b[i];
    Loop(i,1,n)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    dfs(0);
    Loop(i,0,n) cout << F(ans[i], 0) << ' ';
}