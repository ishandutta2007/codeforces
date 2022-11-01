#pragma gcc optimize("OFast")
#pragma gcc target("sse,sse2,sse3,sse4,tune=native")
//#pragma gcc optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
const int maxn = 1e5, INF = 1e9;
const ll llINF = 1e18;

int cnt[26][26][5000], c[26][5000];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    string s; cin >> s;
    for(int i = 0; i < sz(s); i++)
        for(int j = i + 1; j <= i + sz(s) - 1; j++) {
            cnt[s[i] - 'a'][s[j % sz(s)] - 'a'][j - i]++;
        }

    bitset<5000> di[26];
    vector<vector<int>> cgood(26, vector<int>(5000, 0)), cbad(26, vector<int>(5000, 0));
    for(int ch = 0; ch < 26; ch++)
        for(int d = 1; d < sz(s); d++)
            for(int ch1 = 0; ch1 < 26; ch1++) {
                cgood[ch][d] += (cnt[ch][ch1][d] == 1);
                cbad[ch][d] += (cnt[ch][ch1][d] > 1);
            }

    vector<int> ccc(26, 0);
    for(char ch : s) ccc[ch - 'a']++;

    double P = 0;
    for(int ch = 0; ch < 26; ch++) {
        if(ccc[ch] == 0) continue;
        double pp = (.0 + ccc[ch]) / sz(s);
        double hi = 0;
        for(int d = 1; d < sz(s); d++) hi = max(hi, (.0 + cgood[ch][d]) / (ccc[ch]));
        P += pp * hi;
    }
    cout.precision(9);
    cout << fixed << P;
}