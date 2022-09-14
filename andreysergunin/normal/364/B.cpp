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

long long gcd(long long a, long long b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, d;
    cin >> n >> d;
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    vector<int> a(n * 10000 + 1000);
    a[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = (n - 1) * 10000; j >= 0; j--)
            if (a[j] == 1)
                a[j + c[i]] = 1;
    }
    set<int> s;
    for (int i = 1; i <= d; i++)
        if (a[i] == 1)
            s.insert(i);
    int k = d + 1;
    int ans1 = 0, ans2 = 0;
        
    while (!s.empty()) {
        int x = *(--s.end());
        ans1 = x;
        ans2++;
        int y = *(s.lower_bound(-1));
        while (!s.empty() && y <= ans1) {
            s.erase(y);
            y = *(s.lower_bound(-1));
        }
        while (k <= n * 10000 && k <= ans1 + d) {
            if (a[k] == 1)
                s.insert(k);
            k++;
        }
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}