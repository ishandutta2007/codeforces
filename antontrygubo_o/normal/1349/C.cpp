#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair

const int p = 999983;


int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=p) s-=p;
    return s;
}

int sub(int a, int b) {
    int s = (a+p-b);
    if (s>=p) s-=p;
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


mt19937 rnd(time(0));

/*struct DSU {
    vector<int> sz;
    vector<int> parent;

    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
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

    DSU(int n) {
        sz.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) make_set(i);
    }
};*/

/*
const int N = 1200000;

vector<int> facs(N), invfacs(N);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<N; i++) facs[i] = mul(facs[i-1], i);
    invfacs[N-1] = inv(facs[N-1]);
    for (int i = N-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C(int n, int k)
{
    if (n<k) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}
*/

int n, m, t;

vector<string> a;

vector<vector<int>> d;

vector<pair<int, int>> close(pair<int, int> a)
{
    int x = a.first; int y = a.second;
    vector<pair<int, int>> res = {mp(x, y-1), mp(x, y+1), mp(x-1, y), mp(x+1, y)};

    vector<pair<int, int>> ans;
    for (auto it: res) if (0<=it.first && it.first<n && 0<=it.second && it.second<m) ans.push_back(it);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin>>n>>m>>t;

    a.resize(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    d = vector<vector<int>>(n,  vector<int>(m));

    vector<vector<bool>> visited(n, vector<bool>(m));

    queue<pair<int, int>> Q;

    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
        {
            auto cl = close(mp(i, j));
            bool check = false;
            for (auto it: cl) if (a[it.first][it.second]==a[i][j]) check = true;

            if (check)
            {
                Q.push(mp(i, j));
                visited[i][j] = true;
            }
        }

    if (Q.size()==0)
    {
        for (int i = 0; i<t; i++)
        {
            ll x, y, when;
            cin>>x>>y>>when; x--; y--;
            cout<<a[x][y]<<endl;
        }
        return 0;
    }

    while (!Q.empty())
    {
        auto kek = Q.front();
        Q.pop();
        for (auto it: close(kek)) if (!visited[it.first][it.second])
        {
            d[it.first][it.second] = d[kek.first][kek.second] + 1;
            visited[it.first][it.second] = true;
            Q.push(mp(it.first, it.second));
        }
    }

    for (int i = 0; i<t; i++)
    {
        ll x, y, when;
        cin>>x>>y>>when;
        x--; y--;
        //cout<<x<<' '<<y<<endl;
        if (d[x][y]<=when)
        {
            bool change = (when - d[x][y])%2;
            if (change)
            {
                if (a[x][y]=='1') cout<<'0'<<endl;
                else cout<<'1'<<endl;
            }
            else cout<<a[x][y]<<endl;
        }
        else cout<<a[x][y]<<endl;
    }



}