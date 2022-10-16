#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native") 
#include <immintrin.h>
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

__m256i mask;
__m256i b[N / 8 + 1];
int a[N], n, q;

void change(int l, int r, int x) {
    while (l < r && (l & 7)) {
//        if (a[l] > x) a[l] -= x;
        int *arr = (int*)&b[l / 8];
        if (arr[l - l / 8 * 8] > x) arr[l - l / 8 * 8] -= x;
        b[l / 8] = _mm256_maskload_epi32(arr, mask); 
        l++;
    }
    while (l < r && (r & 7)) {
        r--;
        int *arr = (int*)&b[r / 8];
        if (arr[r - r / 8 * 8] > x) arr[r - r / 8 * 8] -= x;
        b[r / 8] = _mm256_maskload_epi32(arr, mask); 
    }
    l /= 8, r /= 8;
    __m256i *cur = b + l, tmp = _mm256_set_epi32(x, x, x, x, x, x, x, x);
    for (r -= l; r; r--, cur++) {
        *cur = _mm256_sub_epi32(*cur, _mm256_and_si256(_mm256_cmpgt_epi32(*cur, tmp), tmp));
    }
}
int query(int l, int r, int x) {
    int ans = 0;
    while (l < r && (l & 7)) {
        int *arr = (int*)&b[l / 8];
        if (arr[l - l / 8 * 8] == x) ans++;
        l++;
    }
    while (l < r && (r & 7)) {
        r--;
        int *arr = (int*)&b[r / 8];
        if (arr[r - r / 8 * 8] == x) ans++;
    }
    l /= 8, r /= 8;
    __m256i *cur = b + l, tmp = _mm256_set_epi32(x, x, x, x, x, x, x, x), res = _mm256_setzero_si256();
    for (r -= l; r; r--, cur++) {
        res = _mm256_sub_epi32(res, _mm256_cmpeq_epi32(*cur, tmp));
    }
    int *resarr = (int*)&res;
    for (int i = 0; i < 8; i++) ans += resarr[i];
    return ans;
}

int main() {
    mask = _mm256_set_epi32(-1, -1, -1, -1, -1, -1, -1, -1);
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i <= n / 8; i++) {
        b[i] = _mm256_maskload_epi32(a + i * 8, mask);
    }
    while (q--) {
        int opt, l, r, x;
        scanf("%d%d%d%d", &opt, &l, &r, &x);
        l--;
        if (opt == 1) {
            change(l, r, x);
        } else {
            printf("%d\n", query(l, r, x));
        }
    }
    return 0;
}