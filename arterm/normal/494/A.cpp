#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int a = 0;
    for (auto ch : s)
        if (ch == '(')
            ++a;

    int last = -1;
    for (int i = 0; i < n; ++i)
        if (s[i] == '#')
            last = i;
    int b = n - a;

    if (b > a) {
        cout << "-1\n";
        cerr << "b > a\n";
        return 0;
    }

    int sum = 0;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            ++sum;
        }
        if (s[i] == ')') {
            --sum;
        }
        if (s[i] == '#') {
            if (i != last)
                ans.push_back(1);
            else
                ans.push_back(a - b + 1);
            sum -= ans.back();
        }
        if (sum < 0) {
            cout << "-1\n";
            cerr << "sum < 0\n";
            return 0;
        }
    }

    if (sum != 0) {
        cout << "-1\n";
        return 0;
    }

    for (auto x : ans)
        cout << x << "\n";
    
    return 0;
}