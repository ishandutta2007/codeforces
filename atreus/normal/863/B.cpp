#include <bits/stdc++.h>

using namespace std;

int a[120], b[120], c[120];

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    n *= 2;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    sort (c, c + n);
    int ans = 1000000000;
    for (int k = 0; k < n - 1; k++){
        for (int l = k + 1; l < n; l++){
            int total = 0;
            for (int j = 0; j < n; j++){
                a[j] = c[j];
            }
            a[k] = 0;
            a[l] = 0;
            for (int i = n - 1; i >= 1; i -= 2){
                if (a[i] != 0){
                    for (int j = i - 1; j >= 0; j--){
                        if (a[j] != 0){
                            total += a[i] - a[j];
                            i = j + 1;
                            break;
                        }
                    }
                }
                else{
                    i ++;
                    continue;
                }
            }
            ans = min(total, ans);
        }
    }
    cout << ans << endl;
}