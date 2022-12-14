#include <bits/stdc++.h>

using namespace std;

int a[1000 + 100];

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
        if (__gcd(a[i], a[0]) != a[0])
            return cout << -1, 0;
    cout << 2 * n << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " " << a[0] << " ";
}