#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>

using namespace std;

const int INF = 1e18;

long long C(long long n, long long k) {
    long long ans = 1;
    k = min(k, n - k);
    for (int i = 0; i < k; i++) {
        if (ans > 1e18 / (n - i) * (i + 1))
            return INF;
        else
            ans = (ans * (n - i) / (i + 1));
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        long long n, m;
        cin >> n >> m;
        long long l = -1, r = n;
        while (r - l > 1) {
            long long x = (l + r) / 2;
            long long v = x * m;
            long long ans = 0;
            
            for (int i = 0; i <= x; i++) {
                if (v < i)
                    break;
                long long y = min((i == 0 ? 1 : v / i), C(x, i));
                ans += y;
                if (ans >= n || v <= 0)
                    break;
                v -= y * i;
            }
            if (ans >= n)
                r = x;
            else
                l = x;
        }
        cout << r << endl;
    }
}