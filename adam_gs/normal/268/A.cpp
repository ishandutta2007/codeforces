#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int t1[n];
    int t2[n];
    for (int i = 0; i < n; ++i) {
        cin >> t1[i] >> t2[i];
    }
    int r = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i!=j) {
                if (t1[i]==t2[j]) {
                    ++r;
                }
            }
        }
    }
    cout << r;
}