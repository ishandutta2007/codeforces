#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

int main() {
    #ifdef ONPC
        freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #else
        //freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    s += '1';
    vector <int> all_pos;
    int was = 0;
    int start = 0;
    for (int i = 0; i <= n; i++) {
        if (s[i] == '1') {
            int end = i;
            for (int i = start; i < end; i += b) {
                if (i + b - 1 < end) all_pos.push_back(i + b);
            }
            start = i + 1;
        }
    }
    int cnt = all_pos.size();
    int need;
    for (need = 0; need <= cnt; need++) {
        if (cnt - need < a) {
            break;
        }
    }
    cout << need << '\n';
    for (int i = 0; i < need; i++) {
        cout << all_pos[i] << ' ';
    }
    cout << '\n';
}