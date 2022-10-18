#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

const int maxn = 3e5, sigma = 27;
int to[maxn][sigma];
int link[maxn], term[maxn];
int len[maxn];
int sz = 1;

int add_str(string s)
{
    int v = 0;
    for(auto c: s)
    {
        c -= 'a';
        if(!to[v][c]) to[v][c] = sz++;
        len[to[v][c]] = len[v] + 1;
        v = to[v][c];
    }
    term[v] = v;
    return v;
}

void push_links()
{
    int q[maxn];
    int st = 0, fi = 1;
    q[0] = 0;
    while(st < fi)
    {
        int v = q[st++];
        int u = link[v];
        if(!term[v])
            term[v] = term[u];
        for(int c = 0; c < sigma; c++)
        {
            if(to[v][c])
            {
                link[to[v][c]] = v ? to[u][c] : 0;
                q[fi++] = to[v][c];
            }
            else
            {
                to[v][c] = to[u][c];
            }
        }
    }
}

vector<int> Q[maxn];
int l[2 * maxn], r[2 * maxn];
int ans[2 * maxn];
ordered_set st[maxn];

main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    int L[n], R[n], v[n];
    for(int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        L[i] = s.size();
        s += t;
        s += char('z' + 1);
        R[i] = s.size();
        v[i] = add_str(t);
    }
    push_links();
    for(int i = 0; i < q; i++)
    {
        int k;
        cin >> l[i] >> r[i] >> k;
        l[i] = L[l[i] - 1];
        r[i] = R[r[i] - 1];
        Q[v[k - 1]].push_back(i);
    }
    int V = 0;
    for(int i = 0; i < s.size(); i++)
    {
        V = to[V][s[i] - 'a'];
        st[V].insert(i);
    }
    int p[sz];
    iota(p, p + sz, 0);
    sort(p, p + sz, [](int a, int b){return len[a] > len[b];});
    for(int i = 0; i < sz - 1; i++)
    {
        int u = p[i];
        int v = term[link[u]];
        for(auto it: Q[u])
            ans[it] = st[u].order_of_key(r[it]) - st[u].order_of_key(l[it]);
        if(st[u].size() > st[v].size())
            st[v].swap(st[u]);
        for(auto it: st[u])
            st[v].insert(it);
    }
    for(int i = 0; i < q; i++)
        cout << ans[i] << "\n";
}