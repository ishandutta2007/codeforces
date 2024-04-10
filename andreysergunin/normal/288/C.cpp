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
    cout << (long long)n * ((long long)n + 1) << endl;
    vector<int> ans(n + 1);
    int p = 1;
    while (p <= n)
        p *= 2;
    int m = n;
    for (int i = n; i >= 0; i--) {
        while  (p - i - 1 > m) {
            m = i;
            p /= 2;
        }
        ans[i] = p - i - 1;
    }
    for (int i = 0; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}