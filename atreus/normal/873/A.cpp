#include <bits/stdc++.h>
#include <string>
#include <map>
#include <math.h>

using namespace std;

int a[200];

int main() {
    int n, k, x;
    cin >> n >> k >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long ans = 0;
    for (int i = 0; i < n - k; i++)
        ans += a[i];
    ans += k * x;
    cout << ans << endl;
}