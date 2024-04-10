
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define pw(x) (1LL<<(x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl

using namespace std;

typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;


template<typename T>
vector<vector<T>> rev(vector<vector<T>> a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<T>> b(m, vector<T>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[j][i] = a[i][j];
        }
    }
    return b;
}

vector<vector<pair<int,int>>> calc(vector<vector<int>> a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<pair<int,int>>> res(n, vector<pair<int,int>>(m));
    for (int i = 0; i < n; i++) {
        vector<int> b = a[i];
        sort(all(b));
        b.resize(unique(all(b)) - b.begin());
        for (int j = 0; j < m; j++) {
            int pos = lower_bound(all(b), a[i][j]) - b.begin();
            res[i][j] = {pos, b.size() - pos - 1};
        }
    }
    return res;
}

int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK".in", "r", stdin));
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> a(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    auto r1 = calc(a);
    auto r2 = rev(calc(rev(a)));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", max(r1[i][j].F, r2[i][j].F) + 1 + max(r1[i][j].S, r2[i][j].S));
        }
        puts("");
    }


    return 0;
}