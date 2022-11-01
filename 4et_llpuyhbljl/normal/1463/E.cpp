#pragma comment(linker, "/STACK:9759095000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<unordered_map>
#include<random>
#include<ctime>
//#define double long double
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
long long gcd(long long i, long long j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
#ifdef _DEBUG
ll __builtin_popcount(ll x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
#endif
template<typename T> inline T getint() {
    T val = 0;
    char c;

    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9')) {
        neg |= c == '-';
    }

    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));

    return val * (neg ? -1 : 1);
}
//#define int long long
const long long INF = 1e18;
const int mod = 1000000007;
const ld eps = 1e-12, pi = acos(-1);
const int maxN = 300100, maxT = 100010;
void panic() {
    cout << "0\n";
    exit(0);
}
vector<vector<int>>G, G1, NG;
int f[maxN];
int find(int v) { return f[v] == v ? v : f[v] = find(f[v]); }
vector<int>top_sort, used;
void add_comp(int v) {
    if (G1[v].empty()) {
        top_sort.push_back(v);
        return;
    }
    int v1 = G1[v][0];
    queue<int>st;
    st.push(v);
    st.push(v1);
    while (G1[v1].size() == 1) {
        v1 = G1[v1][0];
        st.push(v1);
        if (v1 == v)panic();
    }
    while (!st.empty()) {
        top_sort.push_back(st.front());
        st.pop();
    }
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(11);
#ifdef _MY
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        f[i] = i;
    }
    G.resize(n + 1);
    G1.resize(n + 1);
    NG.resize(n + 1);
    vector<int>ct(n + 1), ct1(n + 1);
    int main_vertex = -1;
    vector<int>pp(n + 1);
    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        pp[i] = p;
        if (p)G[p].push_back(i);
        else main_vertex = i;
    }
    set<pair<int, int>>sse;
    vector<pair<int, int>>gg(k);
    used.assign(n + 1, 0);
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        if (sse.count(make_pair(a, b)))continue;
        sse.insert({ a,b });
        gg[i] = { a,b };
        if (++ct[a] == 2 || ++ct1[b] == 2 || find(b) == main_vertex)panic();
        if (find(a) == find(b)) {
            panic();
        }
        else {
            G1[a].push_back(b);
            f[b] = a;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (auto x : G[i]) {
            if (find(i) != find(x)) {
                NG[find(i)].push_back(find(x));
                ++used[find(x)];
            }
        }
    }
    queue<int>q;
    q.push(main_vertex);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        add_comp(v);
        for (auto x : NG[v]) {
            if (--used[x] == 0)q.push(x);
        }
    }
    if (top_sort.size() != n) {
        panic();
    }
    vector<int>id(n + 1, -50);
    for (int i = 0; i < top_sort.size(); ++i) {
        id[top_sort[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        if (i == main_vertex)continue;
        if (id[i] < id[pp[i]])panic();
    }
    for (auto x : gg) {
        if (id[x.first] + 1 != id[x.second])panic();
    }
    for (auto x : top_sort)cout << x << " ";
    return 0;
}