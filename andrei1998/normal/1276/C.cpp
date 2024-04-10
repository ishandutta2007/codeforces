#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

int main() {
    //freopen("data.in", "r", stdin);
    ios_base :: sync_with_stdio(false);
    int N;
    cin >> N;
    map <int, int> freq;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        ++freq[val];
    }
    vector <pair <int, int> > rev_map;
    for (const auto& kv : freq) {
        rev_map.emplace_back(kv.second, kv.first);
    }
    sort(rev_map.begin(), rev_map.end());
    /*for (int i = 0; i < rev_map.size(); ++i) {
        cout << rev_map[i].first << " with eleement " << rev_map[i].second << endl;
    }*/
    const int M = rev_map.size();

    int cursor = -1;
    int sum_left = 0;
    pair <int, function <void()> > best;
    for (int smaller_side = 1; smaller_side <= N / smaller_side; ++smaller_side) {
        while (cursor + 1 < M && rev_map[cursor + 1].first <= smaller_side) {
            sum_left += rev_map[++cursor].first;
        }
        const int usable_elements = sum_left + (M - cursor - 1) * smaller_side;
        const int columns = usable_elements / smaller_side;

        if (smaller_side > columns) {
            continue;
        }

        const int area = smaller_side * columns;
        const auto print_callback = [M, area, smaller_side, columns, &rev_map](){
            cout << area << '\n';
            cout << smaller_side << ' ' << columns << '\n';
            int cnt = 0, pos = M - 1, used = 0, i = 0, j = 0;
            vector <vector <int> > mat(smaller_side, vector <int>(columns, -1));
            while (++cnt <= area) {
                while (mat[i][j] != -1) {
                    ++j;
                }
                if (used == min(rev_map[pos].first, smaller_side)) {
                    --pos, used = 0;
                }
                mat[i][j] = rev_map[pos].second;
                ++used;
                i = (i + 1) % smaller_side;
                j = (j + 1) % columns;
            }
            for (int i = 0; i < smaller_side; ++i) {
                for (int j = 0; j < columns; ++j) {
                    cout << mat[i][j] << " \n"[j + 1 == columns];
                }
            }
        };
        if (area > best.first) {
            best = make_pair(area, print_callback);
        }
    }

    best.second();
    return 0;
}