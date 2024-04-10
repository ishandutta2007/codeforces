#include <bits/stdc++.h>

using namespace std;

#define M 5009

struct edge {
    int from, to;
    int cap;
    edge() {}
    edge(int from, int to, int cap) : from(from), to(to), cap(cap) {}
} e[M];

vector<int> g[M];
int es = 0;

void add(int from, int to, int cap) {
    g[from].push_back(es);
    g[to].push_back(es + 1);
    e[es++] = edge(from, to, cap);
    e[es++] = edge(to, from, 1);
}

void sub(int id, int x) {
    e[id].cap /= x;
    e[id ^ 1].cap *= x;
}

int a[M];
int n, S, T, m;
int spec[M];
int ans = 0;

int cnt(int x) {
    int ans = 0;
    for (int i = 2; i * i <= x; ++i)
        while (x % i == 0) {
            ++ans;
            x /= i;
        }
    if (x > 1)
        ans++;
    return ans;
}

int getSpec(int x) {
    int ans = 1;
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0) {
            ans *= i;           
            while (x % i == 0)
                x /= i;
        }
    if (x > 1)
        ans *= x;
    return ans;    
}

int gcd(int x, int y) {
    while (x) {
        y %= x;
        swap(x, y);
    }
    return y;
}

int lcm(int x, int y) {
    return x / gcd(x, y) * y;
}

void read() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    S = n + 2;
    T = n + 3;
    for (int i = 1; i <= n; i += 2)
        add(S, i, a[i]);
    for (int i = 2; i <= n; i += 2)
        add(i, T, a[i]);

    for (int j = 0, x, y; j < m; ++j) {
        cin >> x >> y;
        if (x % 2 == 0)
            swap(x, y);
        add(x, y, 0);
    }
}

int st[M], sz = 0;

void push(int x) {
    st[sz++] = x;
}

void pop() {
    --sz;
}

int dfs(int v, int tk) {
    if (v == T)
        return tk;
    if (tk == 1)
        return -1;

    int s = getSpec(tk);
    if (tk != 0 && spec[v] % s == 0) {
        return -1;
    }
    spec[v] = lcm(spec[v], s);


    for (int id : g[v]) {
        int t = gcd(tk, e[id].cap), val;
        push(id);
        if ((val = dfs(e[id].to, t)) > 1)
            return val;
        pop();
    }
    return -1;
}

void relax(int t) {
    ans += cnt(t);
    for (int i = 0; i < sz; ++i)
        sub(st[i], t);
}

void printNetwork() {
    for (int i = 0; i < es; i += 2) {
        cerr << e[i].from << " -> " << e[i].to << " | " << e[i].cap << "\n";
    }
}


int main() {

    read();
    //printNetwork();

    int val;
    fill(spec, spec + T, 1);
    sz = 0;

    while ((val = dfs(S, 0)) > 1) {
        relax(val);

        //cerr << val << "!\n";

        fill(spec, spec + T, 1);
        sz = 0;
    }

    cout << ans << "\n";
    return 0;
}