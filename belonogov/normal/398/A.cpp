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
const long long INF = 1e18 + 19;

int a, b;

long long sqr(int x) {
    return x * 1ll * x;
}

void read() {
    long long answer = -INF;
    int where = -1;
    cin >> a >> b;
    if (a == 0) {
        printf("%lld\n", -sqr(b));
        for (int i = 0; i < b; i++)
            printf("x");
        puts("");
        return;
    }
    for (int i = 1; i <= a; i++) {
        int cnt = i + 1;
        long long r = (i - 1) + sqr(a - (i - 1));
        long long d = b / cnt;
        int cntBig = b % cnt;
        r -= cntBig * sqr(d + 1);
        r -= (cnt - cntBig) * sqr(d);
        if (r > answer) {
            answer = r;
            where = i;
        }
    }
    db(where);
    db(answer);
        
    assert(where != -1);

    int cnt = where + 1;
    long long d = b / cnt;
    int cntBig = b % cnt;

    cout << answer << endl;
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < d; j++)
            printf("x");  
        if (cntBig > 0) {
            cntBig--;
            printf("x");
        }
        if (i + 1 == cnt) break;
        if (i == 0)
            for (int j = 0; j < a - (where - 1); j++)
                printf("o");
        else
            printf("o");
    }
    puts("");


}

void solve() {

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