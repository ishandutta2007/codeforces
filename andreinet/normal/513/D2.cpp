#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

void noSol() {
    cout << "IMPOSSIBLE\n";
    exit(0);
}

const int Nmax = 1000005;

vector<int> G[Nmax];

string toString(int x) {
    if (x == 0) return "0";
    if (x < 0) return "-" + toString(-x);
    string ret;
    while (x > 0) {
        ret += x % 10 + '0';
        x /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

struct Req {
    int x, y, where;
    Req() {}
    Req(int _x, int _y, int _where):
        x(_x), y(_y), where(_where) {}
    bool operator<(const Req& other) const {
        if (y != other.y) return y < other.y;
        return x < other.x;
    }
    string toString() const {
        return "{" + ::toString(x) + ", " + ::toString(y) + ", " + ::toString(where) + "}";
    }
};


vector<int> L[Nmax], R[Nmax];
int Son[Nmax][2], MaxN[Nmax];
int Parc[Nmax];
int beginE[Nmax], midE[Nmax], lastE[Nmax];
int E;

int solve(int left, int right) {
    //cerr << left << ' ' << right << '\n';
    if (left > right) return -1;

    int maxn = -1;
    for (int p: L[left])
        maxn = max(maxn, MaxN[p]);
    for (int p: R[left])
        right = max(right, MaxN[p]);
    right = max(maxn, right);

    /*if (left == 23)
        cerr << maxn << ' ' << right << ' ' << MaxN[left] << '\n';*/

    if (maxn == -1) {
        if (left + 1 <= right) {
            Son[left][1] = left + 1;
            right = max(right, solve(left + 1, right));
        }
    } else {
        Son[left][0] = left + 1;
        maxn = max(maxn, solve(left + 1, maxn));
        right = max(right, maxn);
        if (maxn + 1 <= right) {
            Son[left][1] = maxn + 1;
            right = max(right, solve(maxn + 1, right));
        }
    }
    return right;
}

void Dfs(const int node) {
    if (node == 0) return;
    Parc[++Parc[0]] = node;
    beginE[node] = ++E;
    Dfs(Son[node][0]);
    midE[node] = ++E;
    Dfs(Son[node][1]);
    lastE[node] = ++E;
}

void Dfs2(const int node) {
    if (node == 0) return;
    Dfs2(Son[node][0]);
    Parc[++Parc[0]] = node;
    Dfs2(Son[node][1]);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<Req> reqs(M);
    for (int i = 0; i < M; ++i) {
        int x, y;
        string S;
        cin >> x >> y >> S;

        if (x >= y) noSol();
        reqs[i] = Req(x, y, S == "LEFT" ? 0: 1);
        if (S == "LEFT") {
            L[x].push_back(y);
        }
        else {
            R[x].push_back(y);
        }
    }

    for (int i = N; i > 0; --i) {
        MaxN[i] = i;
        for (int p: L[i])
            MaxN[i] = max(MaxN[i], MaxN[p]);
        for (int p: R[i])
            MaxN[i] = max(MaxN[i], MaxN[p]);
        //cerr << i << ": " << MaxN[i] << '\n';
    }

    solve(1, N);

    Dfs(1);
    for (int i = 1; i <= N; ++i)
        if (Parc[i] != i)
            noSol();
    Parc[0] = 0;
    Dfs2(1);

    for (const Req& curr: reqs) {
        if (curr.where == 0 && !(beginE[curr.x] < beginE[curr.y] && lastE[curr.y] < midE[curr.x]))
            noSol();
        else if (curr.where == 1 && !(midE[curr.x] < beginE[curr.y] && lastE[curr.y] < lastE[curr.x]))
            cerr << "HERE: " << curr.toString(), noSol();
    }

    //cerr <<

    for (int i = 1; i <= N; ++i)
        cout << Parc[i] << ' ';
    cout << '\n';

    /*for (int i = 1; i <= N; ++i)
        cerr << "Node #" << i << ": " << Son[i][0] << ' ' << Son[i][1] << '\n';*/
}