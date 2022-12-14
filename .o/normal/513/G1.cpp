#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;

int n, k;
int a[100];
int p[100];

ll res1;
ll cnt1;

void rec1 (int x) {
    if(x > k) {
        int c = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) if(p[i] > p[j]) ++c;
        }
        res1 += c;
        cnt1 ++;
        return;
    }
    for(int i = 0; i < n; i++) for(int j = i; j < n; j++) {
        reverse(p+i, p+j+1);
        rec1(x+1);
        reverse(p+i, p+j+1);
    }
}
void solve1() {
    for(int i = 0; i < n; i++) p[i]=a[i];
    rec1(1);
    printf("%.10lf\n", (lf)res1 / cnt1);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", a+i);
    
    if(n <= 6 && k <= 4) {
        solve1();
    }
    return 0;
}