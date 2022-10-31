#include<bits/stdc++.h>

using namespace std;

int const maxn = 5e5 + 5;
pair < int, int > a[maxn];
int dp[maxn], pref[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    vector < pair < int, int > > one, two, good;
    for (int i = 1; i <= n; ++i) {
        if (d <= a[i].first) {
            if (a[i].first < a[i].second) {
                one.push_back(a[i]);
            } else {
                two.push_back(a[i]);
            }
        }
    }
    sort(one.begin(), one.end(), [](pair < int, int > t, pair < int, int > s) {
        return t.second < s.second;
    });
    sort(two.begin(), two.end());
    int answer = (int)two.size();
    set < int > Q;
    int ptr = 0;
    for (int i = 0; i < (int)one.size(); ++i) {
        int flag = 1;
        /*for (auto key : two) {
            if (one[i].first < key.second && key.first < one[i].second) flag = 0;
        }*/
        while (ptr < (int)two.size() && two[ptr].first < one[i].second) {
            Q.insert(two[ptr++].second);
        }
        if ((int)Q.size() == 0 || one[i].first >= (*Q.rbegin())) good.push_back(one[i]);
    }
    for (int i = 1; i <= (int)good.size(); ++i) {
        pair < int, int > cur = {good[i - 1].first, -1};
        int lef = -1, righ = i - 1;
        while (righ - lef > 1) {
            int mid = (righ + lef) / 2;
            if (good[mid].second <= good[i - 1].first) lef = mid;
            else righ = mid;
        }
        dp[i] = pref[lef + 1] + 1;
        pref[i] = max(pref[i - 1], dp[i]);
    }
    cout << answer + pref[(int)good.size()] << '\n';
    return 0;
}