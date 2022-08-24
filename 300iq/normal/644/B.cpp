#include <bits/stdc++.h>

using namespace std;

long long e[200000];
vector <long long> up;

int main() {
    ios_base::sync_with_stdio(0);
    long long n, b, t, d, cur_time = 0;
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        cin >> t >> d;
        int i_x = upper_bound(up.begin(), up.end(), t) - up.begin();
        int k = up.size() - i_x - 1;
        if (k < b) {
            e[i] = up.size();
            if (up.size() > 0) {
                up.push_back(max(t, up.back()) + d);
            } else {
                up.push_back(t + d);
            }
        } else {
            e[i] = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (e[i] == -1)
            cout << -1 << " ";
        else
            cout << up[e[i]] << " ";
    }
}