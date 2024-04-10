#include <cstdio>
#include <cctype>
using namespace std;
namespace fast_IO{
    inline char read(){
        static const int IN_LEN = 1000000;
        static char buf[IN_LEN], *s, *t;
        if (s == t){
            t = (s = buf) + fread(buf, 1, IN_LEN, stdin);
            if (s == t) return -1;
        }
        return *s++;
    }
    template<class T>
    inline void read(T &x){
        static bool iosig;
        static char c;
        for (iosig = false, c = read(); !isdigit(c); c = read()){
            if (c == '-') iosig = true;
            if (c == -1) return;
        }
        for (x = 0; isdigit(c); c = read()) x = ((x + (x << 2)) << 1) + (c ^ '0');
        if (iosig) x = -x;
    }
    const int OUT_LEN = 10000000;
    char obuf[OUT_LEN], *ooh = obuf;
    inline void print(char c){
        if (ooh == obuf + OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh = obuf;
        *ooh++ = c;
    }
    template<class T>
    inline void print(T x){
        static int buf[30], cnt;
        if (x == 0) print('0');
        else{
            if (x < 0) print('-'), x = -x;
            for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 + 48;
            while (cnt) print((char)buf[cnt--]);
        }
    }
    inline void flush(){
        fwrite(obuf, 1, ooh - obuf, stdout);
    }
}
using namespace fast_IO;
inline long long abs(long long a){return a > 0 ? a : -a;}
int T, n;
long long x0, y0, x1, y1, x, y;
char a[1000005];
inline long long dist(long long x0, long long y0, long long x1, long long y1){
    return abs(x0 - x1) + abs(y0 - y1);
}
inline long long work(){
    read(n), read(x0), read(y0), read(x1), read(y1);
    for (register int i = 1; i <= n; ++i) while (!isalpha(a[i] = read())) ;
    if (x0 == x1 && y0 == y1) return 0;
    for (register int i = 1; i <= n; ++i){
        if (a[i] == 'E') x = x0 + 1, y = y0;
        if (a[i] == 'S') x = x0, y = y0 - 1;
        if (a[i] == 'W') x = x0 - 1, y = y0;
        if (a[i] == 'N') x = x0, y = y0 + 1;
        if (dist(x, y, x1, y1) < dist(x0, y0, x1, y1)) x0 = x, y0 = y;
        if (x0 == x1 && y0 == y1) return i;
    }
    return -1;
}
int main(){
    T = 1;
    while (T--) print(work()), print('\n');
    return flush(), 0;
}