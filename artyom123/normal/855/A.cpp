#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main()
{
    int n;
    cin >> n;
    set <string> s;
    for (int i = 0; i < n; i++) {
        string now;
        cin >> now;
        if (s.find(now) != s.end()) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
        s.insert(now);
    }
    return 0;
}