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

int a[N];
int cnt[N];
int n, k;

void read() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void solve() {
    int r = 0;
    int g = 0;
    int al = -1, ar = -1;
    for (int l = 0; l < n; l++) {
        for (;;) {
            if (r == n) break;
            if (cnt[a[r]] > 0) {
                cnt[a[r]]++;
                r++;
            }
            else {
                if (g < k) {
                    cnt[a[r]]++;
                    g++;
                    r++;
                }  
                else
                    break;
            }
        } 
        if (r - l > ar - al) {
            al = l;
            ar = r;
        }
        cnt[a[l]]--;
        if (cnt[a[l]] == 0) 
            g--;
    }
    printf("%d %d\n", al + 1, ar);

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