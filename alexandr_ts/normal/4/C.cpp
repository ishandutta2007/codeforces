#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a)

using namespace std;

int main() {
    int n;
    cin >> n;
    map <string, int> m;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (m.count(s)) {
            cout << s << m[s] << endl;
            m[s]++;
        }
        else {
            m[s] = 1;
            cout << "OK" << endl;
        }

    }
}