#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl

using namespace std;

typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;
const int LOG = 30;
const int N = 3e5 + 100;

struct Node {
    int nxt[2];
    int cnt;
    Node() {
        memset(nxt, -1, sizeof nxt);
        cnt = 0;
    }
};


Node data[N * LOG];
int cur = 1;

void add(int x) {
    int v = 0;
    for (int i = LOG - 1; i >= 0; i--) {
        data[v].cnt++;
        int bit = (x >> i) & 1;
        if (data[v].nxt[bit] == -1)  {
            data[v].nxt[bit] = cur++;
        }
        v = data[v].nxt[bit];
    }
    data[v].cnt++;
}



int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK".in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        add(p[i]);
    }

    for (int i = 0; i < n; i++) {
        int res = 0;
        int v = 0;
        for (int j = LOG - 1; j >= 0; j--) {
            int bit = (a[i] >> j) & 1;
            assert(data[v].cnt >= 0);
            if (data[data[v].nxt[bit]].cnt > 0) {
               v = data[v].nxt[bit];
            }
            else {
                res |= pw(j);
                v = data[v].nxt[bit ^ 1];
            }
            data[v].cnt--;
        }
        printf("%d ", res);
    }
    puts("");









    return 0;
}