#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#define double long double
#define P 1009

using namespace std;

typedef long long ll;

int n, m, k;

struct comp {
    double a, b;
    comp() {}
    comp(double _1, double _2) {a = _1, b = _2;}
    comp operator + (const comp& X) {return comp(a + X.a, b + X.b);}
    comp operator - (const comp& X) {return comp(a - X.a, b - X.b);}
    comp operator * (const comp& X) {return comp(a * X.a - b * X.b, a * X.b + b * X.a);}
};

int Rev[1 << 19];

comp A[1 << 19], B[1 << 19], C[1 << 19];

double pi = M_PI;

void DFT(comp *A, int tot) {
    for(int i = 0; i < tot; i++) if(Rev[i] > i) swap(A[i], A[Rev[i]]);
    for(int i = 1, h = tot / 2; i < tot; i *= 2, h >>= 1)
        for(int j = 0; j < tot; j += i + i)
            for(int k = 0; k < i; k++) {
                comp X = A[j + k], Y = A[j + k + i], O = C[h * k];
                A[j + k] = X + Y * O;
                A[j + k + i] = X - Y * O;
            }
}

void convo(vector <int> &X, vector <int> &Y) {
    int tot = 1, lx = (int) X.size() - 1, ly = (int) Y.size() - 1;
    while(tot <= lx + ly) tot *= 2;
    for(int i = 1; i < tot; i++) Rev[i] = Rev[i / 2] / 2 + (i & 1) * (tot / 2);
    for(int i = 0; i < tot; i++) A[i] = comp(0, 0), B[i] = comp(0, 0);
    for(int i = 0; i <= lx; i++) A[i].a = X[i];
    for(int i = 0; i <= ly; i++) B[i].a = Y[i];
    C[0] = comp(1, 0);
    C[1] = comp(cos(2 * pi / tot), sin(2 * pi / tot));
    for(int i = 2; i < tot; i++) C[i] = C[i / 2] * C[i - i / 2];
    DFT(A, tot);
    DFT(B, tot);
    for(int i = 0; i < tot; i++) A[i] = A[i] * B[i];
    reverse(C + 1, C + tot);
    DFT(A, tot);
    Y.clear();
    X.resize(lx + ly + 1);
    for(int i = 0; i <= lx + ly; i++) X[i] = (long long) (A[i].a / tot + 0.5) % P;
}

vector <int> V[1 << 19];

int V1[1 << 19], V2[1 << 19], t1 = 0, w1 = 1, t2 = 0, w2 = 1;

bool cmp(int x, int y) {
    return V[x].size() < V[y].size();
}

int get() {
    if(t1 < w1) return V2[w2++];
    if(t2 < w2) return V1[w1++];
    return V[V1[w1]].size() < V[V2[w2]].size() ? V1[w1++] : V2[w2++];
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++) V[i].push_back(1);
    for(int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        V[a].push_back(1);
    }
    for(int i = 1; i <= n; i++) V1[++t1] = i;
    sort(V1 + 1, V1 + m + 1, cmp);
    for(int i = 1; i < n; i++) {
        int a = get(), b = get();
        convo(V[a], V[b]);
        V2[++t2] = a;
    }
    printf("%d\n", (V[get()][k] % P + P) % P);
    return 0;
}