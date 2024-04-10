#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1000 + 5;

int main() {
    vector <int> v;

    int N;
    int K;

    cin >> N >> K;
    for (int i = 1; i <= N; ++ i) {
        int val;
        cin >> val;

        if (val > K)
            v.push_back(val);
    }

    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < v.size(); ++ i) {
        int it = v[i];
        if (2 * K < it) {
            K *= 2;
            ++ ans;
            -- i;
        }
        else
            K = max(it, K);
    }

    cout << ans << endl;
    return 0;
}