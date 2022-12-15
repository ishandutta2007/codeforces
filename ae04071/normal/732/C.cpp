#include <stdio.h>
#include <algorithm>

typedef long long ll;

inline void Max(ll &a, ll &b, ll &c) {
    if(a < b) {
        std::swap(a, b);
    }
    if(a < c)
        std::swap(a, c);
    if(b < c)
        std::swap(b, c);
}

int main()
{
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    Max(a,b,c);

    long long res = 0, temp;
    temp = (a - b - 1);
    if(temp < 0) temp = 0;
    res += temp;

    temp = (a - c - 1);
    if(temp < 0) temp = 0;
    res += temp;

    printf("%lld\n", res);

    return 0;
}