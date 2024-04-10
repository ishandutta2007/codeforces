#include <bits/stdc++.h>

using namespace std;

set <pair <char, char> > Set;

int used[256];
int individ[256];
int in_pair[256];

int main() {
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != t[i]) {
            if (s[i] > t[i]) {
                swap(s[i], t[i]);
            }
            Set.insert(make_pair(s[i], t[i]));
            if (individ[s[i]] || individ[t[i]]) {
                cout << "-1\n";
                return 0;
            }
            ++in_pair[s[i]];
            ++in_pair[t[i]];
        }
        else {
            ++individ[s[i]];
            if (in_pair[s[i]]) {
                cout << "-1\n";
                return 0;
            }
        }
    }

    vector <pair <char, char> > sol;
    for (auto it: Set) {
        ++used[it.first];
        ++used[it.second];
        if (used[it.first] > 1 || used[it.second] > 1) {
            cout << "-1\n";
            return 0;
        }
        sol.push_back(it);
    }

    cout << sol.size() << endl;
    for (auto it: sol) {
        cout << it.first << ' ' << it.second << endl;
    }
    return 0;
}