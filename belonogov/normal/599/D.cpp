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
typedef unsigned long long ull;


void read() {
    ull x;
    cin >> x;
    vector < pair < ull, ull> > answer;
    ull sum = 0;
    for (ull b = 1; ; b++) {
        sum += (b - 1) * 1ll * (b - 1);
        ull tmp = x - sum;
        tmp += b * 1ll * (b - 1) * 1ll * b / 2;
        //db(tmp);
        if (tmp <= 0) break;
        ull d = b * 1ll * b - b * 1ll * (b - 1) / 2;
        //db(d);
        if (tmp / d < b)
            break;
        if (tmp % d == 0) {
            answer.pb(mp(b, tmp / d));
            if (b != tmp / d)
                answer.pb(mp(tmp / d, b));
        }
    }
    sort(answer.begin(), answer.end());
    printf("%d\n", (int)answer.size());
    for (auto x: answer)
        printf("%lld %lld\n", x.fr, x.sc);
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