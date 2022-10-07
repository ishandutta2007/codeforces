#include <cstdio>
#include <algorithm>
using namespace std;
long long n, m, a, b, ans;
int main(){
    scanf("%I64d%I64d%I64d%I64d", &n, &m, &a, &b);
    ans = min((n - n / m * m) * b, ((n / m + 1) * m - n) * a);
    return printf("%I64d", ans), 0;
}