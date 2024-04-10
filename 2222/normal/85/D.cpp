#include <algorithm>
#include <cstdio>

using namespace std;

int n, m;
int a[100500] __attribute__((aligned(16)));

int main() {
    for (scanf("%d", &m); m --> 0; ) {
        char q[4];
        scanf("%s", q);
        if (q[0] == 's') {
            long long res = 0;
            for (int i = 2; i < n; ) {
                res += a[i]; i += 5;
                res += a[i]; i += 5;
                res += a[i]; i += 5;
                res += a[i]; i += 5;
            }
            printf("%I64d\n", res);
        } else {
            int x[] = {0, 0, 0, 0}, i;
            scanf("%d", x);
            i = lower_bound(a, a + n, x[0]) - a;
            if (q[0] == 'a') {
                for (; i & 3; ++i) 
                    swap(x[0], a[i]);
                asm volatile (
                    "movdqu %[x], %%xmm0 \n\t"
                    :
                    : [x]"m"(x[0])
                );
                n += 4;
                for (; i < n; i += 8) {
                    asm volatile (
                        "movdqa 0(%[p]), %%xmm2 \n\t"
                        "movdqa 16(%[p]), %%xmm3 \n\t"
                        
                        "movdqa %%xmm2, %%xmm4 \n\t"
                        "pslldq $4, %%xmm2 \n\t"
                        "psrldq $12, %%xmm4 \n\t"
                        
                        "por %%xmm0, %%xmm2 \n\t"
                        
                        "movdqa %%xmm3, %%xmm0 \n\t"
                        "pslldq $4, %%xmm3 \n\t"
                        "psrldq $12, %%xmm0 \n\t"
                        
                        "por %%xmm4, %%xmm3 \n\t"
                        
                        "movdqa %%xmm2, 0(%[p]) \n\t"
                        "movdqa %%xmm3, 16(%[p]) \n\t"
                        
                        :
                        : [p]"r"(a + i)
                    );
                }
                n -= 3;
            } else {
                for (; i & 3; ++i)
                    a[i] = a[i + 1];
                for (; i < n; i += 4) {
                    asm volatile (
                        "movdqa %[a], %%xmm0 \n\t"
                        "psrldq $4, %%xmm0 \n\t"
                        "movdqa %%xmm0, %[a] \n\t"
                        :
                        : [a]"m"(a[i])
                    );
                    a[i + 3] = a[i + 4];
                }
                a[--n] = 0;
            }
        }
    }
    return 0;
}