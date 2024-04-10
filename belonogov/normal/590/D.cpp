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
const int N = 155;
const long long INF = 1e9 + 19;

int n, k, s;
vector < int > a, b;
int gap;
int dp1[N][N * N];
int dp2[N][N * N];
int r1[N][N * N];
int r2[N][N * N];


void read() {
    scanf("%d%d%d", &n, &k, &s);
    a.resize(k);
    for (int i = 0; i < k; i++)
        scanf("%d", &a[i]);

    b.resize(n - k);
    for (int i = 0; i < n - k; i++)
        scanf("%d", &b[i]);
}

void upd(int & a, int b) {
    a = max(a, b);
}

void calc(vector < int > a) {
    memset(dp1, -63, sizeof(dp1)); 

    dp1[0][0] = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        memset(dp2, -63, sizeof(dp2)); 
        for (int j = 0; j <= i; j++)
            for (int k = 0; k <= j * (i - j); k++) {
                upd(dp2[j][k], dp1[j][k]);
                upd(dp2[j + 1][k + (i - j)], dp1[j][k] + a[i]);
            }
        memcpy(dp1, dp2, sizeof(dp1));
    }
    for (int i = 0; i <= (int)a.size(); i++) {
        int tmp = -INF;
        for (int j = 0; j <= (int)a.size() * (int)a.size(); j++) {
            tmp = max(tmp, dp1[i][j]);
            dp1[i][j] = tmp;
        }
    }
}

void solve() {
    reverse(a.begin(), a.end());
    calc(a);
    memcpy(r1, dp1, sizeof(dp1));
    //for (int i = 0; i < 5; i++, cerr << endl)
        //for (int j = 0; j < 5; j++)
            //cerr << r1[i][j] << " "; 
    for (auto &x: b)
        x *= -1;
    calc(b);
    memcpy(r2, dp1, sizeof(dp1));
    //for (int i = 0; i < 5; i++, cerr << endl)
        //for (int j = 0; j < 5; j++)
            //cerr << r2[i][j] << " ";

    int sum = 0; 
    for (auto x: a)
        sum += x; 

    gap = min(k, n - k);

    int mn = 0;
    s = min(s, n * (n - 1) / 2);

    for (int t = 1; t <= gap; t++) {
        int rem = s - t * t;
        if (rem >= 0) {
            for (int i = 0; i <= rem; i++)
                mn = min(mn, (-r2[t][i]) - r1[t][rem - i]);
        }

    }



    cout << sum + mn << endl;
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