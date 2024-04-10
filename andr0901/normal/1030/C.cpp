#include <bits/stdc++.h>

using namespace std;

int charToInt(char c) {
    return (int)(c - '0');
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        a[i] = charToInt(c);
        s += a[i];
    }
    bool tmp = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            tmp = 1;
            break;
        }
    }
    if (!tmp) {
        cout << "YES";
        return 0;
    }
    for (int i = 1; i < s; i++) {
        if (s % i) continue;
        //cout << i << "   ";
        bool flag = 1;
        int cur = 0;
        for (int j = 0; j < n; j++) {
            if (cur > i) {
                flag = 0;
                break;
            }
            if (cur == i)
                cur = a[j];
            else
                cur += a[j];
           //cout << cur << " ";
        }
        if (cur > i)
            flag = 0;
        if (flag) {
            cout << "YES";
            return 0;
        }
       // cout << "\n";
    }
    cout << "NO";
    return 0;
}