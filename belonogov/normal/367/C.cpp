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
const int N = 2e6 + 10;
const long long INF = 1e9 + 19;


int n, m;
int w[N];

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d%d", &x, &w[i]);
    }
}

int f(int i) {
    if (i % 2 == 1)
        return i / 2 * i + 1;
    return i / 2 * i;
}

void solve() {
    for (int i = 1; i <= 10; i++)
        db2(i, f(i));
    sort(w, w + m);
    reverse(w, w + m);
    
    int mx = 0;
    for (int i = 1; ; i++) {
        if (n >= f(i))
            mx = i;
        else
            break;
    }
    //db(mx);
    long long sum = 0;
    for (int i = 0; i < min(m, mx); i++)
        sum += w[i];
    printf("%lld\n", sum);

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
        }
    }
    else {
        stress();
    }

    return 0;
}