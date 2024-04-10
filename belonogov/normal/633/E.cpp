#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;
const int T = 21;

int n, k;
int a[N];
int b[N];
int f[N];
int minTree[T][N];
int maxTree[T][N];
int deg[N];


void read() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    for (int i = 0; i < n; i++)
        a[i] *= 100;
}

int getMax(int l, int r) {
    int len = r - l;
    int j = deg[len];
    return max(maxTree[j][l], maxTree[j][r - (1 << j)]);
}


int getMin(int l, int r) {
    int len = r - l;
    int j = deg[len];
    return min(minTree[j][l], minTree[j][r - (1 << j)]);
}


double solve() {
    deg[1] = 0;
    for (int i = 2; i <= n; i++)
        deg[i] = deg[i / 2] + 1;


    for (int i = 0; i < n; i++) {
        minTree[0][i] = b[i];
        maxTree[0][i] = a[i];
    }
    for (int j = 1; j < T; j++)
        for (int i = 0; i + (1 << j) <= n; i++) {
            minTree[j][i] = min(minTree[j - 1][i], minTree[j - 1][i + (1 << (j - 1))]);
            maxTree[j][i] = max(maxTree[j - 1][i], maxTree[j - 1][i + (1 << (j - 1))]);
        }
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cur = max(cur, i + 1);
        for (; cur + 1 <= n;) {
            if (getMax(i, cur + 1) < getMin(i, cur + 1))
                cur++;
            else 
                break;
        }
        int r =  min(getMax(i, cur), getMin(i, cur));
        if (cur + 1 <= n)
            r = max(r, min(getMax(i, cur + 1), getMin(i, cur + 1)));
        f[i] = r;
    } 
    sort(f, f + n);
    //for (int i = 0; i < n; i++)
        //cerr << f[i] << " ";
    //cerr << endl;
    double answer = 0;
    double cof = 1;
    for (int i = 0; i < n; i++) {
        double curCof = k * 1.0 / (n - i);
        answer += f[i] * cof * curCof;
        cof *= (1 - curCof);
        if (cof < 1e-30) break;
        if (k == n - i) break;
    }

    return answer;
}


void genTest() {
    n = 30;
    k = rand() % n + 1;
    int T = 100;
    for (int i = 0; i < n; i++)
        a[i] = rand() % T + 1;
    for (int i = 0; i < n; i++)
        b[i] = rand() % T + 1;
}


double stupid() {
    vector < int > f; 
    for (int l = 0; l < n; l++) {
        int best = -INF;
        for (int r = l + 1; r <= n; r++) {
            int mn = INF;
            for (int i = l; i < r; i++)
                mn = min(b[i], mn);
            int mx = -INF;
            for (int i = l; i < r; i++)
                mx = max(a[i], mx);
            int res = min(mn, mx);
            best = max(best, res);
        }
        f.pb(best);
    }
    //for (int i = 0; i < (int)f.size(); i++)
        //cerr << f[i] << " ";
    //cerr << endl;
    sort(f.begin(), f.end());

    double cof = 1;
    double answer = 0;
    for (int i = 0; i < n; i++) {
        double tmp = k * 1.0 / (n - i);
        answer += f[i] * cof * tmp;
        cof *= (1 - tmp);
    }
    return answer;
}

void printTest() {
    cerr << n << " " << k << endl;
    for (int i = 0; i < n; i++)
        cerr << a[i] << " ";
    cerr << endl;
    for (int i = 0; i < n; i++)
        cerr << b[i] * 100 << " ";
    cerr << endl;
}

void stress() {
    for (int it = 0;; it++) {
        db(it);
        genTest();
        double r1 = solve();
        double r2 = stupid();
        printTest();
        db2(r1, r2);
        assert(abs(r1 - r2) < 1e-9);
    }

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            printf("%.17f\n", solve());
            //printf("%.17f\n", stupid());
        }
    }
    else {
        stress();
    }

    return 0;
}