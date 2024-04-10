#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double
#define mp make_pair
#define ull unsigned long long

const int INF = 1e9 + 1;
const ll INFLL = (ll)1e18 + 1;

string solve(string &s) {
    int n = s.size();
    sort(all(s));
    if (s[0] == s.back()) return s;
    map<char, int> cnt;
    for (auto &c : s) cnt[c]++;
    for (char c = 'a'; c <= 'z'; c++) {
        if (cnt[c] != 1) continue;
        string ans = "";
        ans += c;
        cnt[c] = 0;
        for (char l = 'a'; l <= 'z'; l++) {
            while (cnt[l]) {
                cnt[l]--;
                ans += l;
            }
        }
        return ans;
    }
    for (char c = 'a'; c <= 'z'; c++) {
        if (cnt[c] == 0) continue;
        int x = cnt[c];
        if (n - x < x - 2) break;
        string ans = "";
        ans += c;
        ans += c;
        x -= 2;
        string others = "";
        for (char l = 'a'; l <= 'z'; l++) {
            if (l == c) continue;
            while (cnt[l]) {
                cnt[l]--;
                others += l;
            }
        }
        reverse(all(others));
        while (x) {
            ans += others.back();
            others.pop_back();
            x--;
            ans += c;
        }
        while (others.size()) {
            ans += others.back();
            others.pop_back();
        }
        return ans;
    }
    vector<char> diff;
    for (char c = 'a'; c <= 'z'; c++) {
        if (cnt[c]) diff.pb(c);
    }
    if ((int)diff.size() == 2) {
        string ans = "";
        ans += diff[0];
        ans += diff[1];
        cnt[diff[0]]--;
        cnt[diff[1]]--;
        while (cnt[diff[1]]) {
            ans += diff[1];
            cnt[diff[1]]--;
        }
        while (cnt[diff[0]]) {
            ans += diff[0];
            cnt[diff[0]]--;
        }
        return ans;
    }
    string ans = "";
    ans += diff[0];
    ans += diff[1];
    cnt[diff[0]]--;
    cnt[diff[1]]--;
    while (cnt[diff[0]]) {
        ans += diff[0];
        cnt[diff[0]]--;
    }
    ans += diff[2];
    cnt[diff[2]]--;
    string others = "";
    for (char l = 'a'; l <= 'z'; l++) {
        while (cnt[l]) {
            cnt[l]--;
            others += l;
        }
    }
    return ans + others;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << solve(s) << "\n";
    }
    return 0;
}