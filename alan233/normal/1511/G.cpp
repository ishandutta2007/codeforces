// Author: wlzhouzhuan
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#include <immintrin.h>
#include <nmmintrin.h>
using namespace std;

const int N = 200005;

__m256i A[N / 8 + 5];
int a[N], n, m, q;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n / 8 + 1; i++) {
        A[i] = _mm256_loadu_si256((__m256i*) (a + 8 * (i - 1) + 1));
    }
    scanf("%d", &q);
    while (q--) {
        int L, R; scanf("%d%d", &L, &R);
        const __m256i tmp = _mm256_set1_epi32(L);
        int l = lower_bound(a + 1, a + n + 1, L) - a;
        int r = upper_bound(a + 1, a + n + 1, R) - a - 1;
        int ANS = 0; 
        __m256i ans = _mm256_setzero_si256();
//        printf("l = %d, r = %d\n", l, r);
        while (l <= r && l % 8 != 1) {
            ANS ^= a[l] - L;
            l++;
        }
        while (l <= r && r % 8 != 0) {
            ANS ^= a[r] - L;
            r--;
        }
        if (l <= r) {
//            printf("now l = %d, r = %d\n", l, r);
            l = l / 8 + 1, r = r / 8;
//            printf("l = %d, r = %d\n", l, r);
            for (; l <= r; l++) {
                ans = _mm256_xor_si256(ans, _mm256_sub_epi32(A[l], tmp));
            }
        }
        int zz[8]; _mm256_storeu_si256((__m256i*) zz, ans);
        for (int i = 0; i < 8; i++) ANS ^= zz[i];
        putchar(ANS ? 'A' : 'B');
    }
    return 0;
}

/*
100 200
191 160 109 123 87 12 178 15 55 171 44 189 121 122 54 141 75 62 168 37 191 29 191 197 132 155 100 154 3 103 169 118 50 19 56 150 165 199 51 59 96 190 108 146 86 127 87 180 109 189 43 126 136 184 46 26 59 82 14 85 179 107 72 167 76 126 28 30 152 33 183 195 167 89 143 123 145 196 171 183 158 21 153 132 119 131 166 100 10 26 10 84 89 168 193 188 155 113 115 34
1
30 177
*/