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

int n, q;
int a[N];
int b[N];
pair < int, int > st[N];

void read() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++)
        b[i] = abs(a[i] - a[i + 1]);
    for (int j = 0; j < q; j++) {
        int l, r;
        scanf("%d%d", &l, &r); l--; r--;
        long long answer = 0;
        long long sum = 0;
        int cur = 0;
        for (int i = l; i < r; i++) {
            int cnt = 1;
            for (; cur > 0 && st[cur - 1].fr < b[i]; cur--) {
                cnt += st[cur - 1].sc;
                sum -= st[cur - 1].sc * 1ll * st[cur - 1].fr;
            }
            st[cur++] = mp(b[i], cnt); 
            sum += b[i] * 1ll * cnt;
            answer += sum;
        }

        cout << answer << "\n";
    }
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