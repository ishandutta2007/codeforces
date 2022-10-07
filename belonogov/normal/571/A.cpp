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

#define equal equalll
#define less lesss
const int N = -1;
const int INF = 1e9 + 19;

long long a, b, c, l;
long long answer;

void read() {
    cin >> a >> b >> c >> l;
}

long long getT(long long x) {
    return x * (x + 1) / 2;
}
long long sqr(long long a) {
    return a * a;
}

void solve() {
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);

    for (int i = 0; i <= l; i++) {
        long long cc = c + i;
        long long add = 0;
        int ll = l - i;
        if (ll + a + b <= cc) continue;

        add += getT(l - i + 1);
        //db(add);
        if (a + b <= cc)
            add -= getT(cc - a - b + 1);

        for (int tt = 0; tt < 2; tt++) {
            //db2(l + b, cc + a);
            if (ll + b >= cc + a) {
                long long len = ll + b - cc - a + 1;
                if (len % 2 == 1)
                    add -= sqr((len + 1) / 2);
                else
                    add -= 2 * getT(len / 2);
            }
            swap(a, b);
        }
        answer += add;
    }
    cout << answer << endl;

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