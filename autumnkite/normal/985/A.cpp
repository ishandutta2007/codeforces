#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>
using namespace std;
#define gc getchar
inline void read(int &x){
    register bool f;
    register char ch;
    for (f = false, ch = gc(); !isdigit(ch); ch = gc()) if (ch == '-') f = true;
    for (x = 0; isdigit(ch); ch = gc()) x = ((x + (x << 2)) << 1) + (ch ^ '0');
    if (f) x = -x;
}
const int N = 105;
int n, a[N], s1, s2;
inline int abs(int x){
    return x > 0 ? x : -x;
}
int main(){
    read(n), n >>= 1;
    for (register int i = 1; i <= n; ++i) read(a[i]);
    sort(a + 1, a + 1 + n);
    for (register int i = 1; i <= n; ++i)
        s1 += abs(a[i] - (i << 1) + 1), s2 += abs(a[i] - (i << 1));
    return printf("%d", s1 < s2 ? s1 : s2), 0;
}