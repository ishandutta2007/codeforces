#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int wrong_id = -1;
    for (int i = 0; i < m; i++) {
        bool found = 0;
        for (int j = 1; j < n; j++) {
            if (a[j - 1][i] != a[j][i]) {
                swap(a[j - 1], a[0]);
                swap(a[j], a[1]);
                found = 1;
                wrong_id = i;
                break;
            }
        }
        if (found) break;
    }
    
    if (wrong_id == -1 || m == 1) {
        cout << "Yes\n";
        for (int i = 0; i < m; i++) cout << a[0][i] << ' ';
        cout << '\n';
        return 0;
    }
    vector<int> res;
    // check for first copy
    auto solve = [&]() {   
        vector<int> cnt_all_wrong(n, 0);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cnt_all_wrong[i] += a[i][j] != a[0][j];
            }
        }
        for (int col = 0; col < m; col++) {
            if (col == wrong_id) continue;
            bool ok = 1;
            vector<int> cnt_wrong(n, 0);
            int to_correct = -1;
            int almost_correct = -1;
            for (int row = 1; row < n; row++) {
                cnt_wrong[row] = cnt_all_wrong[row] - (a[row][col] != a[0][col]) - (a[row][wrong_id] != a[0][wrong_id]); 
                if (cnt_wrong[row] > 2) {
                    ok = 0;
                    break;
                }
                if (cnt_wrong[row] == 2) to_correct = row;
                if (cnt_wrong[row] == 1) almost_correct = row; 
            }
            if (ok == 0) continue;
            if (to_correct != -1) {
                for (int row = 1; row < n; row++) {
                    cnt_wrong[row] += (a[to_correct][col] != a[row][col]) + (a[to_correct][wrong_id] != a[row][wrong_id]);
                }
                int mx = 0;
                for (int row = 1; row < n; row++) {
                    mx = max(mx, cnt_wrong[row]);
                    cnt_wrong[row] -= (a[to_correct][col] != a[row][col]) + (a[to_correct][wrong_id] != a[row][wrong_id]);
                }
                if (mx <= 2) {
                    res.resize(m);
                    for (int i = 0; i < m; i++) {
                        if (i != col && i != wrong_id) res[i] = a[0][i];
                        else res[i] = a[to_correct][i];
                    }
                    return true;
                }
                continue;
            }
            if (almost_correct != -1) {
                auto sub_solve = [&](int correct_id, int wrong_id) { // fix col to be correct
                    for (int row = 1; row < n; row++) {
                        cnt_wrong[row] += (a[almost_correct][correct_id] != a[row][correct_id]);
                    }
                    int mx = 0;
                    int id_mx = -1;
                    for (int row = 1; row < n; row++) {
                        if (mx < cnt_wrong[row]) {
                            mx = cnt_wrong[row];
                            id_mx = row;
                        }                        
                        cnt_wrong[row] -= (a[almost_correct][correct_id] != a[row][correct_id]);
                    }
                    if (mx <= 1) {
                        res.resize(m);
                        for (int i = 0; i < m; i++) {
                            if (i != correct_id) res[i] = a[0][i];
                            else res[i] = a[almost_correct][i];
                        }
                        return true;
                    } else {
                        int need_to_be_correct = id_mx;
                        for (int row = 1; row < n; row++) {
                            cnt_wrong[row] += (a[almost_correct][correct_id] != a[row][correct_id]) + (a[need_to_be_correct][wrong_id] != a[row][wrong_id]);
                        }
                        int mx = 0;
                        for (int row = 1; row < n; row++) {
                            mx = max(mx, cnt_wrong[row]);
                            cnt_wrong[row] -= (a[almost_correct][correct_id] != a[row][correct_id]) + (a[need_to_be_correct][wrong_id] != a[row][wrong_id]);
                        }
                        if (mx <= 2) {
                            res.resize(m);
                            for (int i = 0; i < m; i++) {
                                if (i == correct_id) res[i] = a[almost_correct][i];
                                else if (i == wrong_id) res[i] = a[need_to_be_correct][i];
                                else res[i] = a[0][i];
                            }
                            return true;
                        }
                    }
                    return false;
                };
                if (sub_solve(col, wrong_id)) return true;
                if (sub_solve(wrong_id, col)) return true;
                continue;
            }
            res.resize(m);
            for (int i = 0; i < m; i++) res[i] = a[0][i];
            return true;
        }
        return false;
    };
    if (solve()) {
        cout << "Yes\n";
        for (int i = 0; i < m; i++) cout << res[i] << ' ';
        cout << '\n';
        return 0;
    }
    swap(a[0], a[1]);
    if (solve()) {
        cout << "Yes\n";
        for (int i = 0; i < m; i++) cout << res[i] << ' ';
        cout << '\n';
        return 0;
    }
    cout << "No\n";

    return 0;
}