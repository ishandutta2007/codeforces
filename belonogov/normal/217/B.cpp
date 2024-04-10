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
const int N = -1;
const long long INF = 1e9 + 19;

int n, r;

void read() {
    scanf("%d%d", &n, &r);
}

void solve() {
    int best = -1;
    int where = -1;
    for (int i = 0; i <= r; i++) {
        int a = r;
        int b = i;
        int cnt = 0; 
        if (__gcd(a, b) != 1) continue;
        int iter = 0;
        for (; b > 0; ) {
            assert(a >= b);
            int tmp = a % b;
            int d = a / b;
            if (b == 1 && a != 1) {
                d--;
                tmp = 1;
            }
            cnt += d;
            a = b;
            iter++;
            b = tmp;
        }
        assert(a == 1);
        //if (cnt < n)
            //iter++;
        if (iter > best && cnt == n) {
            where = i;
            best = iter;
        }
    }
    //db2(best, where);
    
    if (best == -1) {
        puts("IMPOSSIBLE");
        return;
    }

    vector < int > res;

    int a = r;
    int b = where;
    int iter = best;
    for (;b > 0; ) {
        assert(a >= b);
        int tmp = a % b;
        int d = a / b;
        if (b == 1 && a != 1) {
            d--;
            tmp = 1;
        }
        for (int i = 0; i < d; i++)
            res.pb(iter % 2);
        a = b;
        b = tmp;
        iter--;
    }
    assert((int)res.size() <= n);
    for (; (int)res.size() < n; ) {
        res.pb(0);
    }
    reverse(res.begin(), res.end());
    int cnt = 0;
    for (int i = 0; i < (int)res.size() - 1; i++)
        cnt += res[i] != res[i + 1];

    a = 0;
    b = 1;
    for (int i = 0; i < (int)res.size(); i++)
        if (res[i])
            a += b;
        else
            b += a; 
    //db2(a, b);
    //assert(max(a, b) == r);
    printf("%d\n", n - 1 - cnt);
    for (auto x: res)
        if (x)
            printf("T");      
        else
            printf("B");
    puts("");

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