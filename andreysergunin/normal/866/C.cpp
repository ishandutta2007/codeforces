// MIPT Shock Content
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>
 
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

mt19937 rr(random_device{}());

const int MAXN = 52;
const int MAXM = 5200;
const double EPS = 1e-15;

double e[MAXN][MAXM];

int main() {

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, r;
    cin >> n >> r;
    vector<int> f(n), s(n);
    vector<double> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i] >> s[i] >> p[i];
        p[i] /= 100;
    }

    double lf = 0, rg = 1e9;
    for (int ops = 0; ops < 150; ++ops) {
        double exp = (lf + rg) / 2;
        for (int j = 0; j <= r; ++j)
            e[n][j] = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j <= r; ++j) {
                e[i][j] = min(exp, p[i] * (f[i] + (j >= f[i] ? e[i + 1][j - f[i]] : exp)) + 
                    (1 - p[i]) * (s[i] + (j >= s[i] ? e[i + 1][j - s[i]] : exp)));
            }
        }
        // cout << exp << " " << e[0][r] << endl;
        if (abs(1 - (exp / e[0][r])) < EPS) {
            lf = exp;
        } else {
            rg = exp;
        }
    }

    cout << fixed;
    cout.precision(12);
    cout << lf << endl;

}