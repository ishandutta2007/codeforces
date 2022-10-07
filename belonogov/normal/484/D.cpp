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

int n;
int a[N];
bool use[N];
long long dp[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void solve() {
    long long answer = 0; 
    for (int i = 1; i < n - 1; i++) {
        if (a[i - 1] <= a[i] && a[i] >= a[i + 1]) {
            use[i] = 1;
        }
        if (a[i - 1] >= a[i] && a[i] <= a[i + 1]) {
            use[i] = 1;
        }
    } 
    for (int i = 0; i < n - 1; i++)
        if (!use[i] && !use[i + 1])
            answer += abs(a[i] - a[i + 1]);


    for (int i = 0; i < n; ) {
        for (; i < n && !use[i]; i++);
        int j = i;
        for (; i < n && use[i]; i++);
        if (i > j) {
            dp[j - 1] = 0;
            dp[j] = 0;
            for (int k = j; k <= i; k++) {
                dp[k + 1] = max(dp[k + 1], dp[k - 1]) + abs(a[k - 1] - a[k]);
                dp[k + 1] = max(dp[k + 1], dp[k]);
            }
            answer += max(dp[i + 1], dp[i]);
        }
    } 


    cout << answer << endl;
}

void printAns() {

}

void stress() {

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
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}