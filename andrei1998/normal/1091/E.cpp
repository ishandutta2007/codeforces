#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

const int NMAX = 500000 + 5;

int N;
int v[NMAX];

lint at_most_place_left[NMAX];
lint at_least_place_right[NMAX];

int main() {
    //freopen("data.in", "r", stdin);
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    lint sum_tot = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
        sum_tot += v[i];
    }
    sort(v + 1, v + N + 1, greater <int>());

    int ptr = N + 1;
    lint sum_k = 0;
    lint sum_rgt = 0;
    for (int k = 0; k <= N; ++k) {
        if (k >= 1) {
            sum_k += v[k];
            while (ptr - 1 > k && v[ptr - 1] <= k) {
                sum_rgt += v[--ptr];
            }
            if (ptr <= k) {
                ptr = k + 1;
                sum_rgt = sum_tot - sum_k;
            }
        }


        // At least
        const lint val = sum_k - k * (k - 1LL) - sum_rgt - k * (ptr - k - 1LL);
        if (k < val) {
            at_least_place_right[k] = 2 * N + 2; // INF
        }
        else {
            at_least_place_right[k] = val;
        }

        // At most
        while (ptr - 1 > k && v[ptr - 1] <= k + 1) {
            sum_rgt += v[--ptr];
        }
        at_most_place_left[k] = k * (k + 1LL) + sum_rgt + (k + 1LL) * (ptr - k - 1LL) - sum_k;
        //cout << k << ' ' << at_most_place_left[k] << ' ' << at_least_place_right[k] << endl;
    }

    at_most_place_left[N] = min(at_most_place_left[N], 1LL * N);
    for (int i = N; i >= 1; --i) {
        at_most_place_left[i - 1] = min(at_most_place_left[i - 1], at_most_place_left[i]);
    }
    at_least_place_right[0] = max(0LL, at_least_place_right[0]);
    for (int i = 0; i < N; ++i) {
        at_least_place_right[i + 1] = max(at_least_place_right[i + 1], at_least_place_right[i]);
    }

    vector <int> sol;

    v[0] = N;
    v[N + 1] = 0;
    for (int i = 0; i <= N; ++i) {
        //cout << "la " << i << endl;
        for (int vl = v[i + 1]; vl <= v[i]; ++vl) {
            //cout << "incerc " << vl << endl;
            if (vl >= at_least_place_right[i] && vl <= at_most_place_left[i]) {
                sol.push_back(vl);
                //cout << "pe " << vl << endl;
            }
        }
    }

    vector <int> new_sol;
    for (auto it: sol) {
        if (sum_k + it <= N * (N + 1LL)) {
            if (it % 2 == sum_k % 2) {
                new_sol.push_back(it);
            }
        }
    }

    if (new_sol.empty()) {
        cout << "-1\n";
    }
    else {
        sort(new_sol.begin(), new_sol.end());
        new_sol.resize(unique(new_sol.begin(), new_sol.end()) - new_sol.begin());
        for (int i = 0; i < new_sol.size(); ++i) {
            cout << new_sol[i] << " \n"[i + 1 == new_sol.size()];
        }
    }
    return 0;
}