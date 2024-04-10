#include <bits/stdc++.h>

using namespace std;

int a[100005];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int numb = 0;
    for (int i = 2; i <= n; ++i){
        int imin = 1;
        for (int j = 2; j * j <= i; ++j){
            if (i % j == 0){
                imin = j;
                break;
            }
        }
        if (imin == 1){
            numb++;
            cout << numb << " ";
            a[i] = numb;
        }
        else{
            cout << a[imin] << " ";
            a[i] = a[imin];
        }
    }
    return 0;
}