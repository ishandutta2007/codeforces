#include <bits/stdc++.h>

using namespace std;

#define long unsigned long long

const int M = 300;

int n;
int used[M], d[M];
bool c[M], u[M];
vector<int> f, cycles;


void dfs(int v) {
    used[v] = 1;

    if (used[f[v]] == 0) {
        dfs(f[v]);
    }

    if (used[f[v]] == 1) {
        int x = v, len = 1;
        c[v] = true;
        while (used[x] == 1 && f[x] != v) {
            x = f[x];
            c[x] = true;
            ++len;
        }
        cycles.push_back(len);
    }

    used[v] = 2;
}

void calcD() {
    for (int i = 0; i < n; ++i) {
        int ans = 0, x = i;
        while (!c[x]) {
            ++ans;
            x = f[x];
        }
        d[i] = ans;
    }
}

long gcd(long x, long y) {
    while (x) {
        y %= x;
        swap(x, y);
    }
    return y;
}

long lcm(long x, long y) {
    return x / gcd(x, y) * y;
}

void print(long x) {
    cout << x << "\n";
    return;
    vector<int> d;
    while (x) {
        d.push_back(x % 10);
        x /= 10;
    }
    if (d.empty())
        d.push_back(0);
    reverse(d.begin(), d.end());
    for (int x : d)
        cout << x;
    cout << "\n";
}

void kill() {
    long g = 1;
    for (int c : cycles)
        g = lcm(g, c);
    long D = *max_element(d, d + n);
    /*cout << "D = ";
    print(D);
    cout << "g = ";
    print(g);*/
    if (D == 0)
        D = 1;
    long ans = ((D + g - 1) / g) * g;
    assert(ans >= D);

    print(ans);
}

int main() {
    cin >> n;
    f.resize(n);


    for (int i = 0; i < n; ++i) {
        cin >> f[i];
        --f[i];
    }

    for (int i = 0; i < n; ++i)
        if (!used[i])
            dfs(i);

    calcD();

    kill();


    return 0;
}