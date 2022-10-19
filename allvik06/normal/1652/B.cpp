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

using namespace std;
#define int long long
const int INF = 1e9;

signed main(){
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector <int> now(26);
        for (char i : s) ++now[i - 'a'];
        int st;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (now[s[i] - 'a'] > 1) {
                --now[s[i] - 'a'];
            } else {
                st = i;
                break;
            }
        }
        cout << s.substr(st, (int)s.size() - st) << "\n";
    }
}