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
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;


int n;
pair < int, int > a[N];
int b[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].fr, &a[i].sc);
    }
}

void solve() {
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(a, a + n, mp(a[i].fr - a[i].sc, - 1)) - a;
        pos--;
        //db(pos);
        if (pos < 0)
            b[i] = 1;
        else
            b[i] = b[pos] + 1;
    }

    int mx = 0;
    for (int i = 0; i < n; i++)
        mx = max(mx, b[i]);
    cout << (n - mx) << endl;
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