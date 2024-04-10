#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, x;
    cin >> n;
    map <ll, int> pref;
    ll sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
        pref[sum]++;
        ans = max(ans, pref[sum]);
    }
    cout << n - ans << endl;
}