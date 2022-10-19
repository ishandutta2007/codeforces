#include <bits/stdc++.h>

using namespace std;

#define M 100100
#define N 10100
#define T 5050

int n, a[M], q;
int l[N], r[N];
double p[N];
int m = 1;
vector<int> g[M];
int vert[M];
int qnum[M];
int st[M];
double d[T][N], fiction[N];

void read() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < q; ++i) {
        cin >> l[i] >> r[i] >> p[i];
        l[i]--;
    }
    l[q] = 0, r[q] = n, p[q] = 0.0;
}

struct event {
    bool type;
    //0 open
    //1 close

    int pos, num;

    event(){}

    event(bool type, int pos, int num) : type(type), pos(pos), num(num) {}

    bool operator < (const event &to) const {
        if (pos != to.pos)
            return pos < to.pos;

        if (type != to.type)
            return type;

        int len1 = r[num] - l[num];
        int len2 = r[to.num] - l[to.num];
        if (len1 != len2) {
            if (!type)
                return len1 > len2;
            else
                return len1 < len2;
        }

        if (!type)
            return num < to.num;
        else
            return num > to.num;
    }

} e[N];

void sortEvents() {
    for (int i = 0; i < q; ++i) {
        e[2 * i] = event(0, l[i], i);
        e[2 * i + 1] = event(1, r[i], i);
    }
    sort(e, e + 2 * q);

    /*for (int i = 0; i < 2 * q; ++i) {
        int x = e[i].num;
        cerr << (e[i].type ? "close" : "open") << " " << (l[x]) << "-" << r[x] << "\n";
    }*/
}

void build() {
    static int st[M];
    int k = 1;
    st[0] = q;
    vert[q] = 0;

    for (int i = 0; i < 2 * q; ) {
        int j = i;
        while (j < 2 * q && e[j].pos == e[i].pos) {
            if (e[j].type) {
                assert(st[k - 1] == e[j].num);
                --k;
            } else {
                vert[e[j].num] = m++;
                g[vert[st[k - 1]]].push_back(vert[e[j].num]);
                st[k++] = e[j].num;
            }
            ++j;
        }
        i = j;
    }

    for (int i = 0; i <= q; ++i)
        qnum[vert[i]] = i;
}

void iniState(double *d, int bound = 0) {
    for (int i = 0; i < bound; ++i)
        d[i] = 0.0;

    for (int i = bound; i < N; ++i)
        d[i] = 1.0;
}

void addState(double *d, double *to) {
    for (int i = 0; i < N; ++i)
        d[i] *= to[i];
}

void addOne(double *d, double p) {
    for (int i = N - 1; i > 0; --i)
        d[i] = (1 - p) * d[i] + p * d[i - 1];
}

void dfs(int v) {

    int le = l[qnum[v]];
    int re = r[qnum[v]];

    //cerr << v << " " << le << "-" << re << "\n";

    iniState(d[v]);

    for (int u : g[v]) {
        int lt = l[qnum[u]];
        while (le < lt) {
            iniState(fiction, a[le]);
            addState(d[v], fiction);
            ++le;
        }
        dfs(u);
        addState(d[v], d[u]);
        le = r[qnum[u]];
    }

    while (le < re) {
        iniState(fiction, a[le]);
        addState(d[v], fiction);
        ++le;
    }

    addOne(d[v], p[qnum[v]]);
}


void run() {
    int mx = *max_element(a, a + n);
    for (int i = 0; i < n; ++i) {
        a[i] -= mx;
        a[i] += T;
        if (a[i] < 0)
            a[i] = 0;
    }

    dfs(0);

    double ans = 0;

    for (int i = 1; i < N; ++i)
        ans += (mx + i - T) * (d[0][i] - d[0][i - 1]);

    cout << ans << "\n";
}

int main() {
    cout.precision(9);
    cout << fixed;

    read();
    sortEvents();
    build();
    run();

    return 0;
}