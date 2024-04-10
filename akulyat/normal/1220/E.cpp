#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;
const long long gs = 500 * kk;

ll n, m, i, j, t, str, v2, gans;
vector<vector<ll>> reb;
vector<vector<ll>> e;
vector<ll> col, col2, col3, tc, v, ins, ans, q, vx, ans4, col4;
set <pll> er;
vector <bool> mark;

bool viv = false;

void DFS(ll v, ll c)
{
col[v] = c;
ll l = reb[v].size();
q.push_back(v);
for (ll i = 0; i < l; i++)
    {
    ll s = reb[v][i];
    if (col[s] == -1)
        {
        er.insert({v, s});
        DFS(s, c + 1);
        }
    }
}

void DFS2(ll v, ll c)
{
col2[v] = c;
ll l = reb[v].size();
for (ll i = 0; i < l; i++)
    {
    ll s = reb[v][i];
    if (col2[s] == -1 && er.find({v, s}) == er.end())
        {
        DFS2(s, c);
        }
    }
}

void DFS3(ll v, ll c) {
    col3[v] = c;
    for (auto s : e[v]) {
        if (col3[s] == -1) {
            DFS3(s, c);
            if (mark[s])
                mark[v] = true;
        }
    }
    if (mark[v])
        gans += ins[v], ins[v] = 0;
}

void DFS4(ll v, ll c) {
    col4[v] = c;
    ans4[v] = ins[v];
    ll add = 0;
    for (auto s : e[v]) {
        if (col4[s] == -1) {
            DFS4(s, c);
            add = max(add, ans4[s]);
        }
    }
    ans4[v] += add;
}

void gr2(){
    e.resize(v2);
    for (ll i = 0; i < n; i++) {
        for (auto s : reb[i])
            if (col2[i] != col2[s]) {
                e[col2[i]].push_back(col2[s]);
                e[col2[s]].push_back(col2[i]);
            }
    }

    for (auto & v : e) {
        unordered_set <ll> s;
        for (auto i : v)
            s.insert(i);
        v.clear();
        for (auto i : s)
            v.push_back(i);
    }
}

int main()
{
//viv= true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin >> n >> m;
v.resize(n);
reb.resize(n);
for (auto & i : v)
    cin >> i;
for (i = 0; i < m; i++)
    {
    long a, b;
    cin >> a >> b;
    a--; b--;
    reb[a].push_back(b);
    reb[b].push_back(a);
    }
cin >> str;
str--;
col.assign(n, -1);
col2.assign(n, -1);
DFS(str, 0);

v2 = 0;
for (auto v : q)
    if (col2[v] == -1)
        DFS2(v, v2), v2++;

gr2();

ins.resize(v2);
vx.resize(v2);
for (ll i = 0; i < n; i++) {
    ins[col2[i]] += v[i];
    vx[col2[i]]++;
}

mark.resize(v2, false);
for (ll i = 0; i < v2; i++)
    if (vx[i] > 1)
        mark[i] = true;

if (viv)
    {
    cout << v2 << endl;
    for (auto i : col2)
        cout << i << ' ';
    cout << endl;
    for (auto i : ins)
        cout << i << ' ';
    cout << endl;
    for (auto i : mark)
        cout << i;
    cout << endl;
    }

col3.resize(v2, -1);
DFS3(0, 0);

if (viv)
    {
    cout << v2 << endl;
    for (auto i : col2)
        cout << i << ' ';
    cout << endl;
    for (auto i : ins)
        cout << i << ' ';
    cout << endl;
    for (auto i : mark)
        cout << i;
    cout << endl;
    }



ans4.resize(v2, 0);
col4.resize(v2, -1);
DFS4(0, 0);

gans += ans4[0];

cout << gans;





        return 0;
}
/**
10 12
1 7 1 9 3 3 6 30 1 10
1 2
1 3
3 5
5 7
2 3
5 4
6 9
4 6
3 7
6 8
9 4
9 10
6

13 16
1 7 1 9 3 3 6 30 1 10 0 0 0
1 2
1 3
3 5
5 7
2 3
5 4
6 9
4 6
3 7
6 8
9 4
9 10
10 12
11 12
12 13
13 11
6


**/