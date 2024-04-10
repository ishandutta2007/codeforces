#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> l(n), r(n), s(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        if (l[i] > i) {
            cout << "NO";
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> r[i];
        if (r[i] >= n - i) {
            cout << "NO";
            return 0;
        }
    }
    int m = INT_MIN;
    for (int i = 0; i < n; i++) {
        s[i] = l[i] + r[i];
        m = max(m, s[i]);
    }
    for (int i = 0; i < n; i++)
        s[i] =  m + 1 - s[i];
    for (int i = 0; i < n; i++) {
        int left = 0;
        for (int j = 0; j < i; j++)
            if (s[i] < s[j]) left++;
        if (left != l[i]) {
            cout << "NO";
            return 0;
        }
        int right = 0;
        for (int j = i + 1; j < n; j++)
            if (s[i] < s[j]) right++;
        if (right != r[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << s[i] << " ";
    return 0;
}