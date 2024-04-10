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

const int N = 200'010;
int n;

struct node
{
    int cnt;
    node *l = 0, *r = 0;
    node(int x){cnt = x;}
    node(node* a, node* b){l=a;r=b;cnt=l->cnt+r->cnt;}
};

node* init(int b=0, int e=n)
{
    if(e-b == 1) return new node(0);
    return new node(init(b,(b+e)/2),init((b+e)/2,e));
}

ll get(node* t1, node* t2, int l, int r, int b=0, int e=n)
{
    if(l <= b && e <= r) return t2->cnt - t1->cnt;
    if(r <= b || e <= l) return 0;
    return get(t1->l,t2->l,l,r,b,(b+e)/2)+get(t1->r,t2->r,l,r,(b+e)/2,e);
}

node* add(node* t, int p, int b=0, int e=n)
{
    if(e-b==1) return new node(t->cnt+1);
    if(p<(b+e)/2) return new node(add(t->l,p,b,(b+e)/2),t->r);
    else          return new node(t->l,add(t->r,p,(b+e)/2,e));
}

node* t[N];
int a[N];

int main()
{
    FAST;
    int q;
    cin >> n >> q;
    t[0] = init();
    Loop(i,0,n)
    {
        cin >> a[i]; --a[i];
        t[i+1] = add(t[i], a[i]);
    }
    while(q--)
    {
        int l, d, r, u;
        cin >> l >> d >> r >> u;
        --l; --d;
        ll bad = get(t[l],t[r],d,u);
        ll ans = 0;
        ans += get(t[0],t[r],0,u)*get(t[l],t[n],d,n) - bad;
        //ans -= get(t[l],t[r],0,u)*get(t[l],t[r],d,n) - bad;
        ans += get(t[0],t[r],d,n)*get(t[l],t[n],0,u) - bad;
        ans -= get(t[l],t[r],d,n)*get(t[l],t[r],0,u) - bad;
        ll tmp = get(t[0],t[r],d,u)*get(t[l],t[n],d,u) - bad;
        tmp -= (bad*bad - bad)/2;
        ans -= tmp;
        cout << ans << '\n';
    }
}