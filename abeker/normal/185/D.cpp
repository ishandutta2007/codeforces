#include <cstdio>
using namespace std;

typedef long long ll;
 
inline int add(int a, int b, int c) {
    a += b;
    if (a >= c) a -= c;
    else if (a < 0) a += c;
    return a;
}

inline int mul(int a, int b, int c) {
    return (ll)a * b % c;
}
       
int pow(int a, ll b, int c) {
    int res = 1;
    for (; b; b /= 2) {
        if (b % 2) res = mul(res, a, c);
        a = mul(a, a, c);
    }
    return res;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int k, p;
        ll l, r;
        scanf("%d%I64d%I64d%d", &k, &l, &r, &p);
        if (p == 2) {
            printf("%d\n", !(k % 2));
            continue;
        }
        int prod = 1;
        if (k % p) {
            int e = pow(2, l, p - 1);
            int t = pow(k, e, p);
            if (t == 1) 
                prod = pow(2, r - l + 1, p);
            else {
                int inv = pow(add(t, -1, p), p - 2, p);
                int num = add(pow(t, add(pow(2, r - l + 1, p - 1), -1, p - 1), p), -1, p);
                prod = add(mul(t, mul(num, inv, p), p), 1, p);
            }
        }
        if (k % 2) 
            prod = mul(prod, pow(2, add(l % (p - 1), -(r % (p - 1)), p - 1), p), p);
        printf("%d\n", prod);
    }
    return 0;
}