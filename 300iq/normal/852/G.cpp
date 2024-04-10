//#define _GLIBCXX_DEBUG
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

#define mk make_pair
#define inb push_back
#define X first
#define Y second
#define all(v) v.begin(), v.end()
#define sqr(x) (x) * (x)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC
#define y1 AYDARBOG
//continue break pop_back return

int solve();

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
#define TASK "lzss"
#ifndef _DEBUG
    //freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
#endif
    solve();
#ifdef _DEBUG
    fprintf(stderr, "\nTIME: %.3f\n", TIME);
#endif
}

const int BUFSZ = (int)1e5 + 7;
char buf[BUFSZ];
string get_str()
{
    scanf(" %s", buf);
    return string(buf);
}

struct Node
{
    vi nxt;
    int t;
    Node() { nxt.assign(5, -1), t = 0; };
};

struct Trie
{
    vi was;
    int it;
    vector<Node> t;
    Trie() { t.inb(Node()), was.inb(0), it = 0; };
    void add(string &s)
    {
        int u = 0;
        for (size_t i = 0; i < s.size(); ++i)
        {
            if (t[u].nxt[s[i] - 'a'] == -1)
            {
                t[u].nxt[s[i] - 'a'] = t.size();
                t.inb(Node());
                was.inb(0);
            }
            u = t[u].nxt[s[i] - 'a'];
        }
        ++t[u].t;
    }
    int get(string &s)
    {
        queue<int> q;
        q.push(0);
        for (size_t c = 0; c < s.size(); ++c)
        {
            int sz = q.size();
            for (int i = 0; i < sz; ++i)
            {
                int u = q.front();
                q.pop();
                if (s[c] != '?')
                {
                    if (t[u].nxt[s[c] - 'a'] != -1)
                    {
                        q.push(t[u].nxt[s[c] - 'a']);
                    }
                }
                else
                {
                    q.push(u);
                    for (int i = 0; i < 5; ++i)
                    {
                        if (t[u].nxt[i] != -1)
                        {
                            q.push(t[u].nxt[i]);
                        }
                    }
                }
            }
        }
        int ans = 0;
        ++it;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (was[u] != it)
            {
                ans += t[u].t;
                was[u] = it;
            }
        }
        return ans;
    }
};

int solve()
{
    int n, q;
    scanf("%d %d", &n, &q);
    Trie T;
    for (int i = 0; i < n; ++i)
    {
        string s = get_str();
        T.add(s);
    }
    for (int i = 0; i < q; ++i)
    {
        string s = get_str();
        printf("%d\n", T.get(s));
    }
    return 0;
}