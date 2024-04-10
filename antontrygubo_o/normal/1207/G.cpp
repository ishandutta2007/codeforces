#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
/*#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/

using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ld long double
#define mp make_pair
#define what_is(x) cerr << #x << " is " << x << endl;

typedef tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

/*
const int p = 998244353;


int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    s = s%p;
    if (s<0) s+=p;
    return s;
}

int sub(int a, int b) {
    int s = (a-b);
    s = s%p;
    if (s<0) s+=p;
    return s;
}

int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, p-2);
}
*/
vector<int> Z(vector<int> s)
{
    int n = s.size();
    vector<int> z(n);
    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R-L] == s[R]) R++;
            z[i] = R-L; R--;
        } else {
            int k = i-L;
            if (z[k] < R-i+1) z[i] = z[k];
            else {
                L = i;
                while (R < n && s[R-L] == s[R]) R++;
                z[i] = R-L; R--;
            }
        }
    }
    return z;
}

mt19937 rnd(time(0));
/*
struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};

struct CHT : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b); }
    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = inf; return false; }
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};
*/


const int N = 500000;

const int K = 26;

struct vertex
{
    int nxt[K];
    int p;
    int pch;
    int link;
    int go[K];
};

vertex t[N];

int sz;

void init()
{
    t[0].p = 0;
    t[0].link = 0;
    t[0].pch = -1;
    for (int i = 0; i<K; i++) {t[0].nxt[i] = -1; t[0].go[i] = -1;}
    sz = 1;
}



vector<char> letter(N);
vector<int> par(N);
vector<vector<int>> son(N);
vector<int> leaf_position(N);

void add_string(int iter, string s)
{
    //cout<<iter<<" iteration:\n";
    int n = s.size();
    int start = 0;
    for (int i = 0; i<n; i++) {
        //cout<<start<<' '<<sz<<' ';
        if (t[start].nxt[s[i] - 'a'] == -1)
        {
            //cout<<"YES ";
            t[start].nxt[s[i]-'a'] = sz;
            //cout<<t[start].nxt[s[i]-'a'];
            t[sz].p = start;
            t[sz].pch = s[i]-'a';
            t[sz].link = -1;
            for (int j = 0; j<K; j++) {t[sz].nxt[j] = -1; t[sz].go[j] = -1;}
            sz++;
        }
        //cout<<endl;
        start = t[start].nxt[s[i]-'a'];
    }
    leaf_position[iter] = start;
}

int go(int v, int ch);

int find_link(int v)
{
    if (t[v].link==-1)
    {
        if (v==0 || t[v].p == 0) t[v].link = 0;
        else
        {
            t[v].link = go(find_link(t[v].p), t[v].pch);
        }
    }

    return t[v].link;
}

int go(int v, int ch)
{
    if (t[v].go[ch]==-1)
    {
        if (t[v].nxt[ch]!=-1)
        {
            t[v].go[ch] = t[v].nxt[ch];
        }
        else
        {
            if (v == 0) t[v].go[ch] = 0;
            else t[v].go[ch] = go(find_link(v), ch);
        }
    }

    return t[v].go[ch];
}


vector<vector<int>> G_links(N);

int timer = 0;

vector<int> t_in(N);
vector<int> t_out(N);

void dfs_links(int start, int p)
{
    t_in[start] = timer++;
    for (auto it: G_links[start]) if (it!=p) dfs_links(it, start);
    t_out[start] = timer;
}

vector<int> value(4*N);

void upd(int v, int tl, int tr, int pos, int val)
{
    if (tl==tr) {value[v]+=val; return;}
    int mid = (tl+tr)/2;
    if (pos<=mid) upd(2*v, tl, mid, pos, val);
    else upd(2*v+1, mid+1, tr, pos, val);

    value[v] = value[2*v] + value[2*v+1];
}

int get(int v, int tl, int tr, int l, int r)
{
    if (tl==l&&tr==r) return value[v];
    if (l>r) return 0;
    int mid = (tl+tr)/2;
    return get(2*v, tl, mid, l, min(r, mid)) + get(2*v+1, mid+1, tr, max(l, mid+1), r);
}

int n, m;
vector<string> queries;
vector<vector<int>> to_ans;
vector<int> answer;

void dfs_songs(int start, int state)
{
    //cout<<"we are at "<<start<<endl;
    upd(1, 0, N-1, t_in[state], 1);
    //cout<<"upd "<<state<<" +1"<<endl;
    for (auto it: to_ans[start])
    {
        int k = leaf_position[it];
        answer[it] = get(1, 0, N-1, t_in[k], t_out[k]-1);
        //cout<<"ask on "<<t_in[k]<<' '<<t_out[k]-1<<endl;
    }
    for (auto it: son[start])
    {
        //cout<<state<<' '<<letter[it]-'a'<<' '<<go(state, letter[it]-'a')<<endl;
        dfs_songs(it, go(state, letter[it]-'a'));
    }
    upd(1, 0, N-1, t_in[state], -1);
    //cout<<"upd "<<state<<" -1"<<endl;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin>>n;
    for (int i = 1; i<=n; i++)
    {
        int op;
        cin>>op;
        if (op==1)
        {
            char c;
            cin>>c;
            letter[i] = c;
            par[i] = 0;
            son[0].push_back(i);
        }
        else
        {
            char c;
            cin>>par[i]>>c;
            son[par[i]].push_back(i);
            letter[i] = c;
        }
    }

    /*GOOD*/

    cin>>m;
    answer.resize(m);
    queries.resize(m);
    to_ans.resize(n+1);
    for (int i = 0; i<m; i++)
    {
        int kek;
        cin>>kek>>queries[i];
        to_ans[kek].push_back(i);
    }
    /*GOOD*/
    //for (auto it: queries) cout<<it<<endl;

    init();



    for (int i = 0; i<m; i++) add_string(i, queries[i]);


    for (int i = 0; i<sz; i++)
    {
        int k = find_link(i);
        //cout<<k<<endl;
        if (i!=0) G_links[k].push_back(i);
    }

    /*for (int i = 0; i<K; i++) cout<<i<<": "<<t[0].nxt[i]<<endl;*/


    //for (int i = 0; i<sz; i++) cout<<i<<": "<<find_link(i)<<endl;

    /*for (int i = 0; i<=sz; i++)
    {
        for (auto it: G_links[i]) cout<<it<<' ';
        cout<<endl;
    }*/

    //cout<<"WE GOT HERE"<<endl;

    /*for (int i = 0; i<sz; i++)
    {
        cout<<"state "<<i<<": "<<endl;
        for (int j = 0; j<K; j++) cout<<j<<": "<<t[i].nxt[j]<<' '<<t[i].go[j]<<"| ";
        cout<<endl;
        cout<<t[i].link<<' ';
        cout<<t[i].p<<' ';
        cout<<t[i].pch<<endl;
    }*/

    dfs_links(0, -1);

    /*for (int i = 0; i<sz; i++) cout<<i<<": "<<t_in[i]<<' '<<t_out[i]<<endl;

    for (int i = 0; i<m; i++) cout<<i<<": "<<leaf_position[i]<<' ';
    cout<<endl;*/

    /*for (int i = 0; i<=n; i++)
    {
        cout<<i<<":";
        for (auto it: son[i]) cout<<it<<' ';
        cout<<endl;
    }*/

    /*for (int i = 0; i<=n; i++)
    {
        cout<<i<<": ";
        for (auto it: to_ans[i]) cout<<it<<' ';
        cout<<endl;
    }*/

    dfs_songs(0, 0);
    for (int i = 0; i<m; i++) cout<<answer[i]<<endl;
}