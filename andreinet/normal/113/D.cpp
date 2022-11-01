#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
#define WRITE(x) (cerr << #x << ' ' << (x) << endl)
using namespace std;

typedef long long i64;
const int NMAX = 25, MMAX = 1005, RMAX = NMAX * NMAX + NMAX;
const double EPS = 1e-10;

double A[RMAX][RMAX];
double aux[RMAX];
double X[RMAX];

int to[MMAX], nextEdge[MMAX], firstEdge[NMAX];
int edges;
int deg[NMAX];

double stay[NMAX];

void addEdge(int x, int y) {
    to[edges] = y;
    nextEdge[edges] = firstEdge[x];
    firstEdge[x] = edges++;
    deg[x]++;
}

void gauss(int n, int m, int r) {
    for (int i = 0, j = 0; i < n && j < m; ) {
        int k;
        for (k = i; k < n && abs(A[k][j]) < EPS; ++k);
        
        if (k == n) {
            ++j;
            continue;
        }

        {
            memcpy(aux, A[k], sizeof aux);
            memcpy(A[k], A[i], sizeof A[k]);
            memcpy(A[i], aux, sizeof A[i]);
        }

        for (int k = j + 1; k < r; ++k) {
            A[i][k] /= A[i][j];
        }
        A[i][j] = 1;

        for (int k = i + 1; k < n; ++k) {
            for (int p = j + 1; p < r; ++p) {
                A[k][p] -= A[k][j] * A[i][p];
            }
            A[k][j] = 0;
        }

        i++;
        j++;
    }
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    cout << setprecision(17) << fixed;

    int n, m, a, b;
    cin >> n >> m >> a >> b;
    a--; b--;

    if (a == b) {
        for (int i = 0; i < n; ++i) {
            cout << (i == a ? 1.0: 0.0) << ' ';
        }
        cout << '\n';
        return 0;
    }

    memset(firstEdge, -1, sizeof firstEdge);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        addEdge(x, y);
        addEdge(y, x);
    }

    for (int i = 0; i < n; ++i)
        cin >> stay[i];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            double s = stay[i] * stay[j];
            A[i * n + j][i * n + j] = 1 - s;
            double s1 = stay[i], s2 = stay[j];
            double m1 = (1 - stay[i]) * (1.0L / deg[i]);
            double m2 = (1 - stay[j]) * (1.0L / deg[j]);
            for (int p1 = firstEdge[i]; p1 != -1; p1 = nextEdge[p1]) {
                int ni = to[p1], nj = j;
                double p = m1 * s2;
                if (ni == nj) {
                    A[i * n + j][n * n + ni] = p;
                } else {
                    A[i * n + j][ni * n + nj] = -p;
                }
            }
            for (int p2 = firstEdge[j]; p2 != -1; p2 = nextEdge[p2]) {
                int ni = i, nj = to[p2];
                double p = s1 * m2;
                if (ni == nj) {
                    A[i * n + j][n * n + ni] = p;
                } else {
                    A[i * n + j][ni * n + nj] = -p;
                }
            }
            for (int p1 = firstEdge[i]; p1 != -1; p1 = nextEdge[p1]) {
                for (int p2 = firstEdge[j]; p2 != -1; p2 = nextEdge[p2]) {
                    int ni = to[p1], nj = to[p2];
                    double p = m1 * m2;
                    if (ni == nj) {
                        A[i * n + j][n * n + ni] = p;
                    } else {
                        A[i * n + j][ni * n + nj] = -p;
                    }
                }
            }
        }
    }
//    cerr << "BEFORE:" << endl;
//    for (int i = 0; i < n * n; ++i) {
//        for (int j = 0; j < n * n + n; ++j) {
//            cerr << A[i][j] << ' ';
//        }
//        cerr << endl;
//    }

    gauss(n * n, n * n, n * n + n);

//    cerr << "AFTER: " << endl;
//    for (int i = 0; i < n * n; ++i) {
//        for (int j = 0; j < n * n + n; ++j) {
//            cerr << A[i][j] << ' ';
//        }
//        cerr << endl;
//    }
    for (int p = 0; p < n; ++p) {
        memset(X, 0, sizeof X);
        for (int i = n * n - 1; i >= 0; --i) {
            int j, l = n * n;
            for (j = 0; j < l && abs(A[i][j]) < EPS; ++j);
            if (j == l) {
                if (abs(A[i][l + p]) > EPS) throw -1337;
                else continue;
            }

            double val = A[i][l + p];
            for (int k = j + 1; k < l; ++k)
                val -= X[k] * A[i][k];
            X[j] = val;
        }
        cout << X[a * n + b] << '\n';
    }
}