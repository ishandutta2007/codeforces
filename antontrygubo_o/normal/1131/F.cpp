#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define mp make_pair

void print(auto &a)
{
    for (auto s: a) cout<<s<<' ';
    cout<<endl;
}

void get(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cin>>a[i];
}

ll p = 1e9 + 7;

ll mul(ll a, ll b) {
    return (1LL * a%p * b%p) % p;
}

ll add(ll a, ll b) {
    ll s = (a+b);
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

mt19937 rnd(228);

int n;

vector<int> parent(150010);
vector<int> len(150010);
vector<int> pos(150010);
vector<int> visited(150010);
vector<int> where(150010);

void ins(int i)
{
    parent[i] = i;
    len[i] = 1;
    pos[i] = 0;
}

int find_root(int i)
{
    while (i!=parent[i]) i = parent[i];
    return i;
}

void unite(int i, int j)
{
    i = find_root(i);
    j = find_root(j);
    if (len[i]<len[j]) swap(i, j);
    parent[j] = i;
    pos[j] = len[i];
    len[i] += len[j];
}

void find_pos(int i)
{
    if (visited[i]) return;
    if (i==parent[i]) {where[i] = 1; visited[i] = true; return;}
    find_pos(parent[i]);
    where[i] = where[parent[i]] + pos[i];
    visited[i] = true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin>>n;
    vector<int> x(n-1);
    vector<int> y(n-1);
    for (int i = 0; i<n-1; i++) cin>>x[i]>>y[i];
    
    for (int i = 1; i<=n; i++) ins(i);
    for (int i = 0; i<n-1; i++) unite(x[i], y[i]);
    

    for (int i = 1; i<=n; i++) find_pos(i);
    

    vector<int> kitten(n+1);
    for (int i = 1; i<=n; i++) kitten[where[i]] = i;
    for (int i = 1; i<=n; i++) cout<<kitten[i]<<' ';
}