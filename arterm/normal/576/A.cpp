#include <bits/stdc++.h>

using namespace std;

const int M = 1010;

int n;
vector<int> ans, a[M];

bool eq(const vector<int> &a, const vector<int> &b) {
    if (a.size() != b.size())
        return false;
    for (int i = 0; i < (int) a.size(); ++i)
        if (a[i] != b[i])
            return false;
    return true;
}

int main() {
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        bool need = false;
        for (int j = 1; j < i; ++j)
            if (eq(a[i], a[j])) {
                need = true;
                break;
            }
        if (need) {
            ans.push_back(i);
            for (int k = i; k <= n; k += i)
                a[k].push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (int x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}