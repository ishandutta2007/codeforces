#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define int long long

#define M 2000010

using namespace std;

struct robot {
    int x, r, q, L, R;
    robot() {}
    robot(int _1, int _2, int _3) {x = _1, r = _2, q = _3;}
    bool operator < (const robot& X) const {return r < X.r;}
} X[M];

struct query {
    int op, tim, v;
    query() {}
    query(int _1, int _2, int _3) {op = _1, tim = _2, v = _3;}
    bool operator < (const query& X) const {if(tim != X.tim) return tim < X.tim; return op < X.op;}
};
int n, K, num[M], who[M], tmp[M], t = 0;

int Tree[M];

vector <int> V[2200050];

bool cmp(int x, int y) {
    return num[x] < num[y];
}

int find(int x) {
    return lower_bound(num + 1, num + n + 1, x) - num;
}

void add(int x, int y) {
    for(int i = x; i <= n; i += i & -i) Tree[i] += y;
}

int ask(int x) {
    int ans = 0;
    for(int i = x; i; i -= i & -i) ans += Tree[i];
    return ans;
}

signed main() {
    scanf("%lld%lld", &n, &K);
    for(int i = 1; i <= n; i++) scanf("%lld%lld%lld", &X[i].x, &X[i].r, &X[i].q);
    //sort(X + 1, X + n + 1);
    t = 0;
    for(int i = 1; i <= n; i++) num[i] = X[i].q, who[i] = i, tmp[i] = X[i].q;
    sort(tmp + 1, tmp + n + 1);
    for(int i = n; i >= 2; i--) tmp[i] = tmp[i] - tmp[i - 1];
    for(int i = 1; i <= n; i++) tmp[i] = min(tmp[i], K + 1);
    for(int i = 2; i <= n; i++) tmp[i] += tmp[i - 1];
    sort(who + 1, who + n + 1, cmp);
    for(int i = 1; i <= n; i++) {
        X[who[i]].q = tmp[i];
    }
    t = 0;
    for(int i = 1; i <= n; i++) num[i] = X[i].x;
    sort(num + 1, num + n + 1);
    //unique(num + 1, num + n + 1);
    for(int i = 1; i <= n; i++) {
        X[i].L = find(X[i].x - X[i].r);
        X[i].R = find(X[i].x + X[i].r + 1) - 1;
        X[i].x = find(X[i].x);
    }
    for(int i = 1; i <= n; i++) V[X[i].q].push_back(i);
    long long ans = 0;
    for(int i = 0; i <= 2100000; i++) if(!V[i].empty()) {
        for(int j = i; j <= i + K; j++) if(!V[j].empty()) {
            long long tmp = 0;
            vector <query> W;
            W.clear();
            for(int k = 0; k < V[i].size(); k++) {
                int v = V[i][k];
                W.push_back(query(0, X[v].L, X[v].x));
                W.push_back(query(1, X[v].R + 1, X[v].x));
            }
            for(int k = 0; k < V[j].size(); k++)
                W.push_back(query(2, X[V[j][k]].x, V[j][k]));
            sort(W.begin(), W.end());
            // if i == j then ans /= 2 (ans -= n when finish)
            for(int i = 0; i < W.size(); i++) {
                query s = W[i];
                if(s.op == 0) add(s.v, 1);
                else if(s.op == 1) add(s.v, -1);
                else tmp += ask(X[s.v].R) - ask(X[s.v].L - 1);
            }
            if(i != j) ans += tmp; else ans += (tmp - V[i].size()) / 2;
        }
    }
    printf("%lld\n", ans);
}