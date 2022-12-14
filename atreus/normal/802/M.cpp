#include <bits/stdc++.h>

using namespace std;

int a[2500];

int main(){
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort (a, a + n);
    long long ans = 0;
    for (int i = 0; i < k; i++)
        ans += a[i];
    cout << ans << endl;
}