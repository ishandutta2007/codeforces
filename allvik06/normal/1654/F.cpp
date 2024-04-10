#include <iostream>
#include <vector>
#include <cmath>
#include <array>
#include <algorithm>
#include <random>
#include <chrono>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;
#define ll long long
const int INF = 1e9;
string s;
vector <int> num;

inline bool cmp(pair <int, int> a, pair <int, int> b) {
    return s[a.second] < s[b.second];
}

inline bool cmp1(pair <int, int> f, pair <int, int> s) {
    return make_pair(num[f.first], num[f.second]) < make_pair(num[s.first], num[s.second]);
}

signed main(){
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    vector <pair <int, int>> cur;
    for (int i = 0; i < (1 << n); ++i) cur.emplace_back(0, i);
    cin >> s;
    vector <vector <pair <int, int>>> all(1 << n);
    sort(cur.begin(), cur.end(), cmp);
    num.push_back(0);
    for (int i = 1; i < (1 << n); ++i) {
        if (s[cur[i].second] == s[cur[i - 1].second]) num.push_back(num.back());
        else num.push_back(num.back() + 1);
    }
    for (int i = 1; i <= n; ++i) {
        vector <pair <int, int>> cur1, cur2;
        for (int j = 0; j < (1 << n); ++j) all[j].clear();
        for (int j = 0; j < (1 << n); ++j) {
            all[cur[j].first].emplace_back(cur[j].second, j);
        }
        for (int j = 0; j < (1 << n); ++j) {
            sort(all[j].begin(), all[j].end());
        }
        for (int j = 0; j < (1 << (i - 1)); ++j) {
            for (int k = 0; k < (int)all[j].size(); k += 2) {
                cur1.emplace_back(all[j][k].second, all[j][k + 1].second);
                cur2.emplace_back(all[j][k + 1].second, all[j][k].second);
            }
        }
        sort(cur1.begin(), cur1.end(), cmp1);
        sort(cur2.begin(), cur2.end(), cmp1);
        vector <pair <int, int>> new_cur, tmp;
        int i1 = 0, i2 = 0;
        while (i1 < (int)cur1.size() || i2 < (int)cur2.size()) {
            pair <int, int> now1(INF, INF), now2(INF, INF);
            if (i1 < (int)cur1.size()) now1 = make_pair(num[cur1[i1].first], num[cur1[i1].second]);
            if (i2 < (int)cur2.size()) now2 = make_pair(num[cur2[i2].first], num[cur2[i2].second]);
            if (now1 < now2) {
                new_cur.emplace_back(cur[cur1[i1].first].first, cur[cur1[i1].first].second / 2);
                ++i1;
            } else {
                new_cur.emplace_back(cur[cur2[i2].first].first + (1 << (i - 1)), cur[cur2[i2].first].second / 2);
                ++i2;
            }
            tmp.push_back(min(now1, now2));
        }
        num.clear();
        num = {0};
        for (int j = 1; j < (1 << n); ++j) {
            if (tmp[j] == tmp[j - 1]) num.push_back(num.back());
            else num.push_back(num.back() + 1);
        }
        cur.swap(new_cur);
    }
    vector <char> t((1 << n));
    for (int i = 0; i < (1 << n); ++i) {
        t[i] = s[i ^ cur[0].first];
    }
    for (int i = 0; i < (1 << n); ++i) {
        cout << t[i];
    }
}

/*
 3
bcbaaabb
 */