#include <bits/stdc++.h>

using namespace std;


#define int long long
int a[200005];
int inf = 1e9 + 2;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    a[0] = inf;
    int n, k, sum = 0;
    cin >> n >> k;
    if (k == 1){
        cout << "YES" << '\n';
        cout << n << '\n';
        return 0;
    }
    for (int i = 1; i <= k; ++i) a[i] = i, sum += i;
    int pos = k;
    a[k + 1] = inf;
    bool flag = false;
    while (sum < n){
        if (pos == 0) pos = k;
        if (pos == 1){
            flag = true;
            break;
        }
        else{
            int x = a[pos];
            int delta = min({2 * a[pos - 1] - x, a[pos + 1] - x - 1, n - sum});
            a[pos] += delta;
            sum += delta;
            pos--;
        }
    }
    if (sum == n){
        cout << "YES" << '\n';
        for (int i = 1; i <= k; ++i) cout << a[i] << " ";
        return 0;
    }
    if (flag){
        sum = 0;
        pos = k;
        for (int i = 1; i <= k; ++i) a[i] = i + 1, sum += a[i];
        while (sum < n){
            if (pos == 0) pos = k;
            int x = a[pos];
            int delta = min({2 * a[pos - 1] - x, a[pos + 1] - x - 1, n - sum});
            a[pos] += delta;
            sum += delta;
            pos--;
        }
    }
    if (sum == n){
        cout << "YES" << '\n';
        for (int i = 1; i <= k; ++i) cout << a[i] << " ";
        return 0;
    }
    cout << "NO" << '\n';
    return 0;
}