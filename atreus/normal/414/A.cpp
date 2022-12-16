#include <bits/stdc++.h>

using namespace std;

map <int, bool> mark;

int main() {
    int n, k;
    cin >> n >> k;
    if (n == 1){
        if (k == 0)
            cout << 5 << endl;
        else
            cout << -1 << endl;
        return 0;
    }
    if (n % 2 == 0){
        k -= (n - 2) / 2;
        if (k <= 0){
            cout << -1 << endl;
            return 0;
        }
        cout << k << " " << 2 * k << " ";
        mark[k] = true;
        mark[2 * k] = true;
        int cnt = 0, m = 1;
        for (int i = 1; cnt < n - 2 && i <= n + 100; i++){
            if (mark[i] == false && __gcd(i, m) == 1){
                cout << i << " ";
                m = i;
                cnt ++;
            }
        }
    }
    else {
        k -= (n - 3) / 2;
        if (k <= 0){
            cout << -1 << endl;
            return 0;
        }
        cout << k << " " << 2 * k << " ";
        mark[k] = true;
        mark[2 * k] = true;
        int cnt = 0, m = 1;
        for (int i = 1; cnt < n - 2 && i <= n + 100; i++){
            if (mark[i] == false && __gcd(i, m) == 1){
                cout << i << " ";
                m = i;
                cnt ++;
            }
        }
    }
    return 0;
}