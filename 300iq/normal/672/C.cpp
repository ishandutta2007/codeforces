#include <bits/stdc++.h>
#define mp make_pair
#define fc first
#define sc second

using namespace std;

typedef long long ll;

const int MAXN = 100000;

int x[MAXN], y[MAXN];
bool used[MAXN];

ll sqr(ll x) {
    return x * x;
}

double skr(double x) {
    return x * x;
}

double dist(double a, double b, double c, double d) {
    return sqrt(skr(a - c) + sqr(b - d));
}


int main() {
    cout.precision(20);
    ios_base::sync_with_stdio(0);
    #ifdef __linux__ 
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int ax, ay, bx, by, tx, ty, n;
    cin >> ax >> ay >> bx >> by >> tx >> ty;
    cin >> n;
    double ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        ans += 2 * dist(tx, ty, x[i], y[i]);
    }
    double t = ans;
    {
        bool can = false;
        int j = -1;
        double res = INT_MAX;
        for (int i = 0; i < n; i++) {
            double bns = ans - dist(tx, ty, x[i], y[i]) + dist(ax, ay, x[i], y[i]);
            if ((j == -1 || bns < res)) {
                j = i;
                res = bns;
            }
        }
        int cnt = 0;
        if (j != -1) {
            ans = res;
            used[j] = 1;
            cnt = 1;
        } 
        res = ans;
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                ans = min(ans, res - dist(tx, ty, x[i], y[i]) + dist(bx, by, x[i], y[i]));
                if (ans == res - dist(tx, ty, x[i], y[i]) + dist(bx, by, x[i], y[i])) {
                    cnt = 1;
                }
            }
        }
    }
    {
        memset(used, 0, sizeof used);
        bool can = false;
        int j = -1;
        double res = INT_MAX;
        for (int i = 0; i < n; i++) {
            double bns = t - dist(tx, ty, x[i], y[i]) + dist(bx, by, x[i], y[i]);
            if ((j == -1 || bns < res)) {
                j = i;
                res = bns;
            }
        }
        if (j != -1) {
            t = res;
            used[j] = 1;
        } 
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                t = min(t, res - dist(tx, ty, x[i], y[i]) + dist(ax, ay, x[i], y[i]));
            }
        }   
    }
    cout << min(ans, t) << endl;
}