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
//#pragma GCC optimize ("Ofast")
using namespace std;

const int N = 2e5 + 10;

namespace seg
{
    struct node
    {
        int mn, mx;
        int v;
    }t[N<<2];

    node merge(node a, node b)
    {
        node ans;
        ans.mn = min(a.mn, a.v + b.mn);
        ans.mx = max(a.mx, a.v + b.mx);
        ans.v = a.v + b.v;
        return ans;
    }

    void init(int i, string& s, int b, int e)
    {
        if(b+1 == e){
            t[i].v = s[b] == '+'? 1: -1;
            t[i].mn = min(t[i].v, 0);
            t[i].mx = max(t[i].v, 0);
            return;
        }
        init(2*i+1, s, b, (b+e)/2);
        init(2*i+2, s, (b+e)/2, e);
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

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
    {
        int n, q;
        string s;
        cin >> n >> q >> s;
        seg::init(0, s, 0, n);
        while(q--)
        {
            int l, r;
            cin >> l >> r; l--;
            auto tmp = merge(seg::get(0, 0, l, 0, n), seg::get(0, r, n, 0, n));
            cout << tmp.mx - tmp.mn + 1 << '\n';
        }
    }
}