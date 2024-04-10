// Author: wlzhouzhuan
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#include <immintrin.h>
#include <nmmintrin.h>
using namespace std;

const int N = 200005;

char a[N];
int n, q;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%hhi", &a[i]);
    scanf("%d", &q);
    while (q--) {
        int l, r; char x, y;
        scanf("%d%d%hhi%hhi", &l, &r, &x, &y);
        __m256i org = _mm256_set1_epi8(x), to = _mm256_set1_epi8(y);
        for (; l + 31 <= r; l += 32) {
            __m256i now = _mm256_loadu_si256((__m256i*) &a[l]);
            now = _mm256_blendv_epi8(now, to, _mm256_cmpeq_epi8(now, org));
            _mm256_storeu_si256((__m256i*) &a[l], now);
        }
        for (; l <= r; l++) {
            if (a[l] == x) a[l] = y;
        }
    }
    for (int i = 1; i <= n; i++) printf("%hhi ", a[i]);
    puts("");
    return 0;
}