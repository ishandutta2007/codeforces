#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 100005, INF = 0x3f3f3f3f;
const int AMAX = 100005;

struct Node {
    vector<int> nodes;
    int rm;
};

Node aint[4 * AMAX];
int dist[NMAX];
int path[NMAX];

struct Card {
    int a, b, c, d;
};

Card cards[NMAX];
int cardsi[NMAX];

/*void norm(vector<int>& a, map<int>& real) {
    sort(a.begin(), a.end());
    int k = 0;
    for (int i = 0; i < SZ(a); ++i) {
        if (i > 0 && a[i] != a[i - 1]) {
            k++;
            real[a[i]] = k;
        }
    }
}*/

struct cmp {
    bool operator()(const int a, const int b) const {
        return cards[a].a < cards[b].a;
    }
};


struct cmp1 {
    bool operator()(const int a, const int b) const {
        return cards[a].b < cards[b].b;
    }
};

void build(int node, int left, int right) {
    if (left == right) {
        aint[node].nodes.push_back(cardsi[left]);
        aint[node].rm = 0;
    } else {
        aint[node].rm = 0;
        int mid = (left + right) / 2;
        build(2 * node + 1, left, mid);
        build(2 * node + 2, mid + 1, right);
        aint[node].nodes.resize(right - left + 1);
        merge(aint[2 * node + 1].nodes.begin(), aint[2 * node + 1].nodes.end(),
              aint[2 * node + 2].nodes.begin(), aint[2 * node + 2].nodes.end(),
              aint[node].nodes.begin(), cmp1());
    }
}

queue<int> q;

void pushQ(int node, int left, int right, int pnode, int l, int u) {
    if (cards[cardsi[left]].a > l) return;
    if (cards[cardsi[right]].a <= l) {
        int &rm = aint[node].rm;
        while (rm < SZ(aint[node].nodes)) {
            int curr = aint[node].nodes[rm];
            if (cards[curr].b > u) break;
            if (dist[curr] == INF) {
                q.push(curr);
                dist[curr] = dist[pnode] + 1;
                path[curr] = pnode;
            }
            ++rm;
        }
    } else {
        int mid = (left + right) / 2;
        pushQ(2 * node + 1, left, mid, pnode, l, u);
        pushQ(2 * node + 2, mid + 1, right, pnode, l, u);
    }
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    cards[0] = {0, 0, 0, 0};
    for (int i = 1; i <= n; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cards[i] = {a, b, c, d};
    }

    for (int i = 0; i <= n; ++i)
        cardsi[i] = i;
    sort(cardsi + 1, cardsi + n + 1, cmp());
    
    build(0, 1, n);

    q.push(0);
    memset(dist, INF, sizeof dist);
    dist[0] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        int l = cards[node].c, u = cards[node].d;
        pushQ(0, 1, n, node, l, u);
    }

    if (dist[n] == INF) {
        cout << "-1\n";
    } else {
        cout << dist[n] << '\n';
        vector<int> fans;
        for (int i = n; i != 0; i = path[i])
            fans.push_back(i);
        reverse(fans.begin(), fans.end());
        for (int p: fans) cout << p << ' ';
        cout << '\n';
    }
}