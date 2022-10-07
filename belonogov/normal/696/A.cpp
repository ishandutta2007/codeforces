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
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;

int n;
int type[N];
long long v[N];
long long u[N];
int w[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%lld%lld", &type[i], &v[i], &u[i]);
        if (type[i] == 1)
            scanf("%d", &w[i]);
    }

}

int getLevel(long long v) {
    int h = 0;
    for (; v > 0; v /= 2, h++);
    return h;
}

long long getLCA(long long v, long long u) {
    int hv = getLevel(v);    
    int hu = getLevel(u);
    if (hv < hu) {
        swap(v, u);
        swap(hv, hu);
    }
    for (; hv > hu; hv--, v /= 2);
    for (; v != u; v /= 2, u /= 2);
    return v;
}

int getInter2(long long v, long long u) {
    return getLevel(getLCA(v, u));
}

int getInter(long long v, long long A, long long u, long long B) {
    return getInter2(v, u) - getInter2(v, B) - getInter2(A, u) + getInter2(A, B);
}

void solve() {
    for (int i = 0; i < n; i++) {
        if (type[i] == 2) {
            long long answer = 0;
            for (int j = 0; j < i; j++)
                if (type[j] == 1) {
                    long long A = getLCA(v[i], u[i]);
                    long long B = getLCA(v[j], u[j]);
                    answer += getInter(v[i], A, v[j], B) * 1ll * w[j];
                    answer += getInter(v[i], A, u[j], B) * 1ll * w[j];
                    answer += getInter(u[i], A, v[j], B) * 1ll * w[j];
                    answer += getInter(u[i], A, u[j], B) * 1ll * w[j];

                }
        

            printf("%lld\n", answer);
        }
    }

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