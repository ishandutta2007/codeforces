#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 600005;
const int BASE1 = 3137;
const int BASE2 = 31337;
const int MOD1 = 10007;
const int MOD2 = 1000000007;

int N, M;
char s[MAXN];
map <pii, bool> bio;

inline int add1(int x, int y) {
    x += y;
    if (x >= MOD1) x -= MOD1;
    else if (x < 0) x += MOD1;
    return x;
}

inline int mul1(int x, int y) {
    return (long long)x * y % MOD1;
}

inline int add2(int x, int y) {
    x += y;
    if (x >= MOD2) x -= MOD2;
    else if (x < 0) x += MOD2;
    return x;
}

inline int mul2(int x, int y) {
    return (long long)x * y % MOD2;
}

int hash1() {
    int res = 0;
    for (int i = 0; s[i]; i++) 
        res = add1(mul1(res, BASE1), s[i]);
    return res;
}

int hash2() {
    int res = 0;
    for (int i = 0; s[i]; i++) 
        res = add2(mul2(res, BASE2), s[i]);
    return res;
}

void load() {
    scanf("%d%d", &N, &M);
    while (N--) {
        scanf("%s", s);
        bio[pii(hash1(), hash2())] = true;      
    }
}

bool check() {
    int h1 = hash1(), h2 = hash2(), pot1 = 1, pot2 = 1;
    for (int i = strlen(s) - 1; i >= 0; i--) {
        for (char c = 'a'; c <= 'c'; c++)
            if (c != s[i] && bio[pii(add1(h1, mul1(c - s[i], pot1)), add2(h2, mul2(c - s[i], pot2)))]) 
                return true; 
        pot1 = mul1(pot1, BASE1);
        pot2 = mul2(pot2, BASE2);
    }
    return false;
}

void solve() {
    while (M--) {
        scanf("%s", s);
        puts(check() ? "YES" : "NO");
    }
}

int main() {
    load();
    solve();
    return 0;
}