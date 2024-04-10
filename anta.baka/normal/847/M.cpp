#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int d = a[1] - a[0];
    bool ar = true;
    for(int i = 1; i < n; i++)
        ar &= (a[i] == a[i - 1] + d);
    cout << a[n - 1] + ar * d;
}