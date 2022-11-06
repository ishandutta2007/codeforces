#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cout << fixed << setprecision(14);
    cerr << fixed << setprecision(14);

    int n;
    cin >> n;
    vector<long double> x(n), xp(n);
    priority_queue<pair<long double, int>> pq;

    auto eval = [&](const int i) {
        return xp[i] * (1 - x[i]) / (1 - xp[i]);
    };

    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        x[i] = (100 - x[i]) / 100;
        xp[i] = x[i];
        pq.push({eval(i), i});
    }


    long double ans = n;

    for (int rep = 0;; ++rep) {

        long double prod = 1;
        for (int i = 0; i < n; ++i)
            prod *= 1 - xp[i];


        if (prod == 1) {
            cerr << "done at " << rep << endl;
            break;
        }

        ans += 1 - prod;

        const int i = pq.top().second;
        pq.pop();
        xp[i] *= x[i];

        pq.push({eval(i), i});
    }


    cout << ans;
    return 0;
}