#include <bits/stdc++.h>

using namespace std;

int a[105];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> x;
        for (int j = 0; j < x; ++j){
            int y;
            cin >> y;
            a[y]++;
        }
    }
    for (int i = 0; i < 101; ++i)
        if (a[i] == n)
        cout << i << " ";
    return 0;
}