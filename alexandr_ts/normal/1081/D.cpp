#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll INF = 1e9 + 10;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int N = 2e5 + 10;

bool used[N];


int r[N];
int parent[N];
int cnt[N];

void make_set(int a) {
    parent[a] = a;
    r[a] = 1;
    cnt[a] = used[a];
}

int find_set(int a) {
    if (parent[a] == a)
        return a;
    else
        return parent[a] = find_set(parent[a]);
}

void union_sets(int a, int b) {
    int a1 = find_set(a);
    int b1 = find_set(b);
    if (a1 != b1) {
        if (r[a1] < r[b1])
            swap(a1, b1);
        r[a1] += r[b1];
        cnt[a1] += cnt[b1];
        parent[b1] = a1;
    }
}

struct Ed {
    int v, u, w;
} edges[N];

bool cmp(Ed a, Ed b) {
    return a.w < b.w;
}

void solve() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);


    int x;
    fr(i, k) {
        scanf("%d", &x);
        used[x - 1] = true;
    }

    fr(i, n)
        make_set(i);

    fr(i, m) {
        scanf("%d %d %d", &edges[i].v, &edges[i].u, &edges[i].w);
        edges[i].v--;
        edges[i].u--;
    }

    sort(edges, edges + m, cmp);

    int ans = 0;

    fr(i, m) {
        int v = edges[i].v;
        int u = edges[i].u;
        int w = edges[i].w;
        //cout << v << " " << u << endl;
        if (find_set(v) == find_set(u)) {
            continue;
        }

        if (cnt[find_set(v)] && cnt[find_set(u)]) {
            ans = w;
        }

        union_sets(find_set(v), find_set(u));
    }

    fr(i, k)
        cout << ans << " ";
}

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    solve();

    return 0;
}