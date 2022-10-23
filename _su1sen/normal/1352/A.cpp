#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t --> 0) {
        int n;
        cin >> n;
        int p = 1;
        vector<int> a;
        while (n) {
            int r = n % 10;
            if (r) {
                a.push_back(r * p);
            }
            n /= 10;
            p *= 10;
        }
        int k = a.size();
        cout << k << '\n';
        for (int i = 0; i < k; ++i) {
            cout << a[i] << " \n"[i == k - 1];
        }
    }
    return 0;
}