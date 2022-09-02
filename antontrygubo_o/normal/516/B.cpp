#include <bits/stdc++.h>


using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair

const int p = 1000000007;


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

/*const int N = 1000000;

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
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}*/



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;
    vector<string> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    vector<vector<int>> status(n, vector<int>(m)), cnt(n, vector<int>(m)), pushed(n, vector<int>(m));
    vector<vector<char>> lol(n, vector<char>(m));

    queue<pair<int, int>> single;
    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
        {
            if (a[i][j]!='.') {lol[i][j] = '*'; status[i][j] = -1; continue;}

            if (i+1<n && a[i+1][j]=='.') cnt[i][j]++;
            if (i>0 && a[i-1][j]=='.') cnt[i][j]++;
            if (j+1<m && a[i][j+1]=='.') cnt[i][j]++;
            if (j>0 && a[i][j-1]=='.') cnt[i][j]++;
            if (cnt[i][j]==0) {cout<<"Not unique"; return 0;}
            if (cnt[i][j]==1) {single.push(mp(i, j)); pushed[i][j] = 1;}
        }
    while (!single.empty())
    {
        auto cell = single.front();
        single.pop();
        int i = cell.first; int j = cell.second;

        if (status[i][j]==1) continue;

        if (cnt[i][j]<1) {cout<<"Not unique"; return 0;}



        pair<int, int> fr;

        if (i+1<n && status[i+1][j]==0) {fr = mp(i+1, j); lol[i][j] = '^'; lol[i+1][j] = 'v';}
        if (i>0 && status[i-1][j]==0) {fr = mp(i-1, j); lol[i][j] = 'v'; lol[i-1][j] = '^';}
        if (j+1<m && status[i][j+1]==0) {fr = mp(i, j+1); lol[i][j] = '<'; lol[i][j+1] = '>';}
        if (j>0 && status[i][j-1]==0) {fr = mp(i, j-1); lol[i][j] = '>'; lol[i][j-1] = '<';}

        status[i][j] = 1;
        status[fr.first][fr.second] = 1;
        i = fr.first;
        j = fr.second;
        if (i+1<n && status[i+1][j]==0) {cnt[i+1][j]--; if (cnt[i+1][j]==1) single.push(mp(i+1, j));}
        if (i>0 && status[i-1][j]==0) {cnt[i-1][j]--; if (cnt[i-1][j]==1) single.push(mp(i-1, j));}
        if (j+1<m && status[i][j+1]==0) {cnt[i][j+1]--; if (cnt[i][j+1]==1) single.push(mp(i, j+1));}
        if (j>0 && status[i][j-1]==0) {cnt[i][j-1]--; if (cnt[i][j-1]==1) single.push(mp(i, j-1));}
    }

    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++) if (status[i][j]==0) {cout<<"Not unique"; return 0;}

    for (auto it: lol)
    {
        for (auto x: it) cout<<x;
        cout<<endl;
    }

}