#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define B 2
#define long long long 
#define mod 1000000007ll
#define M 100100

struct matr {
    long a[2][2];
    matr() {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                a[i][j] = 0;
    }

    matr operator * (const matr &x) const {
        matr ans;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k)
                    ans.a[i][k] = (ans.a[i][k] + a[i][j] * x.a[j][k]) % mod;
        return ans;
    }

    matr operator + (const matr &x) const {
        matr ans;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                ans.a[i][j] = (a[i][j] + x.a[i][j]) % mod;
        return ans;
    }

    matr operator - (const matr &x) const {
        matr ans;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                ans.a[i][j] = (a[i][j] - x.a[i][j]) % mod;
        return ans;
    }

    matr operator % (const matr &x) const {
        matr ans;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                ans.a[j][i] = (a[i][j] * x.a[j][i]) % mod;
        return ans;
    }

    void print() {
        for (int i = 0; i < 2; ++i, cout << "\n")
            for (int j = 0; j < 2; ++j, cout << " ")
                cout << a[i][j];
    }
} ini, zero, d[M];

void initiate() {
    ini.a[0][1] = ini.a[1][0] = 1;
}

int n;
vector<int> g[M];

void read() {
    cin >> n;
    for (int i = 2, x; i <= n; ++i) {
        cin >> x;
        g[x].push_back(i);
    }
    for (int i = 1; i < n; ++i) {
        sort(g[i].begin(), g[i].end());
    }
}  

matr ch(const matr &x) {
    matr ans;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            ans.a[1 - i][j] = x.a[i][j];
    return ans;
}

void dfs(int v) {
    d[v] = zero;

    for (int & to : g[v])
        dfs(to);

    matr x;

    for (int i = 0; i < (int) g[v].size(); ++i) {
        int to = g[v][i];
        x = x + (x * d[to]) + ch(d[to]);
    }

    matr y;

    for (int i = (int) g[v].size() - 1; i >= 0; --i) {
        int to = g[v][i];
        y = y + (y * d[to]) + ch(d[to]);
    }

    matr minus;

    //(x + y).print();

    matr z;

    for (int i = 0; i < 2; ++i) {
        z = zero;

        for (int k = 0; k < (int) g[v].size(); ++k) {
            int to = g[v][k];

            matr nz = z + (z % d[to]);
            for (int j = 0; j < 2; ++j)
                nz.a[i][j] += d[to].a[i][j];
            z = nz;
        }

        //for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k) {
                minus.a[i][k] += z.a[i][k];
            }
    }

    //minus.print();

    d[v] = (x + y) - ch(minus) + ini;

    //d[v].print();
}

int main() {
    ios_base::sync_with_stdio(false);

    initiate();
    read();
    dfs(1);

    long ans = 0;
    for (int j = 0; j < 2; ++j)
        ans = (ans + d[1].a[0][j]) % mod;

    if (ans < 0)
        ans += mod;

    cout << ans << "\n";

    return 0;
}