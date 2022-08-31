#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main() {
    std::ios_base::sync_with_stdio(false);
 
    int n;
    cin >> n;
    int w;
    int h;
    cin >> w >> h;
    vector<pair<pair<int,int>,int>> v(n);
    for (size_t i =0; i < n; ++i) {
        v[i].second = i;
    }
    for (auto& i : v) {
        cin >> i.first.first >> i.first.second;
    }
    sort(v.begin(), v.end());
    vector<int> best(n);
    int maximal = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i].first.first <= w || v[i].first.second <= h)
            best[i] = 0;
        else
            best[i] = 1, maximal = 1;
    }
    vector<int> besti(n, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (v[j].first.first < v[i].first.first && v[j].first.second < v[i].first.second && best[j] != 0) {
                if (best[i] < best[j] + 1) {
                    best[i] = best[j] + 1;
                    maximal = max(maximal, best[i]);
                    besti[i] = j;
                }
            }
        }
    }
    cout << maximal << endl;
    if (maximal) {
        int index = n-1;
        while (best[index] != maximal)
            --index;
        vector<int> result;
        while (maximal) {
            result.push_back(v[index].second + 1);
            --maximal;
            index = besti[index];
        }
        reverse(result.begin(), result.end());
        for (auto i : result) {
            cout << i << ' ';
        }
        cout << endl;
    }
 
    return 0;
}