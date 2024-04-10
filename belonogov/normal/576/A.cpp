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
const int N = -1;
const int INF = 1e9 + 19;

int n;

bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return 0;
    return 1;
}

void read() {
    scanf("%d", &n);
    vector < int > ans;
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            int h = i;
            for (; h <= n; h *= i)
                ans.pb(h); 
        }
    }
    sort(all(ans));
    printf("%d\n", (int)ans.size());
    for (auto x: ans)
        printf("%d ", x);
    printf("\n");
}

void solve() {

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