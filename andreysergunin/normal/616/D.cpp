#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

const int MAXN = 1e6 + 10;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n), prev(n), next(n);
    int c[MAXN];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    for (int i = 0; i < MAXN; i++)
        c[i] = -1;
    for (int i = 0; i < n; i++) {
        prev[i] = c[arr[i]];
        c[arr[i]] = i;
    }
    for (int i = 0; i < MAXN; i++)
        c[i] = n;
    for (int i = n - 1; i >= 0; i--) {
        next[i] = c[arr[i]];
        c[arr[i]] = i;
    }
    
    int ans = 0, ansl = 0, ansr = 0;
    int t = 0;
    for (int l = 0, r = 0; l < n; l++) {
        while (r < n && ((t < k) || (prev[r] >= l))) {
            if (prev[r] < l)
                t++;
            r++;
        }
        if (ans < r - l) {
            ans = r - l;
            ansl = l;
            ansr = r;
        }
        if (next[l] >= r)
            t--;
    }
    
    cout << ansl + 1 << " " << ansr;
    
    return 0;
}