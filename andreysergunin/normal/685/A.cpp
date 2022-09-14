#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <complex> 
#include <ctime>
#include <cstring>
#include <stack>
#include <random>
 
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

const double EPS = 1e-9;

int main() {
    // freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;

    int n1 = n - 1, m1 = m - 1;
    int k = 0;
    for (; n1 > 0; ++k, n1 /= 7);
    for (; m1 > 0; ++k, m1 /= 7);
    
    if (k > 7) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            int a = i;
            int b = j;
            int n1 = n - 1;
            int m1 = m - 1;
            vector<int> x(7);
            bool f = true;
            if (n1 == 0)
                x[0] = 1;
            for (; n1 > 0; n1 /= 7, a /= 7) {
                if (x[a % 7])
                    f = false;
                x[a % 7] = 1;
            }

            if (m1 == 0)  {
                if (x[0] == 1)
                    f = false;
                x[0] = 1;
            }
            for ( ; m1 > 0; m1 /= 7, b /= 7) {
                if (x[b % 7])
                    f = false;
                x[b % 7] = 1;
            }

            if (f)
                ++ans;
        }   

    cout << ans << endl;

    return 0;
}