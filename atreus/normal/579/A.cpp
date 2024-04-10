#include <bits/stdc++.h>

using namespace std;

long long tav[50];

int main(){
    ios_base::sync_with_stdio(false);
    tav[0] = 1;
    for (int i = 1; i < 40; i++)
        tav[i] = 1ll * tav[i - 1] * 2;
    int n, cnt = 0;
    cin >> n;
    for (int i = 30; n > 0 && i >= 0; i--){
        if (n >= tav[i]){
            n -= tav[i];
            cnt ++;
        }
        if (n == 0)
            break;
    }
    cout << cnt << endl;
}