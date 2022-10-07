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

#define equal equalll
#define less lesss
const int N = 3e5 + 10;
const int INF = 1e9 + 19;

int n, k;
int a[N];
unordered_map < int, int > dp[N];

void read() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) 
        scanf("%d", &a[i]);
}

void upd(int & a, int b) {
    a = max(a, b);
}

void solve() {
    sort(a, a + n);
    a[n] = a[n - 1];
    dp[0][0] = 0; 
    int l1 = n / k; 
    int l2 = l1 + 1;
    int m2 = n % k;
    int m1 = k - m2;
    //db2(m1, m2);
    //db2(l1, l2);
    for (int i = 0; i < n; i++) {
        for (auto x: dp[i]) {
            int res = x.sc;
            int t1 = x.fr;
            int t2 = (i - x.fr * l1) / l2;
            assert((i - x.fr * l1) % l2 == 0);
            if (t1 + 1 <= m1) 
                upd(dp[i + l1][t1 + 1], res + a[i + l1] - a[i + l1 - 1]);
            if (t2 + 1 <= m2) 
                upd(dp[i + l2][t1], res + a[i + l2] - a[i + l2 - 1]);
        }
    }
    //for (int i = 0; i <= n; i++) {
        //cerr << endl;
        //for (auto x: dp[i])
            //db2(x.fr, x.sc);
    //}

    assert(dp[n].count(m1) == 1);
    cout << a[n - 1] - a[0] - dp[n][m1] << "\n";
}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("test.txt", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}