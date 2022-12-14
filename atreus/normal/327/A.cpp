#include <bits/stdc++.h>

using namespace std;

int a[200];

int main(){
    ios_base::sync_with_stdio(false);
    int n, k = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] == 1)
            k ++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            int x = 0, y = 0;
            for (int l = i; l <= j; l++){
                if (a[l] == 1)
                    x ++;
                if (a[l] == 0)
                    y ++;
            }
            ans = max(ans, k + y - x);
        }
    }
    cout << ans << endl;
}