#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

vi v[26];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    for (int i = 0; i < (int) s.size(); i++) {
        v[s[i] - 'a'].pb(i);
    }
    long long ans = 0;
    for (int i = 0; i < 26; i++) ans = max(ans, (long long) v[i].size());
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            long long tmpAns = 0;
            for (int k = 0; k < (int) v[i].size(); k++) {
                int temp = upper_bound(all(v[j]), v[i][k]) - v[j].begin();
                tmpAns += v[j].size() - temp;
            }
            ans = max(ans, tmpAns);
        }
    }
    cout << ans;
    return 0;
}