#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 300000, logN = 20, K = 48763;

vector <pair <int, long long>> adj[2][N];
long long dis[2][N];
int path[2][N];

void build(int s, int n, int t) {
    for (int i = 0; i < n; ++i) path[t][i] = -1, dis[t][i] = 1ll << 60;
    priority_queue <pair <long long, int>, vector <pair <long long, int>>, greater <pair <long long, int>>> pq;
    dis[t][s] = 0;
    pq.push({dis[t][s], s});
    long long d;
    int v;
    while (pq.size()) {
        tie(d, v) = pq.top(); pq.pop();
        if (dis[t][v] < d) continue;
        for (auto E : adj[t][v]) if (dis[t][E.first] > dis[t][v] + E.second) {
            dis[t][E.first] = dis[t][v] + E.second;
            path[t][E.first] = v;
            pq.push({dis[t][E.first], E.first});
        }
    }
}

map <pii, int> edge[2];

int k;

int chg(int x, int y) {
    return y * (k + 1) + x;
}

void add(int x1, int y1, int x2, int y2, int t) {
    if (x1 > x2 || (x1 == x2 && y1 > y2))
        swap(x1, x2), swap(y1, y2);
    if (x1 >= k)
        x1 = k * 2 - x1 - 1, y1 = k * 2 - y1 - 1, x2 = k * 2 - x2 - 1, y2 = k * 2 - y2 - 1;
    if (x1 > x2 || (x1 == x2 && y1 > y2))
        swap(x1, x2), swap(y1, y2);
    if (x1 + 1 == x2) {
        if (x1 == k - 1) {
            edge[t][{chg(k, y1), chg(k, y1 + 1)}]++;
            edge[t][{chg(k, y1 + 1), chg(k, y1)}]++;
            edge[t][{chg(k, 2 * k - y1 - 1), chg(k, 2 * k - y1)}]++;
            edge[t][{chg(k, 2 * k - y1), chg(k, 2 * k - y1 - 1)}]++;
        } else {
            edge[t][{chg(x2, y1), chg(x2, y1 + 1)}]++;
            edge[t][{chg(x2, y1 + 1), chg(x2, y1)}]++;
        }
    } else {
        assert(y1 + 1 == y2);
        edge[t][{chg(x1, y2), chg(x1 + 1, y2)}]++;
        edge[t][{chg(x1 + 1, y2), chg(x1, y2)}]++;
    }
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n >> k, k >>= 1;
        edge[0].clear(), edge[1].clear();
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j <= k * 2; ++j) for (int t : {0, 1}) {
                if (i)
                    edge[t][{chg(i, j), chg(i - 1, j)}] = 0;
                if (i < k)
                    edge[t][{chg(i, j), chg(i + 1, j)}] = 0;
                if (j)
                    edge[t][{chg(i, j), chg(i, j - 1)}] = 0;
                if (j < k * 2)
                    edge[t][{chg(i, j), chg(i, j + 1)}] = 0;
            }
        }
        for (int i = 0, x1, y1, x2, y2; i < n; ++i) {
            cin >> x1 >> y1 >> x2 >> y2, --x1, --y1, --x2, --y2;
            add(x1, y1, x2, y2, 0);
            swap(x1, y1), swap(x2, y2);
            add(x1, y1, x2, y2, 1);
        }
        for (int t : {0, 1}) {
            for (auto A : edge[t]) {
                adj[t][A.X.X].eb(A.X.Y, A.Y);
            }   
        }
        build(chg(k, k), (k + 1) * (2 * k + 1), 0);
        build(chg(k, k), (k + 1) * (2 * k + 1), 1);
        for (int i = 0; i < (k + 1) * (2 * k + 1); ++i) for (int t : {0, 1})
            adj[t][i].clear();
        cout << n - min(dis[0][chg(0, 0)], dis[1][chg(0, 0)]) << endl;
    }
}