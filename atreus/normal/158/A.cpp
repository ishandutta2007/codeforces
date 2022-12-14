#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n, k, ans;
    cin >> n >> k;
    ans = k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < k; i++){
        if (a[i] == 0){
            return cout << i, 0;
            break;
        }
    }
    for (int i = k; i < n; i++){
        if (a[k - 1] == a[i])
            ans++;
    }
    cout << ans << endl;
}