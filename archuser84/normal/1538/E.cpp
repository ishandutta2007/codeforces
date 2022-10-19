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

struct node
{
    ll ans;
    string pre, suf;
    node *l, *r;
    node(string s)
    {
        l = r = 0;
        pre = suf = s;
        reverse(all(suf));
        if(pre.size() > 3) pre.resize(3);
        if(suf.size() > 3) suf.resize(3);
        reverse(all(suf));
        ans = 0;
        Loop(i,0,ll(s.size())-3)
            if(s[i+0] == 'h' && s[i+1] == 'a' && s[i+2] == 'h' && s[i+3] == 'a')
                ++ans;
    }
    node(node* a, node* b)
    {
        l = a; r = b;
        pre = a->pre + b->pre;
        suf = a->suf + b->suf;
        reverse(all(suf));
        if(pre.size() > 3) pre.resize(3);
        if(suf.size() > 3) suf.resize(3);
        reverse(all(suf));
        ans = a->ans + b->ans;
        auto s = a->suf + b->pre;
        Loop(i,0,ll(s.size())-3)
            if(s[i+0] == 'h' && s[i+1] == 'a' && s[i+2] == 'h' && s[i+3] == 'a')
                ++ans;
    }
};

map<string, node*> m;

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string var;
        while(n--)
        {
            string op;
            cin >> var >> op;
            if(op[0] == ':')
            {
                string val;
                cin >> val;
                m[var] = new node(val);
            }
            if(op[0] == '=')
            {
                string a, b, _;
                cin >> a >> _ >> b;
                m[var] = new node(m[a], m[b]);
            }
        }
        cout << m[var]->ans << '\n';
    }
}