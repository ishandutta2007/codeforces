#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, x = 864197532, N = 587, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n * 2);
    for (int &i : a) cin >> i;
    sort(a.begin(), a.end());
    cout << (a[n - 1] < a[n] ? "YES\n" : "NO\n");
}