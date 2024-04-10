#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const int MAXN = 10005;

int N;
string s;
int dp[MAXN][2];

void load() {
    cin >> s;
}

string get(int lo, int len) {
    return s.substr(lo, min(len, N - lo));
}

void solve() {
    N = s.size();
    s += ' ';
    vector <string> sol;
    dp[N][0] = dp[N][1] = 1;
    for (int i = N - 1; i >= 5; i--) {
        if (i + 1 < N) {
            if (get(i, 2) != get(i + 2, 2))
                dp[i][0] |= dp[i + 2][0];
            dp[i][0] |= dp[i + 2][1];
        }  
        if (i + 2 < N) {
            dp[i][1] |= dp[i + 3][0];
            if (get(i, 3) != get(i + 3, 3))
                dp[i][1] |= dp[i + 3][1];
        }
        if (dp[i][0]) sol.push_back(get(i, 2));
        if (dp[i][1]) sol.push_back(get(i, 3));
    }
    sort(sol.begin(), sol.end());
    sol.resize(unique(sol.begin(), sol.end()) - sol.begin());
    printf("%d\n", sol.size());
    for (int i = 0; i < sol.size(); i++)
        puts(sol[i].c_str());
}

int main() {
    load();
    solve();
    return 0;
}