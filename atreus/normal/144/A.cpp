#include <bits/stdc++.h>

using namespace std;

int a[200];

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int maxn = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (a[i] == maxn){
            for (int j = i - 1; j >= 0; j--){
                cnt ++;
                swap (a[j], a[j + 1]);
            }
            break;
        }
    }
    int minn = 1000;
    for (int i = 0; i < n; i++)
        minn = min(minn, a[i]);
    for (int i = n - 1; i >= 1; i--){
        if (a[i] == minn){
            for (int j = i + 1; j < n; j++){
                cnt ++;
                swap (a[j], a[j - 1]);
            }
            break;
        }
    }
    cout << cnt << endl;
}