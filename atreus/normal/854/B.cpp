#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    if (n == k)
        return cout << 0 << " " << 0, 0;
    if (k == 0)
        return cout << 0 << " " << 0, 0;
    cout << 1 << " ";
    int l = n / 3;
    if (n % 3 != 0)
        l ++;
    int m = n - l;
    if (k >= l)
        return cout << n - k, 0;
    if (k < l)
        return cout << 2 * k, 0;
}