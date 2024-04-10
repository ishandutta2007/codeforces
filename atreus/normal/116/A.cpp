#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, cnt = 0, k = 0;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
            cnt = cnt - a[i] + b[i];
            if (k < cnt)
                k = cnt;
    }
    cout << k;
}