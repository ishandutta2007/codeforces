#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 100100;

int a[V], n, K;
LL ans[V];
struct Node {
    int id, type;
    LL t;
    bool operator<(const Node& x) const {
        if (t != x.t) return t > x.t;
        if (type != x.type) return type < x.type;
        return id > x.id;
    }
    //Node(int _id, int _type, LL _t) : id(_id), type(_type), t(_t) {}
    //Node(int _id, int _type, LL _t) {
    //    id = _id, type = _type, t = _t;
    //}
}e[V];



int main() {
    while (~scanf("%d%d", &n, &K)) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i) e[i].id = i, e[i].t = a[i];
        priority_queue<Node> e;
        set<int> want, Q;
        for (int i = 0; i < n; ++i) {
            e.push({i, 1, a[i]});
        }
        LL cur = 0;
        LL qt = 0;
        while (!e.empty()) {
            Node now = e.top();
            e.pop();
            cur = now.t;
            //printf("E %d %d %I64d\n", now.id, now.type, now.t);
            if (now.type == 1) {
                want.insert(now.id);
            } else {
                Q.erase(now.id);
            }
            if (!want.empty() && (Q.empty() || *want.begin() < *Q.begin())) {
                int id = *want.begin();
                want.erase(id);
                Q.insert(id);
                qt = max(cur, qt) + K;
                e.push({id, 0, qt});
                ans[id] = qt;
            }
        }

        for (int i = 0; i < n; ++i) printf("%I64d ", ans[i]); puts("");
    }
    return 0;
}

/*
5 314
0 310 942 628 0

*/