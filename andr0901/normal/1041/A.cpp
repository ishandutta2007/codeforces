#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> num(n);
    for (int i = 0; i < n; i++) cin >> num[i];
    int a = INT_MAX, b = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (num[i] < a) a = num[i];
        if (num[i] > b) b = num[i];
    }
    cout << b - a - n + 1;
    return 0;
}