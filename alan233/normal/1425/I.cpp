// Author: wlzhouzhuan
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native") 
#include <bits/stdc++.h>
#include <immintrin.h>
#include <nmmintrin.h>
using namespace std;

#define ll long long
#define pb push_back

inline int read() {
    int x = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch)) f |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
    return f ? -x : x;
} 

const int N = 50015;
const int inf = 1e9;

vector<int> adj[N];
int A[N], dep[N], d[N], l[N], r[N], tim;
int n, q;

int a[N], b[N];

void dfs(int u) {
    l[u] = ++tim, a[tim] = A[u], dep[tim] = d[u];
    for (auto v: adj[u]) d[v] = d[u] + 1, dfs(v);
    r[u] = tim;
}

__m256i maska[N / 8 + 5], maskb[N / 8 + 5], maskdep[N / 8 + 5];
 
int main() {
    n = read(), q = read();
    for (int i = 1; i <= n; i++) A[i] = read(), b[i] = -inf;
    for (int i = 2; i <= n; i++) adj[read()].pb(i);
    dfs(1);
    for (int i = 1; i <= n / 8 + 5; i++) {
        maska[i] = _mm256_loadu_si256((__m256i*) (a + 8 * (i - 1) + 1));
        maskb[i] = _mm256_loadu_si256((__m256i*) (b + 8 * (i - 1) + 1));    
        maskdep[i] = _mm256_loadu_si256((__m256i*) (dep + 8 * (i - 1) + 1)); 
    }
    
    for (int i = 1; i <= q; i++) {
        int u = read(), l = ::l[u], r = ::r[u] + 1;
        
//        printf("now l = %d, r = %d\n", l, r);
        ll ans1 = 0; int ans2 = 0;
        
        const __m256i ZERO = _mm256_setzero_si256();
        const __m256i limi = _mm256_set1_epi32(i + 1);
        const __m256i lim = _mm256_set1_epi32(i);
        
        __m256i ANS1 = _mm256_setzero_si256();
        __m256i ANS2 = _mm256_setzero_si256();
        
        while (l < r && l % 8 != 1) {
            int zz[8]; _mm256_storeu_si256((__m256i*) zz, maskb[(l - 1) / 8 + 1]);
            if (zz[(l - 1) % 8] + a[l] <= i)
                zz[(l - 1) % 8] = i, ans1 += dep[l], ans2++;
            maskb[(l - 1) / 8 + 1] = _mm256_loadu_si256((__m256i*) zz);
            l++;
        }
        while (l < r && r % 8 != 1) {
            r--;
            int zz[8]; _mm256_storeu_si256((__m256i*) zz, maskb[(r - 1) / 8 + 1]);
            if (zz[(r - 1) % 8] + a[r] <= i)
                zz[(r - 1) % 8] = i, ans1 += dep[r], ans2++;
            maskb[(r - 1) / 8 + 1] = _mm256_loadu_si256((__m256i*) zz);
        } 
        l = l / 8 + 1, r = r / 8 + 1;
        
        for (; l < r; l++) {
            __m256i status = _mm256_cmpgt_epi32(limi, _mm256_add_epi32(maska[l], maskb[l]));
            _mm256_storeu_si256((__m256i*) &maskb[l], _mm256_blendv_epi8(maskb[l], lim, status));
            ANS1 = _mm256_add_epi32(ANS1, _mm256_blendv_epi8(ZERO, maskdep[l], status));
            ANS2 = _mm256_sub_epi32(ANS2, status);
        }
        int zz1[8]; _mm256_storeu_si256((__m256i*) zz1, ANS1);
        int zz2[8]; _mm256_storeu_si256((__m256i*) zz2, ANS2);
        for (int i = 0; i < 8; i++) ans1 += zz1[i];
        for (int i = 0; i < 8; i++) ans2 += zz2[i];
        printf("%lld %d\n", ans1 - 1ll * ans2 * d[u], ans2);
        /*
        for (int j = l; j < r; j++) {
            if (b[j] + a[j] <= i)
               b[j] = i, ans1 += dep[j], ans2++; 
        }
        printf("%lld %d\n", ans1 - 1ll * ans2 * d[u], ans2);
        */
    }
    return 0;
}