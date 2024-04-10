///
///    I have a dream and a piano
///

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

const int N = 100'010;
vector<int> p[N];
int a[N], b[N];
int n, k;

struct node
{
    int cnt=0;
    node *l=0, *r=0;
    node(){}
    node(int x){cnt=x;}
    node(node* a, node* b){l=a;r=b;cnt=l->cnt+r->cnt;}
};

node* init(int b=-1, int e=N)
{
    if(e-b==1) return new node;
    return new node(init(b,(b+e)/2), init((b+e)/2,e));
}

node* add(node* t, int p, int b=-1, int e=N)
{
    if(e-b==1) return new node(t->cnt+1);
    if(p < (b+e)/2) return new node(add(t->l,p,b,(b+e)/2),t->r);
    else            return new node(t->l,add(t->r,p,(b+e)/2,e));
}

int get(node* t, int l, int r, int b=-1, int e=N)
{
    if(l <= b && e <= r) return t->cnt;
    if(r <= b || e <= l) return 0;
    return get(t->l,l,r,b,(b+e)/2)+get(t->r,l,r,(b+e)/2,e);
}

node* rt[N];

int main()
{
    FAST;
    cin >> n >> k;
    Loop(i,0,n)
        cin >> a[i],
        b[i] = p[a[i]].size() < k? -1: *(p[a[i]].end()-k),
        p[a[i]].push_back(i);
    rt[0] = init();
    Loop(i,0,n) rt[i+1] = add(rt[i], b[i]);
    int q;
    cin >> q;
    int lst = 0;
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        l = (l+lst)%n;
        r = (r+lst)%n;
        if(l>r) swap(l,r);
        ++r;
        cout << (lst = get(rt[r],-1,l)-get(rt[l],-1,l)) << '\n';
    }
}