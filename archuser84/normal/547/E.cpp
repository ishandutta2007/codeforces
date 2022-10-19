///
///    "I, Giorno Giovanna, have a dream."
///
///                                    -Giorno Giovanna

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;
//#pragma GCC optimize ("O0")

struct node
{
    node *f = 0, *p = 0;
    node *c[26] = {}, *n[26] = {};
    char e;
    vector<node*> dt = {};
    int st, ft;
} rt;

ostream& operator<<(ostream& out, node* t)
{
    string ans;
    while(t != &rt)
    {
        ans.push_back(t->e+'a');
        t = t->p;
    }
    reverse(all(ans));
    out << ans;
    return out;
}

node* addstr(const string& s)
{
    node* t = &rt;
    for(char c : s)
    {
        c -= 'a';
        if(!t->c[c]) {t->c[c] = new node; t->c[c]->p = t; t->c[c]->e = c;}
        t = t->c[c];
    }
    return t;
}

void aho()
{
    rt.f = 0;
    Loop(i,0,26) rt.n[i] = rt.c[i]? rt.c[i]: &rt;
    Loop(i,0,26) if(rt.c[i]) rt.c[i]->f = &rt, rt.dt.push_back(rt.c[i]);
    Loop(i,0,26) Loop(j,0,26) if(rt.c[i]) rt.c[i]->n[j] = rt.c[i]->c[j]? rt.c[i]->c[j]: rt.n[j];
    queue<node*> q; Loop(i,0,26) Loop(j,0,26) if(rt.c[i] && rt.c[i]->c[j]) q.push(rt.c[i]->c[j]);
    while(q.size())
    {
        node* t = q.front(); q.pop();
        t->f = t->p->f->n[t->e];
        t->f->dt.push_back(t);
        //cerr << "F(" << t << ") = " << t->f << '\n';
        Loop(i,0,26) t->n[i] = t->c[i]? t->c[i]: t->f->n[i];
        Loop(i,0,26) if(t->c[i]) q.push(t->c[i]);
    }
}

void dfs(node* u, int& t = *new int(0))
{
    //cerr << u << '\n';
    u->st = t++;
    for(node* v : u->dt) dfs(v, t);
    u->ft = t;
}

struct seg
{
    int cnt;
    seg *l, *r;
    seg(int x){cnt = x; l = r = 0;}
    seg(seg* a, seg* b){l = a; r = b; cnt = a->cnt + b->cnt;}
};

seg* build(int b, int e)
{
    if(b+1 == e) return new seg(0);
    return new seg(build(b, (b+e)/2), build((b+e)/2, e));
}

int get(seg* t, int l, int r, int b, int e)
{
    if(l <= b && e <= r) return t->cnt;
    if(e <= l || r <= b) return 0;
    return get(t->l, l, r, b, (b+e)/2) + get(t->r, l, r, (b+e)/2, e);
}

seg* add(seg* t, int p, int b, int e)
{
    if(b+1 == e) return new seg(t->cnt + 1);
    if(p < (b+e)/2) return new seg(add(t->l, p, b, (b+e)/2), t->r);
    else            return new seg(t->l, add(t->r, p, (b+e)/2, e));
}

const int N = 200'010;
node* s[N];
seg* t[N];
int n, q;

int main()
{
    FAST;
    int n, q;
    cin >> n >> q;
    Loop(i,0,n)
    {
        string s;
        cin >> s;
        ::s[i] = addstr(s);
    }
    aho();
    dfs(&rt);
    t[0] = build(0, N);
    Loop(i,0,n)
    {
        node* u = s[i];
        t[i+1] = t[i];
        while(u)
        {
            //cerr << u << '\n';
            t[i+1] = add(t[i+1], u->st, 0, N);
            u = u->p;
        }
    }
    while(q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        l--; k--;
        int ans = get(t[r], s[k]->st, s[k]->ft, 0, N);
        ans -=    get(t[l], s[k]->st, s[k]->ft, 0, N);
        cout << ans << '\n';
    }
}