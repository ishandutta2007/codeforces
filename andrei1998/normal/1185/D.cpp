#include <bits/stdc++.h>

using namespace std;

const int NMAX = 200000 + 5;

int N;
pair <int, int> v[NMAX];

bool is_progr(const vector <int>& v) {
    const int r = v[1] - v[0];
    for (int i = 0; i + 1 < v.size(); ++i) {
        if (v[i + 1] - v[i] != r) {
            return false;
        }
    }
    return true;
}

void do_try(const int r) {
    vector <int> where;
    for (int i = 1; i + 1 <= N; ++i) {
        if (v[i + 1].first - v[i].first != r) {
            where.push_back(i);
            where.push_back(i + 1);
            break;
        }
    }
    if (where.empty()) {
        cout << v[1].second << endl;
        exit(0);
    }
    for (auto i: where) {
        vector <int> v2;
        for (int j = 1; j <= N; ++j) {
            if (j != i) {
                v2.push_back(v[j].first);
            }
        }
        if (is_progr(v2)) {
            cout << v[i].second << endl;
            exit(0);
        }
    }
}

int main() {
    cin >> N;
    if (N <= 3) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1; i <= N; ++i) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v + 1, v + N + 1);
    do_try(v[2].first - v[1].first);
    do_try(v[N].first - v[N - 1].first);
    cout << "-1" << endl;
    return 0;
}