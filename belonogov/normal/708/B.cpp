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
const int N = -1;
const long long INF = 1e9 + 19;

long long a00, a01, a10, a11;

void read() {
    cin >> a00 >> a01 >> a10 >> a11;
}

void ret() {
    puts("Impossible");
    exit(0);
}

int f(int cnt) {
    if (cnt == 0) {
        if (a01 + a10 == 0) return 0;
        return 1;
    }
    int res = 0;
    for (; res * 1ll * (res - 1) / 2 < cnt; res++);

    if (res * (res - 1) / 2 != cnt)
        ret();
    return res;
}


void solve() {
    if (a00 + a01 + a10 + a11 == 0) {
        puts("0");
        return;
    }
    int cnt0 = f(a00);
    int cnt1 = f(a11);

    //db2(cnt0, cnt1);
    if (cnt0 + cnt1 == 0) ret();
    if (cnt0 * cnt1 != a01 + a10) ret();
    string answer = string(cnt0, '0') + string(cnt1, '1');
    int need = a10;
    for (int i = 0; i < cnt1; i++) {
        if (need >= cnt0) {
            need -= cnt0;
            swap(answer[i], answer[i + cnt0]);
        } 
        else {
            swap(answer[i + cnt0 - need], answer[i + cnt0]);
            need = 0;
            break;
        }
    }
    //db(need);
    
    cout << answer << endl;

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