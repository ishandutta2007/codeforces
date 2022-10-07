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
const int N = 5e5 + 10;
const long long INF = 1e9 + 19;

int n;
int k;
int c[N];

void read() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);
}

void solve() {
    long long sum = 0; 
    for (int i = 0; i < n; i++)
        sum += c[i];
    sort(c, c + n, greater < int > ());
    long long t = sum / n;
    long long g = sum % n;
    long long up = 0;
    for (int i = 0; i < n; i++) {
        long long h = t + (i < g);
        if (c[i] > h)
            up += c[i] - h;
    }
    if (up <= k) {
        if (g == 0)
            puts("0");
        else
            puts("1");
        return;
    }

    long long l = -1; 
    long long r = INF;
    for (; r - l > 1;) {
        long long mid = (l + r) / 2;
        long long up = 0;
        for (int i = 0; i < n; i++)
            if (c[i] > mid)
                up += c[i] - mid;
        //db2(up, mid);
        if (up <= k)
            r = mid;
        else
            l = mid;
    }

    long long h1 = r;

    l = -1;
    r = INF;
    for (; r - l > 1; ) {
        long long mid = (l + r) / 2;
        long long down = 0;
        for (int i = 0; i < n; i++)
            if (c[i] < mid) {
                down += mid - c[i];
            }
        if (down <= k)
            l = mid;
        else
            r = mid;
    }
    //db2(h1, l);
    cout << h1 - l << endl;


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