#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    vector < int > a(n);
    vector < pair < int, int > > b(n);
    map < int, int > out;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> x, b[i] = {x, i};
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int j = 0; j < n; ++j) out[b[j].second] = a[n - 1 - j];
    for (auto key : out) cout << key.second << " ";
    return 0;
}