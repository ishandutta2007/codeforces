#include <bits/stdc++.h>
using namespace std;

const int maxn = 200100;
vector< pair<int, int> > d[2];
vector<int> S[2];
int n, v;
int main() {
    cin >> n >> v;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int t, s;
        cin >> t >> s;
        sum += s;
        d[t-1].push_back(make_pair(s, i+1));
    }
   
    for(int i = 0; i < 2; i++) {
        sort(d[i].begin(), d[i].end());
        reverse(d[i].begin(), d[i].end());
        S[i].push_back(0);
        for(auto x: d[i]) {
            S[i].push_back(S[i].back() + x.first);
        }
    }
    int ans = 0;
    int I = 0;
    for(int i = 0; i * 2 <= v && i <= d[1].size(); i++) {
        int cur = S[1][i];
        if(v - 2 * i >= d[0].size()) {
            cur += S[0].back();
        } else {
            cur += S[0][v-2 * i];
        }
        if(cur > ans) {
            ans = cur;
            I = i;
        }
    }
    cout << ans << "\n";
    for(int i = 0; i < I; i++) {
        cout << d[1][i].second << " ";
    }
    for(int i = 0; i < v - 2 * I && i < d[0].size(); i++) {
        cout << d[0][i].second << " ";
    }

    return 0;
}