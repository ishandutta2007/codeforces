#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 100100;

int main() {
    int n;
    int p[MAXN], a[MAXN];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        a[p[i] - 1] = i;
    }
    int k = 1;
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
        if (a[i] < a[i + 1])
            k++;
        else {
            if (k > ans)
                ans = k;
            k = 1;
        }
    if (k > ans)
        ans = k;
    cout << n - ans;
}