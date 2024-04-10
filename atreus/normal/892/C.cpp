#include <bits/stdc++.h>

using namespace std;

int a[2020], dp[2020];

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1 && a[0] == 1){
        cout << 0 << endl;
        return 0;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (a[i] == 1){
            cnt ++;
        }
    }
    if (cnt > 0){
        cout << n - cnt << endl;
        return 0;
    }
    for (int i = 0; i < n - 1; i++){
        int qp = a[i];
        for (int j = i + 1; j < n; j++){
            qp = __gcd(qp, a[j]);
            if (qp == 1){
                dp[i] = j;
                break;
            }
        }
    }
    bool impossible = true;
    int k = 1000000000;
    for (int i = 0; i < n - 1; i++){
        if (dp[i] != 0){
            impossible = false;
            k = min(k, dp[i] - i);
        }
    }
    if (impossible)
        return cout << -1 << endl, 0;
    else{
        cout << n + k - 1 << endl;
    }
}