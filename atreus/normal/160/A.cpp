#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, sum = 0, cnt = 0, ans = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sum /= 2;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] < a[j]){
                int m = a[i];
                a[i] = a[j];
                a[j] = m;
            }
    for (int i = 0; i < n; i++){
        ans++;
        cnt += a[i];
        if (cnt > sum){
            break;
        }
    }
    cout << ans;
}