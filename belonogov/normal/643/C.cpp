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
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 2e5 + 10;
const long long INF = 1e9 + 19;
const int K = 55;

bool equal(double a, double b) {
    return abs(a - b) < 1e-9;
}

struct Line {
    double A, B;
    Line() { }
    Line(double A, double B): A(A), B(B) { }
    double operator * (Line l) {
        assert(!equal(A, l.A));
        return (l.B - B) / (A - l.A);
    }
    double getY(double x) {
        return A * x + B;
    }
};

int n, k;
int t[N];
double dp[N][K];
long long pref[N];
double invP[N];
vector < Line > st[K];
int cur[N];

Line createLine(int pos, double val) {
    return Line(-pref[pos], val + pref[pos] * invP[pos]);
}

void addLine(int j, Line l) {
    //db3(j, l.A, l.B);
    for (; st[j].size() >= 2; ) {
        double prevX = st[j][st[j].size() - 1] * st[j][st[j].size() - 2]; 
        double newX = st[j][st[j].size() - 1] * l;
        if (newX < prevX) 
            st[j].pop_back();
        else
            break;
    }
    st[j].pb(l);

}

void read() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);
}

void solve() {
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + t[i];

    
    for (int i = 0; i < n; i++)
        invP[i + 1] = invP[i] + 1.0 / t[i];

    //for (int i = 0; i <= n; i++)
        //db2(t[i], invP[i]);


    for (int i = 0; i < k; i++) {
        addLine(i, createLine(0, 0));
    }
    
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = 1e18;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            //db2(i, j);
            cur[j] = min(cur[j], (int)st[j].size() - 1);
            for (; cur[j] + 1 < (int)st[j].size(); ) {
                double x = st[j][cur[j]] * st[j][cur[j] + 1];
                if (x < invP[i + 1]) {
                    cur[j]++;
                }
                else
                    break;
            }            
            double y = st[j][cur[j]].getY(invP[i + 1]);
            //db(invP[i + 1]);
            dp[i + 1][j + 1] = y;
            addLine(j + 1, createLine(i + 1, y));
        }
    }


    double shift = 0;
    for (int i = 0; i < n; i++)
        shift += 1.0 / t[i] * pref[i + 1];

    printf("%.17f\n", shift + dp[n][k]);
}

void stress() {

}


int main(){
#ifdef MY_DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}