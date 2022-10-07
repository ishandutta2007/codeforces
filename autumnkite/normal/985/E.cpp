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
const int N = 500005;
int n, k, d, a[N], b[N], s[N];
int main(){
    read(n), read(k), read(d);
    for (register int i = 1; i <= n; ++i) read(a[i]);
    sort(a + 1, a + 1 + n);
    b[0] = 1, s[0] = 1;
    for (register int i = 1, l = 0; i <= n; ++i){
        while (a[l + 1] < a[i] - d) ++l;
        if (l <= i - k && s[i - k] - s[l - 1]) b[i] = 1;
        s[i] = s[i - 1] + b[i];
    }
    return printf(b[n] ? "YES" : "NO"), 0;
}