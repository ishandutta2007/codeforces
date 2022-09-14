#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

const int MAXN = 500200;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    int a[MAXN], stable[MAXN];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n - 1; i++) {
        if (a[i - 1] == a[i] || a[i] == a[i + 1])
            stable[i] = 1;
        else
            stable[i] = 0;
    }
    int last[MAXN], next[MAXN];
    last[0] = 0;
    for (int i = 1; i < n - 1; i++) {
        if (stable[i] == 0)
            last[i] = last[i - 1];
        else
            last[i] = i;
    }
    next[n - 1] = n - 1;
    for (int i = n - 2; i > 0; i--) {
        if (stable[i] == 0)
            next[i] = next[i + 1];
        else
            next[i] = i;
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        if (stable[i] == 0) {
            if (i - last[i] > next[i] - i)
                a[i] = a[next[i]];
            else
                a[i] = a[last[i]];
            ans = max(ans, min(i - last[i], next[i] - i));
        }
    }
    cout << ans <<  endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}