/*
    I will never forget it.
*/
 
// 392699
 
#include <cstdio>
#include <map>
 
#define int long long
 
using std::map;
 
void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}
 
map<int, bool> a3;
 
struct OI {
    int RP, score;
} FJOI2021;
 
signed main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    int t = fr();
    for (int i = 1; i <= 10000; i++) a3[i * i * i] = 1;
    while (t--) {
        int x = fr();
        for (int i = 1; i * i * i <= x; i++) {
            int tmp = x - i * i * i;
            if (a3.count(tmp)) {
                puts("YES");
                goto cat;
            }
        }
        puts("NO");
    cat:;
    }
    return 0;
}