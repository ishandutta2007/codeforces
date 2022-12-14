#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 400;
int a[maxn];

int main() {
    long long sum = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort (a, a + n);
    long long ans = sum;
    for (int i = 0; i < n - 1; i++){
        ans += sum;
        sum -= a[i];
    }
    cout << ans << endl;
    return 0;
}