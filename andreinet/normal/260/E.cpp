#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int INF = 0x3f3f3f3f;
const int NMAX = 100005;

struct Point {
    int x, y;
    Point() {}
    Point(int _x, int _y):
        x(_x), y(_y) {}
    bool operator< (const Point& other) const {
        return x < other.x;
    }
};

struct Query {
    int d, left, right, pos;
    Query() {}
    Query(int _d, int _left, int _right, int _pos):
        d(_d), left(_left), right(_right), pos(_pos) {}

    bool operator < (const Query& other) const {
        return d < other.d;
    }
};

int aint[4 * NMAX];
int X[NMAX], Y[NMAX];

void update(int node, int left, int right, int coord, int val) {
    if (left == right) {
        aint[node] += val;
    } else {
        int mid = (left + right) / 2;
        if (coord <= Y[mid]) update(2 * node + 1, left, mid, coord, val);
        else update(2 * node + 2, mid + 1, right, coord, val);
        aint[node] = aint[2 * node + 1] + aint[2 * node + 2];
    }
}

int query(int node, int left, int right, int lq, int rq) {
    if (rq < Y[left] || lq > Y[right] || lq > rq) return 0;
    if (lq <= Y[left] && Y[right] <= rq ){
        return aint[node];
    } else {
        int mid = (left + right) / 2, ret = 0;
        if (lq <= Y[mid]) ret += query(2 * node + 1, left, mid, lq, rq);
        if (rq >= Y[mid + 1]) {
            ret += query(2 * node + 2, mid + 1, right, lq, rq);
        }
        return ret;
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

    vector<Point> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i].x >> A[i].y;
        X[i] = A[i].x;
        Y[i] = A[i].y;
    }
    sort(X, X + n);
    sort(Y, Y + n);

    vector<Query> queries;
    int a[9];
    for (int i = 0; i < 9; ++i) {
        cin >> a[i];
    }
    sort(a, a + 9);

    int cperm = 0;
    vector<vector<int>> permQ;
    do {
        int sum;
        int xx[4], yy[4];
        xx[0] = yy[0] = -INF;

        sum = a[0] + a[1] + a[2];
        if (Y[sum - 1] == Y[sum]) continue;
        yy[1] = Y[sum - 1];
        sum += a[3] + a[4] + a[5];
        if (Y[sum - 1] == Y[sum]) continue;
        yy[2] = Y[sum - 1];
        sum += a[6] + a[7] + a[8];
        if (Y[sum - 1] == Y[sum]) continue;
        yy[3] = Y[sum - 1];

        sum = a[0] + a[3] + a[6];
        if (X[sum - 1] == X[sum]) continue;
        xx[1] = X[sum - 1];
        sum += a[1] + a[4] + a[7];
        if (X[sum - 1] == X[sum]) continue;
        xx[2] = X[sum - 1];
        sum += a[2] + a[5] + a[8];
        if (X[sum - 1] == X[sum]) continue;
        xx[3] = X[sum - 1];


        //assert(xx[3] == X[n - 1] && yy[3] == Y[n - 1]);
            
        vector<int> pq;
        for (int i = 1, k = 0; i <= 3; ++i) {
            for (int j = 1; j <= 3; ++j, ++k) {
                int cpos = SZ(queries);
                pq.push_back(cpos);
                queries.push_back(Query(xx[j], yy[i - 1] + 1, yy[i], cpos));
                //cerr << i << ' ' << yy[i - 1] + 1 << ' ' << yy[i] << endl;
            }
        }
        permQ.push_back(pq);
        cperm++;
    } while(next_permutation(a, a + 9));

    vector<int> answers(SZ(queries));

    sort(A.begin(), A.end());
    sort(queries.begin(), queries.end());
    int pos = 0;
    for (const Query& e: queries) {
        while (pos < n && A[pos].x <= e.d) {
            update(0, 0, n - 1, A[pos].y, 1);
            pos++;
        }
        answers[e.pos] = query(0, 0, n - 1, e.left, e.right);
        //cerr << answers[e.pos] << endl;
    }

    sort(a, a + 9);
    cperm = 0;
    do {
        int sum;
        int xx[4], yy[4];
        xx[0] = yy[0] = -INF;

        sum = a[0] + a[1] + a[2];
        if (Y[sum - 1] == Y[sum]) continue;
        yy[1] = Y[sum - 1];
        sum += a[3] + a[4] + a[5];
        if (Y[sum - 1] == Y[sum]) continue;
        yy[2] = Y[sum - 1];
        sum += a[6] + a[7] + a[8];
        if (Y[sum - 1] == Y[sum]) continue;
        yy[3] = Y[sum - 1];

        sum = a[0] + a[3] + a[6];
        if (X[sum - 1] == X[sum]) continue;
        xx[1] = X[sum - 1];
        sum += a[1] + a[4] + a[7];
        if (X[sum - 1] == X[sum]) continue;
        xx[2] = X[sum - 1];
        sum += a[2] + a[5] + a[8];
        if (X[sum - 1] == X[sum]) continue;
        xx[3] = X[sum - 1];
            
        bool ok = true;
        for (int i = 1, k = 0; i <= 3; ++i) {
            for (int j = 1; j <= 3; ++j, ++k) {
                int cpos = permQ[cperm][k];
                int val = answers[cpos];
                if (k % 3 > 0) {
                    val -= answers[permQ[cperm][k - 1]];
                }
                if (val != a[k]) {
                    ok = false;
                }
            }
        }

        if (ok) {
            cout << setprecision(17) << fixed;
            cout << xx[1] + 0.5 << ' ' << xx[2] + 0.5 << '\n';
            cout << yy[1] + 0.5 << ' ' << yy[2] + 0.5 << '\n';
            return 0;
        }
        cperm++;
    } while(next_permutation(a, a + 9));

    cout << "-1\n";
}