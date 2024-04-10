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
const int N = 1e6;
const long long INF = 1e9 + 19;
const int MOD = 1e9 + 7;

int n;
int p[N];
int mx;
long long pref[N];
long long suf[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        mx = max(mx, x);
        p[x]++;
    }
}

long long rev(long long a, long long m) {
    if (a == 1) return 1;
    return ((1 - rev(m % a, a) * m) / a + m) % m;
}

long long binPow(long long a, long long b) {
    //db(b);
    long long res = 1;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
    }
    return res;
}

void solve() {
    long long answer = 1;
    pref[0] = 1;
    suf[mx + 1] = 1;
    for (int i = 1; i <= mx; i++)
        pref[i] = pref[i - 1] * (p[i] + 1) % (MOD - 1);
    for (int i = mx; i >= 0; i--)
        suf[i] = suf[i + 1] * (p[i] + 1) % (MOD - 1);
    

    for (int i = 1; i <= mx; i++) {
        if (p[i] > 0) {
            long long tmp = pref[i - 1] * suf[i + 1] % (MOD - 1);
            answer = answer * binPow(i, tmp * (((p[i] + 1) * 1ll * p[i] / 2) % (MOD - 1)) % (MOD - 1)) % MOD;
        }
    }   
    cout << answer << endl;

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