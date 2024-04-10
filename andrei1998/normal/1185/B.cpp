#include <bits/stdc++.h>

using namespace std;

vector <pair <char, int> > factor(const string& str) {
    vector <pair <char, int> > ans;
    for (int i = 0; i < str.size(); ) {
        int j = i;
        while (j + 1 < str.size() && str[j + 1] == str[i]) {
            ++j;
        }
        ans.push_back(make_pair(str[i], j - i + 1));
        i = j + 1;
    }
    return ans;
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        string a, b;
        cin >> a >> b;
        auto f_a = factor(a);
        auto f_b = factor(b);
        if (f_a.size() != f_b.size()) {
            cout << "NO\n";
            continue;
        }
        bool bad = false;
        for (int i = 0; i < f_a.size(); ++i) {
            if (f_a[i].first != f_b[i].first) {
                bad = true;
            }
            if (f_a[i].second > f_b[i].second) {
                bad = true;
            }
        }
        if (bad) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}