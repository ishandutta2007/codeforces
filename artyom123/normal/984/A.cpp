#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main()
{
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cout << a[(n - 1) / 2];
    return 0;
}