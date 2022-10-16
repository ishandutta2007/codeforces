#include <bits/stdc++.h>

using namespace std;

int K, N;
map <string, vector <int> > Map;

string get_rev(string s) {
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    cin >> K >> N;
    for (int i = 1; i <= K; ++i) {
        string str;
        cin >> str;
        int val;
        cin >> val;
        Map[str].push_back(val);
    }

    int best_paly = 0;
    long long int ans = 0;
    for (auto &it: Map) {
        sort(it.second.begin(), it.second.end(), greater <int>());
        const string &str = it.first;
        const vector <int> &w1 = it.second;
        if (str > get_rev(str)) {
            const vector <int> &w2 = Map[get_rev(str)];
            for (int i = 0; i < w1.size() && i < w2.size(); ++i) {
                if (w1[i] + w2[i] > 0) {
                    ans += w1[i] + w2[i];
                }
                else {
                    break;
                }
            }
        }
        else if (str == get_rev(str)) {
            for (int i = 0; i < w1.size(); ++i) {
                if (i + 1 < w1.size() && w1[i + 1] >= 0) {
                    ans += w1[i] + w1[i + 1];
                    ++i;
                }
                else {
                    if (i + 1 < w1.size()) {
                        ans += max(0, w1[i] + w1[i + 1]);
                        best_paly = max(best_paly, w1[i] - max(0, w1[i] + w1[i + 1]));
                    }
                    else {
                        best_paly = max(best_paly, w1[i]);
                    }
                    break;
                }
            }
        }
    }

    cout << ans + best_paly << endl;
    return 0;
}