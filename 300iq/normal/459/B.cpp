#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector <long long> a(n);
    long long maxi = INT_MIN;
    long long mini = INT_MAX;
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
        maxi = max(maxi, a[i]);
        mini = min(mini, a[i]);
    }
    long long mx = 0, mix = 0;
    for (long long i = 0; i < n; i++) {
        mx += (a[i] == maxi);
        mix += (a[i] == mini);
    }
    cout << maxi - mini << " ";
    if (maxi == mini) cout << n * (n - 1) / 2 << endl;
    else cout << mx * mix << endl;
    
}