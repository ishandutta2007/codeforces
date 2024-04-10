#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <iostream>
#include <ctime>
#define int long long

using namespace std;

int n, s, A[200010];

signed main() {
    scanf("%lld%lld", &n, &s);
    for(int i = 1; i <= n; i++) scanf("%lld", &A[i]);
    sort(A + 1, A + n + 1);
    if(A[n / 2 + 1] == s) {
        puts("0");
        return 0;
    }
    if(A[n / 2 + 1] > s) {
        int ans = 0;
        for(int i = n / 2 + 1; i >= 1; i--)
            if(A[i] > s) ans += A[i] - s; else break;
        printf("%lld\n", ans);
        return 0;
    } else {
        int ans = 0;
        for(int i = n / 2 + 1; i <= n; i++)
            if(A[i] < s) ans += s - A[i]; else break;
        printf("%lld\n", ans);
        return 0;
    }
}