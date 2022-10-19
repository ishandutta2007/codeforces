#include <stdio.h>

const int N = 60;
bool exist[N];
char x[N];

void solve()
{
    char n;
    scanf("%hhd", &n);
    for(int i = 0; i < n; ++i) scanf("%hhd", &x[i]);
    char ans;
    asm(
        ".intel_syntax;"
        
        "sub %%rax, 0x1;"
        
        "mov %%r8, 0x32;"
        "exist_clear:;"
        "movb [%%r8 + %%rdx], 0x0;"
        "sub %%r8, 0x1;"
        "jns exist_clear;"

        "mov %%rbx, 0x0;"
        "mov %%r8, %%rax;"
        "for_1:;"
        "mov %%r9, %%r8;"
        "for_2:;"
        "movb %%bl, [%%r8 + %%rcx];"
        "subb %%bl, [%%r9 + %%rcx];"
        "movb [%%rbx + %%rdx], 0x1;"
        "sub %%r9, 0x1;"
        "jns for_2;"
        "sub %%r8, 0x1;"
        "jns for_1;"

        "mov %%bl, 0x0;"
        "mov %%r8, 0x32;"
        "count:;"
        "addb %%bl, [%%r8 + %%rdx];"
        "sub %%r8, 0x1;"
        "jnz count;"
        
        ".att_syntax;"
        : "=b"(ans)
        : "a"(n), "c"(x), "d"(exist)
    );
    printf("%hhd\n", ans);
}
 
int main()
{
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}