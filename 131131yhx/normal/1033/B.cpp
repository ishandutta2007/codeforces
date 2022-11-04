#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>
#define int long long

using namespace std;

signed main() {
    int T;
    scanf("%lld", &T);
    while(T--) {
        int a, b;
        scanf("%lld%lld", &a, &b);
        if(a != b + 1) puts("NO"); else {
        int c = a + b, flag = 0;
        for(int i = 2; i * i <= c; i++)
            if(c % i == 0) {
                flag = 1;
                break;
            }
            if(flag) puts("NO"); else puts("YES");}
    }
    return 0;
}