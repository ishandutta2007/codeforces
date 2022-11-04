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

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for(int i = 1; ; i *= 2) {
        ans++;
        if(n <= i) {
            printf("%d\n", ans);
            return 0;
        }
        n -= i;
    }
    return 0;
}