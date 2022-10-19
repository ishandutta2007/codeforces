#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O0")
using namespace std;

const int N = 100'010;

namespace seg
{
    struct node
    {
        int ans, l, r;
    }t[N << 2];

    inline node merge(node l, node r)
    {
        if(!l.ans) return r;
        if(!r.ans) return l;
        return{
        l.ans + r.ans - (l.r == r.l),
        l.l, r.r
        };
    }

    void create(int i, int *a, int b, int e)
    {
        if(b+1 == e){
            t[i].ans = 1;
            t[i].l = t[i].r = a[b];
            return;
        }
        int m = (b+e)/2;
        create(2*i+1, a, b, m);
        create(2*i+2, a, m, e);
        t[i] = merge(t[2*i+1], t[2*i+2]);
    }

    node get(int i, int l, int r, int b, int e)
    {
        if(l <= b && e <= r) return t[i];
        if(r <= b || e <= l) return {};
        return merge(get(2*i+1, l, r, b, (b+e)/2),
                     get(2*i+2, l, r, (b+e)/2, e));
    }
}

int dp1[N], dp2[N];
int a[N];
int las[N], pre[N];


int main()
{
    FAST;
    int n;
    cin >> n;
    Loop(i,0,n) cin >> a[i];
    seg::create(0, a, 0, n);
    fill(las, las+N, -1);
    Loop(i,0,n) pre[i] = las[a[i]], las[a[i]] = i;
    dp1[0] = 1; dp1[1] = 1 + (a[0] != a[1]);
    dp2[1] = 2;
    Loop(i,2,n)
    {
        if(a[i] == a[i-1])
        {
            dp1[i] = dp1[i-1];
            dp2[i] = dp1[i-1]+1; if(pre[i-1] != -1) dp2[i] = min(dp2[i], dp2[pre[i-1]+1] + seg::get(0, pre[i-1]+1, i, 0, n).ans - 1);
        }
        else
        {
            dp1[i] = dp1[i-1]+1;
            if(pre[i] != -1) dp1[i] = min(dp1[i], dp2[pre[i]+1] + seg::get(0, pre[i]+1, i, 0, n).ans - 1);
            dp2[i] = dp1[i-1]+1;
            if(pre[i] != -1) dp2[i] = min(dp2[i], dp2[pre[i]+1] + seg::get(0, pre[i]+1, i, 0, n).ans - 1);
        }
    }
    cout << dp1[n-1] << '\n';
}