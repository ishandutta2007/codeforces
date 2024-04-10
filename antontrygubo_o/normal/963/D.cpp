#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = long double;

typedef tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

#define mp make_pair

int MOD =  998244353;

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=MOD) s-=MOD;
    return s;
}

int sub(int a, int b) {
    int s = (a+MOD-b);
    if (s>=MOD) s-=MOD;
    return s;
}

int po(int a, ll deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, MOD-2);
}


mt19937 rnd(time(0));


const int LIM = 400005;

vector<int> facs(LIM), invfacs(LIM);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<LIM; i++) facs[i] = mul(facs[i-1], i);
    invfacs[LIM-1] = inv(facs[LIM-1]);
    for (int i = LIM-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C(int n, int k)
{
    if (n<k) return 0;
    if (n<0 || k<0) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}

/*
struct DSU
{
    vector<int> sz;
    vector<int> parent;
    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);

        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/

struct Node
{
    int par;
    char par_char;
    map<char, int> nxt;
    map<char, int> go;
    int suf_link;

    vector<int> incoming;
    set<int> ending;

    Node(int par_ = -1, char par_char_ = '$')
    {
        par = par_;
        par_char = par_char_;
        suf_link = -1;
    }

    /* What we need:
     * - par
     * - char of par
     * - array nxt
     * - array go
     * - suffix link
     * - whether it's leaf
     */
};

vector<Node> T(1);

int go(int v, char c);

void add_string(string s, int idx)
{
    int cur = 0;
    for (auto c: s)
    {
        if (T[cur].nxt.find(c)==T[cur].nxt.end())
        {
            int sz = T.size();
            T.push_back(Node(cur, c));
            T[cur].nxt[c] = sz;
        }
        cur = T[cur].nxt[c];
    }
    //T[cur].leaf = true;
    //T[cur].ending.insert(idx);
}

int suf_link(int v)
{
    if (T[v].suf_link == -1)
    {
        if (v==0||T[v].par==0)
        {
            T[v].suf_link = 0;
        }
        else
        {
            int par = T[v].par;
            char ch = T[v].par_char;
            T[v].suf_link = go(suf_link(par), ch);
        }
        if(v!=0) T[T[v].suf_link].incoming.push_back(v);
    }
    return T[v].suf_link;
}

int go(int v, char c)
{
    if (T[v].go.find(c)==T[v].go.end())
    {
        if (T[v].nxt.find(c)!=T[v].nxt.end())
        {
            T[v].go[c] = T[v].nxt[c];
        }
        else
        {
            if (v==0) T[v].go[c] = 0;
            else T[v].go[c] = go(suf_link(v), c);
        }
    }
    return T[v].go[c];
}

void dfs(int v, int val)
{
    T[v].ending.insert(val);
    for (auto it: T[v].incoming) dfs(it, val);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string s; cin>>s;
    int n; cin>>n;

    vector<pair<int, string>> guys(n);
    for (int i = 0; i<n; i++)
    {
        cin>>guys[i].first>>guys[i].second;
    }

    for (int i = 0; i<n; i++) add_string(guys[i].second, i);

    for (int i = 0; i<T.size(); i++)
    {
        suf_link(i);
    }

    for (int i = 0; i<n; i++)
    {
        int cur = 0;
        for (auto c: guys[i].second) cur = go(cur, c);
        dfs(cur, i);
    }

    vector<vector<int>> where(n);
    int cur = 0;
    for (int i = 0; i<s.size(); i++)
    {
        cur = go(cur, s[i]);
        for (auto it: T[cur].ending) where[it].push_back(i);
    }

    /*for (int i = 0; i<T.size(); i++)
    {
        cout<<i<<": "<<T[i].par<<' '<<T[i].par_char<<' '<<T[i].suf_link<<endl;
    }*/

    //cout<<"Starting comedy"<<endl;
    for (int i = 0; i<n; i++)
    {
        /*for (auto it: where[i]) cout<<it<<' ';
        cout<<endl;*/

        int k = guys[i].first;
        if (where[i].size()<k) {cout<<-1<<endl; continue;}
        int minn = 1e9;
        for (int j = 0; j+k-1<where[i].size(); j++) minn = min(minn, where[i][j+k-1]-where[i][j] + (int)guys[i].second.size());
        cout<<minn<<endl;
    }

}