#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const int N = 1'000'010;

namespace fen
{
    int a[N] = {};

    int get(int i)
    {
        int ans = 0;
        ++i;
        while(i < N)
        {
            ans += a[i];
            i += i & (-i);
        }
        return ans;
    }

    void add(int i, int x)
    {
        ++i;
        while(i > 0)
        {
            a[i] += x;
            i -= i & (-i);
        }
    }
}

namespace Aho
{
    struct node
    {
        int8_t c;
        int child[26]; bitset<26> has;
        int f = -1;
        int st, ft;
    };
    node empty;
    vector<node> trie(1);
    vector<int> fp[N];
    int next = 1;

    int add_string(const char* s)
    {
        int t = 0;
        for(int i = 0; s[i]; ++i)
        {
            if(!trie[t].has[s[i]-'a'])
            {
                trie[t].child[s[i]-'a'] = trie.size();
                trie[t].has[s[i]-'a'] = 1;
                trie.push_back(empty);
                trie.back().c = s[i]-'a';
            }
            t = trie[t].child[s[i]-'a'];
        }
        return t;
    }

    void calc_f()
    {
        queue<pii> Q;
        Loop(i,0,26)
        {
            if(trie[0].child[i])
                Q.push({trie[0].child[i], 0});
        }
        while(Q.size())
        {
            auto u = Q.front().F;
            auto p = Q.front().S; Q.pop();

            int f = trie[p].f;
            while(f >= 0 && !trie[f].has[trie[u].c])
                f = trie[f].f;
            if(f < 0)
                trie[u].f = 0;
            else
                trie[u].f = trie[f].child[trie[u].c];

            fp[trie[u].f].push_back(u);
            Loop(i,0,26)
            {
                if(trie[u].child[i])
                    Q.push({trie[u].child[i], u});
            }
        }
    }

    void dfs(int u = 0, int* t = new int{})
    {
        trie[u].st = (*t)++;
        for(auto v : fp[u])
            dfs(v, t);
        trie[u].ft = *t;
    }

    void print(int t, string& s)
    {
        cout << s << ": " << t << '\n';
        Loop(i,0,26)
        {
            if(trie[t].child[i])
                s.push_back(i+'a'),
                print(trie[t].child[i], s),
                s.pop_back();
        }
    }
}

void include(int u)
{
    fen::add(Aho::trie[u].ft-1, 1);
    fen::add(Aho::trie[u].st-1, -1);
}
void exclude(int u)
{
    fen::add(Aho::trie[u].ft-1, -1);
    fen::add(Aho::trie[u].st-1, 1);
}

ll query(const char* c)
{
    int f = 0;
    ll ans = 0;
    for(int i = 0; c[i]; ++i)
    {
        while(f >= 0 && !Aho::trie[f].has[c[i]-'a'])
            f = Aho::trie[f].f;
        if(f < 0)
            f = 0;
        else
            f = Aho::trie[f].child[c[i]-'a'];

        ans += fen::get(Aho::trie[f].st);
    }
    return ans;
}

struct citizen
{
    int node;
    bool st;
};
vector<citizen> a;
string s;

int main()
{
    FAST;
    int n, q;
    cin >> q >> n;
    Loop(i,0,n)
    {
        cin >> s;
        //s = "";
        //Loop(i,0,1'000'000)
        //    s.push_back('a');
        a.push_back({Aho::add_string(s.c_str()), 0});
    }
    //s = "";
    //Aho::print(0, s);
    Aho::calc_f();
    Aho::dfs();
    for(auto& c : a)
        include(c.node),
        c.st = 1;
    while(q--)
    {
        cin >> s;
        char t = s[0];
        Loop(i,0,s.size()-1)
            s[i] = s[i+1];
        s.pop_back();
        int k;
        switch(t)
        {
            case '-': k = stoi(s)-1; if(a[k].st){exclude(a[k].node); a[k].st=0;} break;
            case '+': k = stoi(s)-1; if(!a[k].st){include(a[k].node); a[k].st=1;} break;
            case '?': cout << query(s.c_str()) << '\n'; break;
        }
    }
}