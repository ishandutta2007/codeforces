#include <bits/stdc++.h>

using namespace std;

int a[200000];

int main() {
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int lo = sum / n;
    int hi = sum / n + (0 < sum % n);
    int above = 0, below = 0;
    for(int i = 0; i < n; i++)
        if(a[i] > hi)
            above += a[i] - hi;
        else if(a[i] < lo)
            below += lo - a[i];
    cout << max(above, below);
}