#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

int main() {
//SATAN
    string s;
    cin >> s;
    vector <int> cnt(255);
    int ans = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        char c = s[i];
        if (c == 'F' && cnt['M'] > 0) {
            ans = max(cnt['M'], ans + 1);
        } 
        cnt[c]++;
    }
    printf("%d\n", ans);
}