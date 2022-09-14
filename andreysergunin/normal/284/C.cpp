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

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    vector<long long> p(n + 1);
    long long m = 1;
    long long s = 0;
    for (int i = 0;  i < n; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            long long a, x;
            cin >> a >> x;
            s += a * x;
            p[a - 1] += x;
        }
        if (t == 2) {
            int k;
            cin >> k;
            a[m] = k;
            s += k;
            m++;
        }
        if (t == 3) {
            m--;
            s -= p[m];
            s -= a[m];
            a[m] = 0;
            p[m - 1] += p[m];
            p[m] = 0;
        }
        printf("%lf\n", (double)s / m);
    }
    
            
}