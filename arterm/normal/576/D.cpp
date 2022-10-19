#include <bits/stdc++.h>

using namespace std;

const int M = 155;
const int INF = 200;
const int mod = 987654323;

#define long long long

int n, m;
    
struct Matrix {
    bitset<M> a[M];

    bitset<M>& operator[](int x) {
        return a[x];
    }

    const bitset<M>& operator[](int x) const {
        return a[x];
    }

    Matrix operator * (const Matrix &to) const {
        Matrix ans;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (a[i][j])
                    ans[i] |= to[j];
        return ans;
    }
};

Matrix bin(Matrix A, int to) {
    Matrix ans;
    for (int i = 1; i <= n; ++i)
        ans[i][i] = 1;
    while (to) {
        if (to & 1)
            ans = ans * A;
        A = A * A;
        to >>= 1;
    }
    return ans;
}

struct Edge {
    int a, b, d;
    void read() {
        cin >> a >> b >> d;
    }

    bool operator < (const Edge &to) const {
        return d < to.d;
    }
} e[M];

vector<int> g[M];
bool used[M], r[M];
int d[M], q[M], qs, qf;
Matrix T;

void add(Edge e) {
    g[e.a].push_back(e.b);
    T[e.a][e.b] = 1;
}

bool bfs() {
    qs = qf = 0;
    fill(used, used + M, false);
    fill(d, d + M, INF);

    for (int i = 1; i <= n; ++i)
        if (r[i]) {
            used[i] = true;
            q[qf++] = i;
            d[i] = 0;
        }

    while (qs < qf) {
        int x = q[qs++];
        for (int to : g[x])
            if (!used[to]) {
                used[to] = true;
                d[to] = d[x] + 1;
                q[qf++] = to;
            }
    }

    return used[n];
}

void read() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        e[i].read();
    sort(e, e + m);
}

bool newR[M];

void make(int to) {
    fill(newR, newR + M, false);
    Matrix A = bin(T, to);
    /*for (int i = 1; i <= n; ++i, cerr << endl)
        for (int j = 1; j <= n; ++j, cerr << " ")
            cerr << A[i][j];*/
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (A[i][j])
                newR[j] |= r[i];
    for (int i = 1; i <= n; ++i)
        r[i] = newR[i];
}

void print() {
    for (int i = 1; i <= n; ++i) {
        cerr << "r " << i << " = " << r[i] << "\n";
    }
}

void kill() {
    int cur = 0, done = 0;

    r[1] = true;

    while (cur < m) {
        make(e[cur].d - done);
        //print();
        done = e[cur].d;
        while (cur < m && e[cur].d == done) {
            add(e[cur]);
            ++cur;
        }
        if (bfs()) {
            cout << done + d[n] << endl;
            return;
        }
    }

    cout << "Impossible\n";
}



int main() {
    read();
    kill();
    return 0;
}