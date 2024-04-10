#include <bits/stdc++.h>

using namespace std;

int main (){
    int a[5 + 1][5 + 1];
    int c, r, ans = 0;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cin >> a[i][j];
            if (a[i][j] == 1){
                c = j + 1;
                r = i + 1;
            }
        }
    }
    if (c < 3)
        ans += 3 - c;
    else if (c > 3)
        ans += c - 3;
    if (r < 3)
        ans += 3 - r;
    else if (r > 3)
        ans += r - 3;
    cout << ans;
}