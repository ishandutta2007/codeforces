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
#include <unordered_map>
#include<random>
#include<ctime>
#define double long double
//#define int long long
using namespace std;
long long gcd(long long i, long long j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
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
const long long INF = 1e9;
//const int mod = 1000000007;
int mod;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 1001, maxT = 2001;
void file_inc() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
vector<pair<int, int>>G[maxN];
int n, m, k;
vector<int>dey(int vertex) {
    vector<int>cost(n, INF);
    cost[vertex] = 0;
    priority_queue< pair<int, int >> q;
    vector<int>used(n, 0);
    q.push({ 0,vertex });
    while (!q.empty()) {
        int b = q.top().second;
        q.pop();
        if (used[b])continue;
        used[b] = 1;
        for (auto x : G[b]) {
            if (cost[x.first] > cost[b] + x.second) {
                cost[x.first] = cost[b] + x.second;
                q.push({ -cost[x.first],x.first });
            }
        }
    }
    return cost;
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    // file_inc();
    cin >> n >> m >> k;
    vector<vector<int>>dist(n);
    vector<tuple<int, int, int>>edges(m);
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        --a;
        --b;
        edges[i] = make_tuple(a, b, w);
        G[a].push_back({ b,w });
        G[b].push_back({ a,w });
    }
    for (int i = 0; i < n; ++i) {
        dist[i] = dey(i);
    }
    long long ans = 0;
    vector<pair<int, int>>qw(k);
    for (auto &x : qw) {
        cin >> x.first >> x.second;
        --x.first;
        --x.second;
        ans += dist[x.first][x.second];
    }
    for (auto ed : edges) {
        int f, s, w;
        tie(f, s, w) = ed;
        long long tmpa = 0;
        for (auto x : qw) {
            tmpa += min(dist[x.first][x.second], min(dist[x.first][f] + dist[s][x.second], dist[x.first][s] + dist[f][x.second]));
        }
        ans = min(ans, tmpa);
    }
    cout << ans;
    return 0;
}