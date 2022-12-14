#include <bits/stdc++.h>

using namespace std;

int a[100000 + 1000];

int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    long long k = 0, t = 1, ans = 0;
    while (k < m){
        if (t > a[k])
            ans += a[k] + n - t;
        if (t < a[k])
            ans += a[k] - t;
        t = a[k];
        k ++;
    }
    cout << ans << endl;
}