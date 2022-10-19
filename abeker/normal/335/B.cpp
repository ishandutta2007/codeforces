#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <string>
using namespace std;

const int MAXM = 50005;
const int MAXN = 2575;
const int INF = 0x3f3f3f3f;

int N;
char s[MAXM];
int cnt[30];
int dp[MAXN][MAXN];
int l[MAXN][MAXN], r[MAXN][MAXN];
int first[MAXN][30];
int last[MAXN][30];

void load() {
    scanf("%s", s + 1);
}

int rec(int lo, int hi) {
    if (lo < 0 || hi > N + 1) return -INF;
    int &ref = dp[lo][hi];
    if (ref != -1) return ref;
    if (!lo || hi == N + 1) return ref = 0;
    int a = 1 + rec(lo - 1, first[hi][s[lo] - 'a'] + 1);
    int b = 1 + rec(last[lo][s[hi] - 'a'] - 1, hi + 1);
    int c = rec(lo - 1, hi + 1);
    int &L = l[lo][hi], &R = r[lo][hi];
    if (a > ref) { ref = a; L = lo; R = first[hi][s[lo] - 'a']; }
    if (b > ref) { ref = b; L = last[lo][s[hi] - 'a']; R = hi; } 
    if (c > ref) { ref = c; L = l[lo - 1][hi + 1]; R = r[lo - 1][hi + 1]; }
    return ref;
}

void output(int lo, int hi, int len, string mid) {
    string suff = "";
    while (len--) {
        suff += s[l[lo][hi]];
        int lo1 = l[lo][hi] - 1;
        int hi1 = r[lo][hi] + 1;
        lo = lo1;
        hi = hi1;
    }
    string pref = suff;
    reverse(pref.begin(), pref.end());
    pref += mid + suff;
    puts(pref.c_str());
}

void solve() {
    N = strlen(s + 1);
    for (int i = 1; i <= N; i++)
        cnt[s[i] - 'a']++;

    for (int i = 0; i < 26; i++) {
        if (cnt[i] < 100) continue;
        for (int j = 0; j < 100; j++)
            printf("%c", 'a' + i);
        puts("");
        return;
    }
    
    assert(N < MAXN);
    
    for (int i = 1; i <= N; i++) {
        memcpy(last[i], last[i - 1], sizeof last[i]);
        last[i][s[i] - 'a'] = i;
    }
    
    for (int j = 0; j < 26; j++)
        first[N + 1][j] = N + 1;
    for (int i = N; i; i--) {
        memcpy(first[i], first[i + 1], sizeof first[i]);
        first[i][s[i] - 'a'] = i;
    }
    
    memset(dp, -1, sizeof dp);
    int even = 0, odd = 1;
    for (int i = 1; i <= N; i++) {
        if (rec(i, i + 1) > rec(even, even + 1)) even = i;
        if (rec(i - 1, i + 1) > rec(odd - 1, odd + 1)) odd = i;
    }
      
    int a = rec(even, even + 1);
    int b = rec(odd - 1, odd + 1);
    if (a < 50) {
        string m = "";
        m += s[odd];
        if (a > b)
            output(even, even + 1, a, "");
        else 
            output(odd - 1, odd + 1, b, m);
        return;
    }
    output(even, even + 1, 50, "");
}

int main() {
    load();
    solve();
    return 0;
}