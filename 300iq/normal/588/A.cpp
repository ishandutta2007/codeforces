#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a, p, ans = 0, price = 1000000;
    for(int i = 0; i < n; i++){
        cin >> a >> p;
        price = min(price, p);
        ans += a * price;
    }
    cout << ans;

}