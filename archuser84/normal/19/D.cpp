#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll int64_t
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O0")
using namespace std;

namespace seg
{
    struct node{
        int mx = -1;
        int l=0, r=0;
    };
    vector<node> t(1);
    map<int, set<int>> M;

    inline int lc(int i){if(!t[i].l) {t[i].l = t.size(); t.emplace_back();} return t[i].l;}
    inline int rc(int i){if(!t[i].r) {t[i].r = t.size(); t.emplace_back();} return t[i].r;}

    void add(int x, int y, int i = 0, int b = 0, int e = 1e9 + 10)
    {
        if(b+1 == e)
        {
            M[i].insert(y);
            t[i].mx = M[i].size()? *(--M[i].end()): -1;
            return;
        }
        int m = (b+e)/2;
        if(x < m) add(x, y, lc(i), b, m);
        else      add(x, y, rc(i), m, e);
        t[i].mx = max(t[i].l? t[t[i].l].mx: -1, t[i].r? t[t[i].r].mx: -1);
    }
    void rem(int x, int y, int i = 0, int b = 0, int e = 1e9 + 10)
    {
        if(b+1 == e)
        {
            M[i].erase(y);
            t[i].mx = M[i].size()? *(--M[i].end()): -1;
            return;
        }
        int m = (b+e)/2;
        if(x < m) rem(x, y, lc(i), b, m);
        else      rem(x, y, rc(i), m, e);
        t[i].mx = max(t[i].l? t[t[i].l].mx: -1, t[i].r? t[t[i].r].mx: -1);
    }

    pii find(int x, int y, int i = 0, int b = 0, int e = 1e9 + 10)
    {
        if(b+1 == e) return {b, *M[i].upper_bound(y)};
        int m = (b+e)/2;
        pii ans = {-1, -1};
        if(x+1 < m     && t[lc(i)].mx > y) ans = find(x, y, lc(i), b, m);
        if(ans.F == -1 && t[rc(i)].mx > y) ans = find(x, y, rc(i), m, e);
        return ans;
    }
};

int main()
{
    FAST;
    int q;
    cin >> q;
    map<int, set<int>> S;
    while(q--)
    {
        string t; int a, b;
        cin >> t >> a >> b;
        //t = rand()&1? "a": "r"; a = rand(); b = rand();
        switch(t[0])
        {
        case 'a':
            seg::add(a, b);
            break;
        case 'r':
            seg::rem(a, b);
            break;
        case 'f':
            auto ans = seg::find(a, b);
            if(ans.F == -1) cout << "-1\n";
            else            cout << ans.F << ' ' << ans.S << '\n';
            break;
        }
    }
}