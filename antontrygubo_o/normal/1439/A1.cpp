#include <bits/stdc++.h>

using namespace std;

/*#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/

using ll = long long;
using ld = long double;



#define mp make_pair

const int p = 1e9 + 7;

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

/*
const int N = 5000005;

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
    if (n<0 || k<0) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}*/




/*struct DSU
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

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/

void solve()
{
    int n, m;
    cin>>n>>m;
    vector<string> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    vector<vector<int>> b(n, vector<int>(m));
    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++) if (a[i][j]=='1') b[i][j] = 1;

    vector<vector<pair<int, int>>> ops;

    for (int i = n-1; i>=2; i--)
    {
        for (int j = 0; j<m-2; j++)
        {
            if (b[i][j] == 1)
            {
                vector<pair<int, int>> tmp = {{i, j}, {i-1, j}, {i-1, j+1}};
                for (auto it: tmp) b[it.first][it.second] = 1 - b[it.first][it.second];
                ops.push_back(tmp);
            }
        }
        if (b[i][m-2]||b[i][m-1])
        {
            vector<pair<int, int>> tmp;
            if (b[i][m-2]) tmp.push_back(mp(i, m-2));
            if (b[i][m-1]) tmp.push_back(mp(i, m-1));
            if (tmp.size()<3) tmp.push_back(mp(i-1, m-2));
            if (tmp.size()<3) tmp.push_back(mp(i-1, m-1));
            for (auto it: tmp) b[it.first][it.second] = 1 - b[it.first][it.second];
            ops.push_back(tmp);
        }
    }

    for (int j = 0; j<m-2; j++) if (b[0][j]||b[1][j])
    {
        vector<pair<int, int>> tmp;
        if (b[0][j]) tmp.push_back(mp(0, j));
        if (b[1][j]) tmp.push_back(mp(1, j));
        if (tmp.size()<3) tmp.push_back(mp(0, j+1));
        if (tmp.size()<3) tmp.push_back(mp(1, j+1));
        for (auto it: tmp) b[it.first][it.second] = 1 - b[it.first][it.second];
        ops.push_back(tmp);
    }

    vector<pair<int, int>> zero, one;
    for (int i = 0; i<=1; i++)
        for (int j = m-2; j<=m-1; j++)
        {
            if (b[i][j]) one.push_back(mp(i, j));
            else zero.push_back(mp(i, j));
        }

    if (one.size()==4)
    {
        vector<pair<int, int>> tmp;
        for (int i = 0; i<3; i++) tmp.push_back(one[i]);
        for (auto it: tmp) b[it.first][it.second] = 1 - b[it.first][it.second];
        ops.push_back(tmp);

        zero.clear(); one.clear();
        for (int i = 0; i<=1; i++)
            for (int j = m-2; j<=m-1; j++)
            {
                if (b[i][j]) one.push_back(mp(i, j));
                else zero.push_back(mp(i, j));
            }
    }


    if (one.size()==1)
    {
        vector<pair<int, int>> tmp;
        tmp.push_back(one[0]);
        for (int i = 0; i<2; i++) tmp.push_back(zero[i]);
        for (auto it: tmp) b[it.first][it.second] = 1 - b[it.first][it.second];
        ops.push_back(tmp);

        zero.clear(); one.clear();
        for (int i = 0; i<=1; i++)
            for (int j = m-2; j<=m-1; j++)
            {
                if (b[i][j]) one.push_back(mp(i, j));
                else zero.push_back(mp(i, j));
            }
    }


    if (one.size()==2)
    {
        vector<pair<int, int>> tmp;
        for (int i = 0; i<2; i++) tmp.push_back(zero[i]);
        tmp.push_back(one[0]);
        for (auto it: tmp) b[it.first][it.second] = 1 - b[it.first][it.second];
        ops.push_back(tmp);

        zero.clear(); one.clear();
        for (int i = 0; i<=1; i++)
            for (int j = m-2; j<=m-1; j++)
            {
                if (b[i][j]) one.push_back(mp(i, j));
                else zero.push_back(mp(i, j));
            }
    }

    if (one.size()==3)
    {
        vector<pair<int, int>> tmp;
        for (int i = 0; i<3; i++) tmp.push_back(one[i]);
        for (auto it: tmp) b[it.first][it.second] = 1 - b[it.first][it.second];
        ops.push_back(tmp);

        zero.clear(); one.clear();
        for (int i = 0; i<=1; i++)
            for (int j = m-2; j<=m-1; j++)
            {
                if (b[i][j]) one.push_back(mp(i, j));
                else zero.push_back(mp(i, j));
            }
    }

    cout<<ops.size()<<endl;
    for (auto it: ops)
    {
        for (auto pr: it) cout<<pr.first+1<<' '<<pr.second+1<<' ';
        cout<<endl;
    }

    /*cout<<">>>>>"<<endl;
    for (auto vec: b)
    {
        for (auto x: vec) cout<<x<<' ';
        cout<<endl;
    }
    cout<<">>>>>>"<<endl;*/

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) solve();

}

/*
5
2
2 3
2 3 1
1 2 2 1
3 1 3 2 3
 */