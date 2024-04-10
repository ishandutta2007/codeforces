#include <bits/stdc++.h>
using namespace std;

vector<char> keys(map<char, vector<int>> m) {
    vector<char> k;
    for (auto &el : m) {
        k.push_back(el.first);
    }
    return k;
}

int main() {
    int n;
    cin >> n;
    string sl, sr;
    cin >> sl >> sr;
    map<char, vector<int>> posl, posr;
    for (int i = 0; i < n; i++) {
        posl[sl[i]].push_back(i);
        posr[sr[i]].push_back(i);
    }
    vector<pair<int, int>> ans;
    for (char c : keys(posl)) {
        if (c != '?') {
            while (!posl[c].empty() && !posr[c].empty()) {
                ans.push_back({posl[c].back(), posr[c].back()});
                posl[c].pop_back();
                posr[c].pop_back();
            }
        }
    }
    for (char c : keys(posl)) {
        if (c != '?') {
            char c2 = '?';
            while (!posl[c].empty() && !posr[c2].empty()) {
                ans.push_back({posl[c].back(), posr[c2].back()});
                posl[c].pop_back();
                posr[c2].pop_back();
            }
        }
    }
    for (char c : keys(posr)) {
        if (c != '?') {
            char c2 = '?';
            while (!posl[c2].empty() && !posr[c].empty()) {
                ans.push_back({posl[c2].back(), posr[c].back()});
                posl[c2].pop_back();
                posr[c].pop_back();
            }
        }
    }
    char c = '?';
    while (!posl[c].empty() && !posr[c].empty()) {
        ans.push_back({posl[c].back(), posr[c].back()});
        posl[c].pop_back();
        posr[c].pop_back();
    }
    cout << ans.size() << endl;
    for (auto pp : ans) {
        cout << pp.first + 1 << " " << pp.second + 1 << endl;
    }
}