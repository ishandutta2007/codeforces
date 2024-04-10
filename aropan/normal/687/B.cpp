#include <bits/stdc++.h>

using namespace std;

int main(int /* argc */, const char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    vector<int> f;
    for (int i = 2; i * i <= k; ++i) {
        int q = 1;
        while (k % i == 0) {
            q *= i;
            k /= i;
        }
        if (q > 1) {
            f.push_back(q);
        }
    }
    if (k > 1) {
        f.push_back(k);
    }

    bool ok = true;
    for (auto& x : f) {
        ok = false;
        for (int j = 0; j < n; ++j) {
            if (c[j] % x == 0) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            break;
        }
    }
    cout << (ok? "Yes" : "No") << endl;

    return 0;
}