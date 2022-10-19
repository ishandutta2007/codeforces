#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cassert>
#include <array>

using namespace std;

void solve() {
    string S; cin >> S;
    
    string ord = "ANOT";
    string best_ord = ord;
    int64_t best_inv = -1;
    
    do {
        vector<int> cnt(256, 0);
        int64_t cur_inv = 0;
        for (char &c : S) {
            for (int i = 3; ord[i] != c; --i) {
                cur_inv += cnt[ord[i]];
            }
            ++cnt[c];
        }
        
        if (cur_inv > best_inv) {
            best_inv = cur_inv;
            best_ord = ord;
        }
    } while (next_permutation(ord.begin(), ord.end()));
    
    vector<int> cnt(256, 0);
    for (char &c : S) ++cnt[c];
    string T = "";
    for (char &c : best_ord) T += string(cnt[c], c);
    cout << T << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}