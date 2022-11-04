#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <bitset>

#define PII pair <int, int>
#define x first
#define y second

using namespace std;

typedef long long ll;

int n, C[600010];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &C[i]);
    int ans = 0;
    for(int i = 1; i <= n; i++) if(C[i] != C[n]) {
        ans = max(ans, n - i + 1);
    }
    for(int i = n; i >= 1; i--) if(C[i] != C[1]) {
        ans = max(ans, i);
    }
    printf("%d\n", ans - 1);
    return 0;
}