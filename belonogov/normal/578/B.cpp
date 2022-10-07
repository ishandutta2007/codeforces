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
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 2e5 + 10;
const int INF = 1e9 + 19;

int n, k, x;
int a[N];
long long p[N];
long long s[N];

void read() {
    scanf("%d%d%d", &n, &k, &x);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void solve() {
    for (int i = 0; i < n; i++)
        p[i + 1] = p[i] | a[i];
    for (int i = n - 1; i >= 0; i--)
        s[i] = s[i + 1] | a[i];
    long long add = 1; 
    for (int i = 0; i < k; i++)
        add *= x;
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        long long r = p[i] | s[i + 1] | (a[i] * add);
        answer = max(answer, r);
    }
    cout << answer << "\n";
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