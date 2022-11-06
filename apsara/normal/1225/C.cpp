#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long LL;
const int P = 1000000007;

const int N = 32;
const int L = 16;
const int R = 16;

map<int, int> mp;
int pt[40];

int n, p;

int main() {
    pt[0] = 1;
    for (int i = 1; i <= N; ++i) pt[i] = pt[i - 1] * 2;
    while (~scanf("%d%d", &n, &p)) {
        int ans = -1;
        for (int i = 1; i <= 30; ++i) {
            int v = n - i * p;
            if (v < i) continue;
            int cnt = 0;
            int x = v;
            while (x) {
                cnt++;
                x -= x & -x;
            }
            if (cnt <= i) {
                ans = i;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*

*/